package myPrograms;

import java.util.Arrays;
import java.util.Scanner;

public class SievePrimeFactorisation {

	public static void spffactor(int n) {
		int spf[] = new int[n + 1];

		Arrays.fill(spf, 0);

		for (int i = 2; i < spf.length; i++) {
			spf[i] = i;
		}

		for (int i = 2; i < spf.length; i++) {
			if (spf[i] == i) {
				for (int j = i * i; j < spf.length; j += i) {
					if (spf[j] == j) {
						spf[j] = i;
					}
				}
			}
		}

		while (n != 1) {
			System.out.println(spf[n] + " ");
			n /= spf[n];
		}

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		spffactor(n);

	}

}
