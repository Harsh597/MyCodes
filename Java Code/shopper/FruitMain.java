package shopper;

public class FruitMain {

	public static void main(String[] args) {
		FruitShop Fshop=new FruitShop();
		try {
		Fshop.listItem();
		Fshop.buyItem("Apple", 2);
		Fshop.listItem();
		Fshop.buyItem("Banana", 1);
		Fshop.buyItem("Orange", 12);
		Fshop.addItem("PineApple", 10);
		Fshop.listItem();
		}
		catch (ArithmeticException ae) {
			System.out.println(ae);
		}
		

	}

}
