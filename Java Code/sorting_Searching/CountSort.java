package sorting_Searching;

import java.util.Arrays;

public class CountSort {
	static void countSorting(int arr[], int n) {
		int max = arr[0];
		for (int i = 1; i < arr.length; i++) {
			max = Math.max(max, arr[i]);
		}

		int[] count_arr = new int[max + 1];
		Arrays.fill(count_arr, 0);

		for (int i = 0; i < arr.length; i++) {
			++count_arr[arr[i]];
		}

		for (int i = 1; i < count_arr.length; i++) {
			count_arr[i] += count_arr[i - 1];
		}

		int[] sorted_arr = new int[n];

		for (int i = n - 1; i >= 0; i--) {
			sorted_arr[--count_arr[arr[i]]] = arr[i];
		}

		for (int i = 0; i < sorted_arr.length; i++) {
			arr[i] = sorted_arr[i];
		}

	}
	// modifying count array

	public static void main(String[] args) {

		int arr[] = { 1, 3, 2, 3, 4, 1, 6, 4, 3 };
		System.out.println("\nBefore  Sorting");
		displayArray(arr);
		countSorting(arr, arr.length);
		System.out.println("\nAfter  Sorting");
		displayArray(arr);
	}

	public static void displayArray(int arr[]) {
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}

}
