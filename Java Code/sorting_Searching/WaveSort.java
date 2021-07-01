package sorting_Searching;

public class WaveSort {
	static void waveSorting(int arr[], int n) {
		for (int i = 1; i < arr.length; i += 2) {
			if (arr[i] > arr[i - 1]) {
				arr[i] = arr[i - 1] + arr[i] - (arr[i - 1] = arr[i]);
			}
			if ((arr[i] > arr[i + 1]) && (i <= n - 2) ){
				arr[i] = arr[i + 1] + arr[i] - (arr[i + 1] = arr[i]);
			}
		}
	}

	public static void main(String[] args) {

		int arr[] = { 1, 3, 4, 7, 5, 6, 2 };
		System.out.println("\nBefore  Sorting");
		displayArray(arr);
		waveSorting(arr, arr.length);
		System.out.println("\nAfter  Sorting");
		displayArray(arr);
	}

	public static void displayArray(int arr[]) {
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}

}
