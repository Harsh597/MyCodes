package shopper;

public class VegetableShop extends Shop {

	public VegetableShop(String[] veglist, double[] prices, int[] stocks) throws NoProperFormatException {
		super(veglist, prices, stocks);
	}

	public VegetableShop() {
		setItem_list(new String[] { "Aloo", "Bhendi", "Cabbage", "Gobi", "Tomato" });
		setItem_costs(new double[] { 30.00, 36.00, 24.00, 40.00, 20.00 });
		setItem_stocks(new int[] { 25, 10, 20, 10, 20 });
	}

}