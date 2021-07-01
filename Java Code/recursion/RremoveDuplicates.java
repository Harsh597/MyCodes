package recursion;

public class RremoveDuplicates {

	static String removeDuplicates(String str, int i) {
		if(i>=str.length())
		return "";
		if(str.charAt(i)==removeDuplicates(str, i+1).charAt(0))
			return removeDuplicates(str, i+1);
		
			return str.charAt(i)+ removeDuplicates(str, i+1);
	}

	public static void main(String[] args) {
		String str = "aabb";
		System.out.println(removeDuplicates(str, 0));

	}

}
