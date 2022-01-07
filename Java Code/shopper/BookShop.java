package shopper;

//Ans-3 Bookshop class derived from the Shop class
public class BookShop extends Shop {
	private String[] Author_List; // adding extra data member Author_list specially for the BookShop Class

	// Overloading checkItem method to check if a particular book by a particular
	// author is available in the bookshop.
	public void checkItem(String Book, String Author) {
		boolean fnd = false;
		int i;
		for (i = 0; i < Author_List.length; i++) {
			if (getItem_list()[i].equalsIgnoreCase(Book) && Author_List[i].equalsIgnoreCase(Author)) {

				fnd = true;
				break;
			}
		}
		if (!fnd)
			throw new NoItemException(Book + " by " + Author);
	}

	// overriding listItem() method of the super class Shop
	public void listItem() {
		System.out.println("List of Available Books and their Prices");
		System.out.printf("%5s %-50s %-40s %8s %5s\n", "SNo.", "Book", "Author", "Price", "Qty.");
		for (int i=0,j = 0; i < getItem_list().length; i++) {
			if (getItem_stocks()[i] > 0) {
				
				System.out.printf("%4d. %-50s %-40s %8.2f %3d\n", ++j, getItem_list()[i], Author_List[i],
						getItem_costs()[i], getItem_stocks()[i]);
			}
		}
	}

	// Overloading buyItem method to buy books according to the book name and author
	// name
	public double buyItem(String itm, String author, int qty) {
		checkItem(itm, author);
		for (int i = 0; i < getItem_list().length; i++) {
			if (getItem_list()[i].equalsIgnoreCase(itm) && Author_List[i].equalsIgnoreCase(author))
				if (getItem_stocks()[i] >= qty) {
					getItem_stocks()[i] -= qty;
					return (qty * getItem_costs()[i]);
				} else
					throw new NoStockException(getItem_list()[i] + " by " + Author_List[i], getItem_stocks()[i]);
		}
		return (0);
	}

//Overloading the getPrice method to get the price of the particular book by a particular author
	public double getPrice(String itm, String author) {
		double c = 0.0;
		checkItem(itm, author);
		for (int i = 0; i < getItem_list().length; i++)
			if (getItem_list()[i].equalsIgnoreCase(itm) && Author_List[i].equalsIgnoreCase(author))
				c = getItem_costs()[i];
		return (c);
	}

//Overloading the addItem method to the add the stock of the particular book by a particular author
	public void addItem(String book, String author, int qty) {
		checkItem(book, author);
		for (int i = 0; i < Author_List.length; i++) {
			if (getItem_list()[i].equalsIgnoreCase(book) && Author_List[i].equalsIgnoreCase(author)) {
				getItem_stocks()[i] += qty;
			}
		}
	}

//	Overloading the setPrice method to the set the price of the particular book by a particular author
	public void setPrice(String book, String author, double price) {
		checkItem(book, author);
		for (int i = 0; i < Author_List.length; i++) {
			if (getItem_list()[i].equalsIgnoreCase(book) && Author_List[i].equalsIgnoreCase(author)) {
				getItem_costs()[i] = price;
			}
		}

	}

//default Constructor to  initialize the data members with the default values
	public BookShop() {
		setItem_list(new String[] { "Java", "C++", "Data Structures", "OOPS", "Networking" });
		setItem_costs(new double[] { 300.0, 360.0, 240.0, 400.0, 200.0 });
		setItem_stocks(new int[] { 25, 10, 20, 10, 20 });
		Author_List = new String[] { "Herbert Schildt", "Yashwant Kanetkar", "Narshimha Karamuchi", "Timothy Budd",
				"James F Kurose" };
	}

//Parametrized Constructor ,values are given by the user
	public BookShop(String[] Book_list, String[] Author, double[] prices, int[] stocks) {
		super(Book_list, prices, stocks);
		System.arraycopy(Author, 0, Author_List, 0, Author_List.length);

	}

}