package myPrograms;

import java.util.Scanner;

public class LongestArithematicSubarray {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int arr[] = new int[n];

		for (int i = 0; i < arr.length; i++)
			arr[i] = sc.nextInt();

		int pd = arr[1] - arr[0];
		int curr = 2; // Current Arithmetic Subarray Length
		int ans = 2; // Max Arithmetic subarray length

		for (int i = 2; i < arr.length; i++) {
			if (pd == (arr[i] - arr[i - 1])) {
				curr++;
				if (curr > ans)
					ans = curr;
			} else {
				pd = arr[i] - arr[i - 1];
				curr = 2;

			}
		}
		System.out.println(ans);

	}

}
