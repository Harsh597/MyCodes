package patterns;

import java.util.Scanner;

public class Pattern2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the value of n");
		int n = sc.nextInt();

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2*(i-1); j++)
				System.out.print("  ");
			for (int j = n; j >= i; j--)
				System.out.print("* ");
			
			System.out.println();
		}

	}

}
