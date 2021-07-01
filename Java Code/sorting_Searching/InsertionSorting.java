package sorting_Searching;

import java.util.Scanner;

public class InsertionSorting {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the no. of elements you want to sort");
		int n = sc.nextInt();

		int arr[] = new int[n];

		getArray(arr);
		insertionSort(arr);
		System.out.println("After Sorting");
		displayArray(arr);
	}

	public static void getArray(int arr[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the " + arr.length + " elements ");
		for (int i = 0; i < arr.length; i++)
			arr[i] = sc.nextInt();
	}

	public static void insertionSort(int arr[]) {
		int n = arr.length;
		int i, j, temp;
		for (i = 1; i < n; i++) {
			temp = arr[i];
			j = i - 1;
			while (j >= 0 && temp < arr[j]) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = temp;
		}

	}

	public static void displayArray(int arr[]) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}

}
