package shopper;

public class FruitShop extends Shop {
<<<<<<< HEAD
	// Ans-2.(ii)
	// Only constructors are here in the class all the other metods and members are
	// derived from the super class Shop
	// No overriding of methods require here
=======

>>>>>>> cb0f8d61ae774798f89a9ed16a4e7256147a67e5
	public FruitShop(String[] fruit_list, double[] prices, int[] stocks) throws NoProperFormatException {
		super(fruit_list, prices, stocks);
	}

	public FruitShop() {
		setItem_list(new String[] { "Banana", "Apple", "Orange", "Guava", "Grapes" });
		setItem_costs(new double[] { 30.00, 36.00, 24.00, 40.00, 20.00 });
		setItem_stocks(new int[] { 25, 10, 20, 10, 20 });
	}
}