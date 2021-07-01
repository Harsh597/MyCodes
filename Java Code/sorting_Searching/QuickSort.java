package sorting_Searching;

import java.util.Scanner;

public class QuickSort {

	public static int partition(int arr[], int l, int r) {
		int pivot_ele = arr[r];
		int pindex = l - 1;
		for (int i = l; i < arr.length; i++) {
			if (arr[i] < pivot_ele) {
				pindex++;
				arr[i] = arr[pindex] + arr[i] - (arr[pindex] = arr[i]);
			}
		}
		arr[pindex + 1] = arr[r] + arr[pindex + 1] - (arr[r] = arr[pindex + 1]);
		return (pindex + 1);
	}

	public static void QuickSorting(int arr[], int l, int r) {
		if (l >= r)
			return;
		int pivot_ele_idx = partition(arr, l, r);
		QuickSorting(arr, l, pivot_ele_idx - 1);
		QuickSorting(arr, pivot_ele_idx + 1, r);

	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the no. of elements you want to sort");
		int n = sc.nextInt();

		int arr[] = new int[n];

		getArray(arr);
		QuickSorting(arr, 0, n - 1);
		System.out.println("After Sorting");
		displayArray(arr);
	}

	public static void displayArray(int arr[]) {
		for (int i : arr) {
			System.out.print(i + " ");
		}

	}

	public static void getArray(int arr[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the " + arr.length + " elements ");
		for (int i = 0; i < arr.length; i++)
			arr[i] = sc.nextInt();
	}

}
