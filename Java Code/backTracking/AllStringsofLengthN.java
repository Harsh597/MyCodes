package backTracking;

import java.util.Scanner;

public class AllStringsofLengthN {
	public static void printArr(int arr[]) {
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}

	public static void allStrings(int arr[], int n, int k) {
		if (n == 0) {
			printArr(arr);
			System.out.println();
			return;
		}
		for (int i = 0; i < k; i++) {
			arr[n - 1] = i;
			allStrings(arr, n - 1, k);

		}

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int arr[] = new int[n];
		allStrings(arr, n, k);

	}

}
