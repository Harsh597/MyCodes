package myPrograms;

import java.util.Scanner;

public class PairSumProblem {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];

		int sum = sc.nextInt();

		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
		}

		int low = 0;
		int high = n - 1;

		while (low < high) {
			if (arr[low] + arr[high] == sum) {
				System.out.println(low + " " + high);
				return;
				}
			else if (arr[low] + arr[high] > sum)
				high--;
			else
				low++;

		}
		System.out.println(-1);

}

}
