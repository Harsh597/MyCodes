package shopper;

public class VegMain {

	public static void main(String[] args) {
		VegetableShop Vshop=new VegetableShop();
		try {
		Vshop.listItem();
		Vshop.buyItem("Aloo", 2);
		Vshop.listItem();
		Vshop.buyItem("Karela", 1);
		Vshop.buyItem("Gobi", 12);
		Vshop.addItem("Aloo", 10);
		Vshop.listItem();
		}
		catch (ArithmeticException ae) {
			System.out.println(ae);
		}
		
	}

}
