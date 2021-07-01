package sorting_Searching;

import java.util.Scanner;

public class SelectionSorting {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the no. of elements you want to sort");
		int n = sc.nextInt();

		int arr[] = new int[n];

		getArray(arr);
		selectionSort(arr);
		System.out.println("\nAfter Final Sorting");
		displayArray(arr);
	}

	public static void getArray(int arr[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the " + arr.length + " elements ");
		for (int i = 0; i < arr.length; i++)
			arr[i] = sc.nextInt();
	}

	public static void selectionSort(int arr[]) {
		int n = arr.length;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] > arr[j])
					arr[i] = arr[j] + arr[i] - (arr[j] = arr[i]); // b=a+b-(a=b)
			}
			

		}
	}

	public static void displayArray(int arr[]) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}
}
