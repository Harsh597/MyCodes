package shopper;

public class Shop {
	private String[] item_list; // item list
	private double[] item_costs; // Cost of each item
	private int[] item_stocks; // Quantities available

	public String[] getItem_list() {
		return item_list;
	}

	public void setItem_list(String[] item_list) {
		this.item_list = item_list;
	}

	public double[] getItem_costs() {
		return item_costs;
	}

	public void setItem_costs(double[] item_costs) {
		this.item_costs = item_costs;
	}

	public int[] getItem_stocks() {
		return item_stocks;
	}

	public void setItem_stocks(int[] item_stocks) {
		this.item_stocks = item_stocks;
	}

	public Shop() {

	}

	public Shop(String[] itemlist, double[] prices, int[] stocks) throws NoProperFormatException {
		// Check if lists match; otherwise throw exception
		if ((itemlist.length != prices.length) || (itemlist.length != stocks.length)
				|| (prices.length != stocks.length))
			throw new NoProperFormatException();

		item_list = new String[itemlist.length];
		item_costs = new double[prices.length];
		item_stocks = new int[stocks.length];

		for (int i = 0; i < itemlist.length; i++) {
			item_list[i] = itemlist[i];
			item_costs[i] = prices[i];
			item_stocks[i] = stocks[i];
		}
	}

	public void listItem() {
		System.out.println("List of Available Items and their Prices");
		System.out.printf("%5s %-30s %8s %5s\n", "SNo.", "Item", "Price", "Qty.");
		for (int i = 0; i < item_list.length; i++) {
			if (item_stocks[i] > 0) {
				System.out.printf("%4d. %-30s %8.2f %3d\n", i + 1, item_list[i], item_costs[i], item_stocks[i]);
			}
		}
	}

	public double buyItem(String itm, int qty)  {
			checkItem(itm);
			for (int i = 0; i < item_list.length; i++) {
				if (item_list[i].equals(itm))
					if (item_stocks[i] >= qty) {
						item_stocks[i] -= qty;
						return (qty * item_costs[i]);
					} else
						throw new NoStockException(item_list[i], item_stocks[i]);
			}
		return (0);
	}

	public double getPrice(String itm) {
		double c = 0.0;
			checkItem(itm);
			for (int i = 0; i < item_list.length; i++)
				if (item_list[i].equals(itm))
					c = item_costs[i];
		return (c);
	}

	private void checkItem(String item)  {
		boolean fnd = false;
		for (int i = 0; i < item_list.length; i++) {
			if (item_list[i].equals(item)) {
				fnd = true;
				break;
			}
		}
		if (!fnd)
			throw new NoItemException(item);

	}

	public void setPrice(String item, double price) {
			checkItem(item);
			int item_i = search_item(item_list, item);
			item_costs[item_i] = price;

	}

	public void addItem(String item, int qty) {
			checkItem(item);
			int item_i = search_item(item_list, item);
			item_stocks[item_i] += qty;
	}

	private int search_item(String[] item_list, String item) {
		for (int i = 0; i < item_list.length; i++) {
			if (item_list[i].equals(item)) {
				return i;
			}
		}
		return -1;
	}
	
class NoProperFormatException extends ArithmeticException {
	private String explanation = "All the lists must be of the same size!";

	public String toString() {
		return ("NoProperFormatException: " + explanation);
	}
}

class NoStockException extends ArithmeticException {
	private String explanation;

	public NoStockException() {
		explanation = new String("Insufficient Stocks!");
	}

	public NoStockException(int qty) {
		explanation = new String("Only " + qty + " Quantities Available");
	}

	public NoStockException(String itm, int qty) {
		explanation = new String(itm + "-- Only " + qty + " Quantities Available");
	}

	public String toString() {
		return ("NoStockException: " + explanation);
	}
}

class NoItemException extends ArithmeticException {
	private String explanation;

	public NoItemException() {
		explanation = new String("Specified Item Not Found!");
	}

	public NoItemException(String it) {
		explanation = new String(it + "-- Not in Items List");
	}

	public String toString() {
		return ("NoItemException: " + explanation);
	}
}

}