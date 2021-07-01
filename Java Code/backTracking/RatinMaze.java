package backTracking;

import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

public class RatinMaze {

	static Boolean isSafe(int arr[][], int x, int y, int n) {
		if (x < n && y < n && arr[x][y] == 1)
			return true;
		return false;
	}

	static Boolean  ratinMaze(int arr[][], int x, int y, int n, int solArr[][]) {

		if (x == n - 1 && y == n - 1) {
			solArr[x][y] = 1;
			return true;
		}

		if (isSafe(arr, x, y, n)) {
			solArr[x][y] = 1;
			if (ratinMaze(arr, x + 1, y, n, solArr))
				return true;
			if (ratinMaze(arr, x, y + 1, n, solArr))
				return true;
			solArr[x][y] = 0;// backtracking
			return false;

		}
		return false;

	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int arr[][] = new int[n][n];
		int solArr[][] = new int[n][n];
		//Arrays.fill(solArr, 0);
		for (int[] is : solArr) {
			Arrays.fill(is, 0);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j]=sc.nextInt();
			}
		}
		ratinMaze(arr, 0, 0, n, solArr);
		
		for (int[] is : solArr) {
			for (int is2 : is) {
				System.out.print(is2+" ");
			}
			System.out.println();
			
		}
		

	}

}
