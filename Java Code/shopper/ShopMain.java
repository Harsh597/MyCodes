package shopper;

import java.util.*;

public class ShopMain {
	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		String veg, frt;
		int qt;
		try {
			String[] veggies = new String[] { "Arbi", "Aloo", "Bhendi", "Capsicum", "Dondakaya", "Turai", "Karela" };
			double[] costs = new double[] { 60.00, 30.00, 24.00, 60.00, 40.00, 80.00, 36.00 };
			int[] quants = new int[] { 12, 30, 16, 15, 20, 12, 10 };
			VegetableShop reddy = new VegetableShop(veggies, costs, quants);
			FruitShop pradeep = new FruitShop();

			System.out.println("Reddy's Vegetable Shop");
			reddy.listItem();
			System.out.print("Enter Vegetable Name and Qty: ");
			veg = inp.next();
			qt = inp.nextInt();
			double amount = reddy.buyItem(veg, qt);
			if (amount > 0)
				System.out.printf("Purchased %d Kilos of %s for Rs. %5.2f\n", qt, veg, amount);
			reddy.listItem();

			System.out.println("Pradeep's Fruit Shop");
			pradeep.listItem();
			System.out.print("Enter Fruit Name and Qty: ");
			frt = inp.next();
			qt = inp.nextInt();
			amount = pradeep.buyItem(frt, qt);
			System.out.printf("Purchased %d Kilos of %s for Rs. %5.2f\n", qt, frt, amount);
			pradeep.listItem();
		}
		catch (ArithmeticException ae) {
			System.out.println(ae);
		} catch (InputMismatchException e) {
			System.out.println("InputMismatchException:  Invalid Input ");
		}
	}
	
}

