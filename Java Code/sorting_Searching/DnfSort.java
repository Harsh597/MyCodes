package sorting_Searching;

public class DnfSort {
	static void dnfSorting(int arr[], int n) {
		int low, mid, high;
		low = mid = 0;
		high = n - 1;

		while (mid < high) {
			if (arr[mid] == 0) {
				arr[mid] = arr[low] + arr[mid] - (arr[low] = arr[mid]);
				low++;
				mid++;
			} else if (arr[mid] == 1) {
				mid++;
			} else {
				arr[mid] = arr[high] + arr[mid] - (arr[high] = arr[mid]);
				high--;
			}

		}
	}

	public static void main(String[] args) {

		int arr[] = { 0, 1, 1, 0, 0, 1, 2, 2, 1, 2 };
		System.out.println("\nBefore  Sorting");
		displayArray(arr);
		dnfSorting(arr, arr.length);
		System.out.println("\nAfter  Sorting");
		displayArray(arr);
	}

	public static void displayArray(int arr[]) {
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}

}
