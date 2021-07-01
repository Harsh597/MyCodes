package myPrograms;

import java.util.Scanner;

public class SubArraysSum {
// Total Subarrays =C(n,2)+n =n(n+1)/2;
// Total Subsequence = 2^n;
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int arr[]=new int[n];
		int curr=0;
		
		for (int i = 0; i < arr.length; i++) {
			arr[i]=sc.nextInt();
		}
		
		for (int i = 0; i < arr.length; i++) {
			for (int j = i; j < arr.length; j++) {
				curr+=arr[j];
				System.out.println(curr);
			}
			
		}
		
	}

}
