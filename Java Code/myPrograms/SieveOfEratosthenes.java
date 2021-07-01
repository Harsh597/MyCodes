package myPrograms;

import java.util.Arrays;
import java.util.Scanner;

public class SieveOfEratosthenes {

	public static void sieve(int n) {
		int prime[] = new int[n + 1];

		Arrays.fill(prime, 0);

		for (int i = 2; i < prime.length; i++) {
			if (prime[i] == 0) {
				for (int j = i * i; j < prime.length; j+=i) {
					prime[j] = 1;
				}
			}
		}
		
		for (int i = 2; i < prime.length; i++) {
			if(prime[i]==0)
				System.out.println(i);
		}
	}

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sieve(n);

	}

}
