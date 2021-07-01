package myPrograms;

import java.util.Arrays;

public class HighFrequencyLetter {

	public static void main(String[] args) {
		String s = "aeebaeacbeeadee";
		int max = 0;
		char ans = 'a' ;
		int letter[] = new int[26];

		Arrays.fill(letter, 0);
		for (int i = 0; i < s.length(); i++) {
			letter[s.charAt(i) - 'a']++;
		}

		for (int i = 0; i < letter.length; i++) {
			if (letter[i] > max) {
				max = letter[i];
				ans = (char) (i + 'a');
			}

		}


		System.out.println(max);
		System.out.println(ans);

	}

}
