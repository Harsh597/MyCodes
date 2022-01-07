package shopper;

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
			System.out.println(ae);
		}

	}

}
