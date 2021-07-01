package patterns;

import java.util.Scanner;

public class Pattern7 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the value of n");
		int n = sc.nextInt();
		int k;
		for (int i = 1; i <= n; i++) {
			k = i;
			for (int j = i; j < n; j++)
				System.out.print("   ");
			for (int j = 1; j <= 2*i-1; j++) {
				if(j==1 ||j==2*i-1)
				System.out.print(k+ "  ");
				else
					System.out.print("0  ");
			}
			
			System.out.println();
		}

	}

}
