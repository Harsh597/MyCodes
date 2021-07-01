package recursion;

import java.util.Arrays;

public class RcheckSortedArray {

	public static boolean isSorted(int arr[], int n) {

		if (n == 1)
			return true;
		boolean restarray = isSorted(Arrays.copyOfRange(arr, 1, arr.length ), n - 1);
		return (arr[0] < arr[1]) && restarray;

	}

	public static void main(String[] args) {
		int arr[] = { 1, 3, 4 };
		
		System.out.println(isSorted(arr, arr.length));

	}

}
