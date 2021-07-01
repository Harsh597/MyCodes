package myPrograms;

import java.util.Scanner;

public class KadanesAlgorithm {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int arr[] = new int[n];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
		}

		int currsum = 0;
		int maxsum = 0;
		int minsum = 0;

		for (int i = 0; i < arr.length; i++) {
			currsum += arr[i];
			if (currsum < 0)
				currsum = 0;
			maxsum = Math.max(maxsum, currsum);
			minsum = Math.min(minsum, arr[i]);

		}
		if (maxsum == 0)
			System.out.println(minsum);
		else
			System.out.println(maxsum);

	}

}
