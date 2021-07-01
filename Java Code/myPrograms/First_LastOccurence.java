package myPrograms;

public class First_LastOccurence {

	static int firstocc(int arr[], int n, int i, int key) {
		if (i == n)
			return -1;
		if (arr[i] == key)
			return i;
		return firstocc(arr, n, i + 1, key);

	}

	static int lastocc(int arr[], int n, int i, int key) {
		if (i == n)
			return -1;
		int restarray = lastocc(arr, n, i + 1, key);
		if (restarray != -1)
			return restarray;

		if (arr[i] == key)
			return i;

		return -1;

	}

	public static void main(String[] args) {
		int arr[] = { 4, 2, 1, 2, 5, 2,7 };
		System.out.println(firstocc(arr, arr.length, 0, 2));
		System.out.println(lastocc(arr, arr.length, 0, 2));

	}

}
