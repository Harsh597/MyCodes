package myPrograms;

import java.util.Iterator;
import java.util.Scanner;

public class IsPrime {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number ");
		int n = sc.nextInt();
		boolean isPrime = true;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				isPrime = false;
				break;
			}

		}
		if (isPrime)
			System.out.println(n + " is Prime number");
		else
			System.out.println(n + " is not Prime number");
	}

}
