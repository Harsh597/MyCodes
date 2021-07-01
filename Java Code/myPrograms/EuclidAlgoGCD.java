package myPrograms;

import java.util.Scanner;

public class EuclidAlgoGCD {

	public static int gcd(int a, int b) {
		while (b != 0) {
			int rem = a % b;
			a = b;
			b = rem;
		}

		return a;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		System.out.println(gcd(a, b));

	}

}
