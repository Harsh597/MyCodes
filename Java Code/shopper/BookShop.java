package shopper;

public class BookShop extends Shop {
	private String[] Author_List; // Author list

	private void checkItem(String item) {
		boolean fnd = false;
		for (int i = 0; i < Author_List.length; i++) {
			if (Author_List[i].equals(item)) {
				fnd = true;
				break;
			}
		}
		if (!fnd)
			throw new NoItemException(item);

	}

	public void listItem() {
		System.out.println("List of Available Items and their Prices");
		System.out.printf("%5s %-30s %-40s %8s %5s\n", "SNo.", "Book", "Author", "Price", "Qty.");
		for (int i = 0; i < getItem_list().length; i++) {
			checkItem(Author_List[i]);
			System.out.printf("%4d. %-30s %-40s %8.2f %3d\n", i + 1, getItem_list()[i], Author_List[i],
					getItem_costs()[i], getItem_stocks()[i]);

		}
	}

	public BookShop() {
		setItem_list(new String[] { "Java", "C++", "Data Structure", "Operating System", "Networking" });
		setItem_costs(new double[] { 300.0, 360.0, 240.0, 400.0, 200.0 });
		setItem_stocks(new int[] { 25, 10, 20, 10, 20 });
		Author_List = new String[] { "Herbert Schildt", "Yashwant Kanetkar","Narshimha Karamuchi", "Avi Silberschatz and Peter Galvin",
				"James F Kurose" };
	}

	public BookShop(String[] Book_list, String[] Author, double[] prices, int[] stocks) {
		super(Book_list,prices,stocks);
		System.arraycopy(Author,0,Author_List,0,Author_List.length);
		
	}
	


}