package shopper;

<<<<<<< HEAD
import java.util.Scanner;

public class BookMain {

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		BookShop Bshop = new BookShop();
		String book, author;
		int qt;
		try {
			Bshop.listItem();
			System.out.println("To buy books enter the following details\n");
			System.out.println("Enter Book Name: ");
			book = inp.nextLine();
			System.out.println("Enter Author Name:");
			author = inp.nextLine();
			System.out.println("Enter Quantity: ");
			qt = inp.nextInt();
			inp.nextLine();
			double amount = Bshop.buyItem(book, author, qt);
			if (amount > 0)
				System.out.printf("Purchased %d Books of %s by %s for Rs. %5.2f\n", qt, book, author, amount);
			Bshop.listItem();
			System.out.println("To add stocks of books enter the following details\n");
			System.out.println("Enter Book Name: ");
			book = inp.nextLine();
			System.out.println("Enter Author: ");
			author = inp.nextLine();
			System.out.println("Enter Quantity: ");
			qt = inp.nextInt();
			Bshop.addItem(book, author, qt);
			Bshop.listItem();
		} catch (ArithmeticException ae) {
=======
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
>>>>>>> cb0f8d61ae774798f89a9ed16a4e7256147a67e5
			System.out.println(ae);
		}

	}

}
