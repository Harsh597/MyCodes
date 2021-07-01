package patterns;

import java.util.Scanner;

public class PascalTriangle {

	public static int fact(int n) {
		int f = 1;
		for (int i = 2; i <= n; i++) {
			f *= i;
		}
		return f;

	}

	public static int C(int n, int r) {
		int result = fact(n) / (fact(n - r) * fact(r));
		return result;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the value of n");
		int n = sc.nextInt();

		for (int i = 0; i <= n; i++) {
			for (int j = i; j < n; j++)
				System.out.print("  ");
			for (int j = 0; j <= i; j++)
				System.out.print(C(i, j) + "   ");
			System.out.println();
		}

	}
}
