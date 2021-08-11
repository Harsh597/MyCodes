package shopper;

public class BookMain {

	public static void main(String[] args) {
		BookShop Bshop=new BookShop();
		try {
			Bshop.listItem();
			Bshop.buyItem("Java", 2);
			Bshop.listItem();
			Bshop.buyItem("Networking", 1);
			Bshop.buyItem("C++", 12);
			Bshop.addItem("Data Structure", 10);
			Bshop.listItem();
		}
		catch (ArithmeticException ae) {
			System.out.println(ae);
		}

	}

}
