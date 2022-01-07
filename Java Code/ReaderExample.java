
import java.util.*;
import java.io.*;

public class ReaderExample {
	public static void main(String[] args) throws IOException {
		try {
			FileReader infp = new FileReader(args[0]);
			FileWriter ofp = new FileWriter(args[1]);
			int ch;

			while ((ch = infp.read()) != -1) {
				ofp.write(ch);
			}
			infp.close();
			ofp.close();
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("No arguments passed");
		}catch (FileNotFoundException e) {
			System.out.println("File Not found");
		} 
		System.out.println("THE END");
	}
}