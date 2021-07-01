package patterns;

import java.util.Scanner;

public class Pattern8 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the value of n");
		int n = sc.nextInt();
		int k = 0;

		for (int i = 1; i <= n + 1; i++) {
			k = n + 2 - i;
			int t = n;
			for (int j = i; j <= n; j++)
				System.out.print("  ");
			for (int j = 1; j <= i; j++) {
				if (k > n || i == 1)
					System.out.print("0 ");
				else {
					System.out.print(k + " ");
					k++;
				}

			}
			if (i > 1) {
				for (int j = 1; j < i; j++) {

					System.out.print(t-- + " ");
				}
			}
			System.out.println();
		}

	}

}
