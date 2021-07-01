package myPrograms;

import java.util.Scanner;

public class MatrixSearch {

	public static void main(String[] args) {
		// Search for an element in the matrix
		// Integers in each row are sorted in ascending from left to right
		// Integers in each column are sorted in ascending from top to bottom.
		Scanner sc = new Scanner(System.in);
		int arr[][] = { { 1, 4, 7, 11 }, { 2, 5, 8 ,12}, { 3, 6, 9, 16 }, { 10, 13, 14, 17 } };

		int key = sc.nextInt();
		int r = 0, c = 3;
		while (r <= 3 && c >= 0) {
			if (key == arr[r][c]) {
				System.out.println("Found");
				return;
			} else if (key > arr[r][c])
				r++;
			else
				c--;

		}
		System.out.println("Not Found");

	}

}
