package shopper;

public class VegetableShop extends Shop {
<<<<<<< HEAD
	// Ans-2.(i)
	// Only constructors are here in the class all the other metods and members are
	// derived from the super class Shop
	// No overriding requires here
=======

>>>>>>> cb0f8d61ae774798f89a9ed16a4e7256147a67e5
	public VegetableShop(String[] veglist, double[] prices, int[] stocks) throws NoProperFormatException {
		super(veglist, prices, stocks);
	}

	public VegetableShop() {
		setItem_list(new String[] { "Aloo", "Bhendi", "Cabbage", "Gobi", "Tomato" });
		setItem_costs(new double[] { 30.00, 36.00, 24.00, 40.00, 20.00 });
		setItem_stocks(new int[] { 25, 10, 20, 10, 20 });
	}

}