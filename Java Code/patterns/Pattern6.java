package patterns;

import java.util.Scanner;

public class Pattern6 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the value of n");
		int n = sc.nextInt();

		int k;

		for (int i = 1; i <= n; i++) {
			k = 1;
			for (int j = 5; j >= i; j--)
				System.out.print("  ");
			for (int j = 1; j <= 2 * i - 1; j++)
				System.out.print(k++ + " ");

			System.out.println();
		}
	}

}
