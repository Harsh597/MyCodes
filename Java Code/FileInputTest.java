import java.util.*;
import java.io.*;

public class FileInputTest {
	public static void main(String[] args) throws FileNotFoundException {
		File f = new File("C:\\Users\\harsh\\OneDrive\\Desktop\\HarshG Codes\\Java Code\\data.txt");
		Scanner input = new Scanner(f);
		while (input.hasNext()) {
			String data = input.next();
			System.out.println("data from file: " + data);
		}
	}
}