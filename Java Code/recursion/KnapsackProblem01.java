package recursion;

public class KnapsackProblem01 {
	static int knapsack(int wt[],int val[],int n,int W) {
		if(n==0|| W==0)
			return 0;
		
		if(wt[n-1]>W)
			return knapsack(wt,val,n-1,W);
		
		return Math.max(knapsack(wt,val,n-1,W-wt[n-1])+val[n-1],knapsack(wt,val,n-1,W));
	}
	public static void main(String[] args) {
		int wt[]= {10,20,30};
		int val[]= {100,50,150};
		System.out.println(knapsack(wt,val,3,50));
	}
}
