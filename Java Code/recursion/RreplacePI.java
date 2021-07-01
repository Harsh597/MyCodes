package recursion;

public class RreplacePI {

	static void replacePI(String str, int i, int len) {
		if (i > len)
			return;
		if (str.charAt(i) == 'p' && str.charAt(i + 1) == 'i') {
			System.out.print("3.14");
			replacePI(str, i + 2, len);
		} else {
			System.out.print(str.charAt(i));
			replacePI(str, i + 1, len);
		}

	}

	public static void main(String[] args) {
		String str = "pippxxppiixipi";//3.14ppxxp3.14ixi3.14
		replacePI(str, 0, str.length() - 1);

	}

}
