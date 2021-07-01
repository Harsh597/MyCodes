package backTracking;

import java.util.Scanner;

public class AllStringsofNBits {

	public static void printArr(int arr[]) {
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}

	public static void allStrings(int arr[], int n) {
		if (n == 0) {
			printArr(arr);
			System.out.println();
			return;
		} 
			arr[n - 1] = 0;
			allStrings(arr, n - 1);
			arr[n - 1] = 1;
			allStrings(arr, n - 1);
		
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];
		allStrings(arr, n);

	}

}
