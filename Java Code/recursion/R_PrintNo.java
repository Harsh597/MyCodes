package recursion;

public class R_PrintNo {

	public static void inc(int n) {
		if (n == 0)
			return;
		inc(n - 1);
		System.out.println(n);

	}

	public static void dec(int n) {
		if (n == 0)
			return;
		System.out.println(n);
		dec(n - 1);

	}

	public static void main(String[] args) {
		inc(5);
		dec(10);

	}

}
