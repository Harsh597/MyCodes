package myPrograms;

public class Panagram {
	/* package whatever //do not write package name here */

	public static String missingPanagram(String str) {
		String ans = "";
		str = str.toLowerCase();

		int j = 0;
		for (int i = 0; i < 26; i++) {
			if (((i + 97) == ( str.charAt(j)))) {
				j++;
				i++;
			}
			else {
				char ch = (char) (i + 97);
				ans += Character.toString(ch);
			}
				
//			System.out.print("ascii value= " + ('z' - str.charAt(j)));
//			if (((i + 97) != ('z' - str.charAt(j)))) {
//				char ch = (char) (i + 97);
//				ans += Character.toString(ch);

		}
		return ans;
	}

	

	public static void main(String[] args) {
		System.out.println(missingPanagram("ABc"));
	}
}
