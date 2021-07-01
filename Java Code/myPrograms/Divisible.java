package myPrograms;

import java.util.Scanner;

public class Divisible {

	public static int divisible(int n, int a, int b) {
		int c1 = n / a;
		int c2 = n / b;
		int c3 = n / (a * b);
		return (c1 + c2 - c3);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		System.out.println(divisible(n, a, b));

	}

}
