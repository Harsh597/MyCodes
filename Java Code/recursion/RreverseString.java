package recursion;

public class RreverseString {

	static void reverse(String str, int i, int len) {
		if (i > len)
			return;

		reverse(str, i + 1, len);
		System.out.print(str.charAt(i));
	}

	public static void main(String[] args) {
		String str = "binod";
		reverse(str, 0, 4);

	}

}
