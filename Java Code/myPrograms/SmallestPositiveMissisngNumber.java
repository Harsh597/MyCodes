package myPrograms;

import java.util.Arrays;
import java.util.Scanner;

public class SmallestPositiveMissisngNumber {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];
		int max = Integer.MIN_VALUE;

		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
		}

		for (int i : arr)
			max = Math.max(i, max);

		boolean check[] = new boolean[max + 1];
		Arrays.fill(check, false);

		for (int i = 0; i < arr.length; i++) {
			if (arr[i] >= 0)
				check[arr[i]] = true;
		}

		for (int i = 0; i < check.length; i++) {
			if (check[i] == false) {
				System.out.println(i);
				break;
			}
		}

	}

}
