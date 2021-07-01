package myPrograms;

import java.util.Scanner;

public class SeriesSum {

	public static void main(String[] args) {
		//Compute the natural logarithm of 2, by adding up to n terms in the  series
		Scanner sc= new Scanner(System.in);
		float result=0;
		byte sign=1;
		System.out.println("Enter the value of n for the series of sum");
		int n=sc.nextInt();
		for (int i = 1; i <= n; i++) {
			result+=(sign*1)/(float)i;
			sign*=-1;
			
		}
		System.out.println("Result = "+ result);
	}

}
