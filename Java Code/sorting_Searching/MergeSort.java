package sorting_Searching;

import java.util.Scanner;

public class MergeSort {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the no. of elements you want to sort");
		int n = sc.nextInt();

		int arr[] = new int[n];

		getArray(arr);
		mergeSort(arr, 0, n - 1);
		System.out.println("After Sorting");
		displayArray(arr);
	}

	public static void getArray(int arr[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the " + arr.length + " elements ");
		for (int i = 0; i < arr.length; i++)
			arr[i] = sc.nextInt();
	}

	public static void merge(int arr[], int low, int mid, int high) {
		int len1 = mid - low + 1;
		int len2 = high - mid;
		int a[] = new int[len1];
		int b[] = new int[len2];
		int i, j, k;
		for (i = 0; i < len1; i++) {
			a[i] = arr[low + i];
		}
		for (i = 0; i < len2; i++) {
			b[i] = arr[mid + 1 + i];
		}

		i = j = 0;
		 k = low;
		
		while (i < len1 && j < len2) {
			if (a[i] < b[j]) {
				arr[k] = a[i];
				i++;
			} else {
				arr[k] = b[j];
				j++;
			}
			k++;
		}
		while (i < len1) {
			arr[k++] = a[i++];

		}
		while (j < len2) {
			arr[k++] = b[j++];

		}

	}

	public static void mergeSort(int arr[], int low, int high) {

		int l = low;
		int h = high;
		if (l >= h)
			return;
		int m = (l + h) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, h);

		merge(arr, l, m, h);
	}

	public static void displayArray(int arr[]) {
		for (int i : arr) {
			System.out.print(i + " ");
		}
		
	}

}
