package recursion;

public class RtilingProblem {
	static int tilingWays(int n) {
		if(n==1)
			return 1;
		if(n==0)
			return 0;
		
		return tilingWays(n-1)+tilingWays(n-2);
	}
	public static void main(String[] args) {
		System.out.println(tilingWays(3));
	}

}
