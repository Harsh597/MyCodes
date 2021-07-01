package myPrograms;

import java.util.Arrays;
import java.util.Scanner;

public class FirstRepeatingElement {

	public static void main(String[] args) {
		// problem : Given an array arr[] of size N. The task is to find the first
		// repeating element in the array of
		// integers,i.e. an element that occurs more than once and whose index f first
		// occurrence is smallest.
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];
		int minidx = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;

		for (int i = 0; i < arr.length; i++)
			arr[i] = sc.nextInt();

		for (int i = 0; i < arr.length; i++)
			max = Math.max(max, arr[i]);

		int idx[] = new int[max + 1];
		Arrays.fill(idx, -1);

		for (int i = 0; i < arr.length; i++) {
			if (idx[arr[i]] != -1)
				minidx = Math.min(idx[arr[i]], minidx);
			else
				idx[arr[i]] = i;
		}

		if (minidx == Integer.MAX_VALUE)
			System.out.println("-1");
		else
			System.out.println((minidx + 1));
	}

}
