package sorting_Searching;

import java.util.Scanner;

public class BubbleSorting {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the no. of elements you want to sort");
		int n = sc.nextInt();

		int arr[] = new int[n];

		getArray(arr);
		//bubbleSort(arr);
		ibubbleSort(arr);
		System.out.println("\nAfter Full Sorting");
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

	public static void ibubbleSort(int arr[]) {
		System.out.println("\nImprovised Bubble Sorting");
		int n = arr.length;
		for (int i = 0; i < n - 1; i++) {
			boolean sorted = true;
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					arr[j + 1] = arr[j] + arr[j + 1] - (arr[j] = arr[j + 1]); // b=a+b-(a=b)
					sorted = false;
				}
			}
			if (sorted)
				break;
			System.out.println("\nAfter " + (i + 1) + " iteration");
			displayArray(arr);
		}
	}

	public static void bubbleSort(int arr[]) {
		System.out.println("\nNormal Bubble Sorting");
		int n = arr.length;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					arr[j + 1] = arr[j] + arr[j + 1] - (arr[j] = arr[j + 1]); // b=a+b-(a=b)
				}
			}
			System.out.println("\nAfter " + (i + 1) + " iteration");
			displayArray(arr);
		}
	}

	
}
