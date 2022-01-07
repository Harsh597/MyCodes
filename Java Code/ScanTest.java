import java.util.*;

public class ScanTest {
    public static void main (String[] args) {
        Scanner inp = new Scanner (System.in);
        String word;
        
        word = inp.next();
        while (word.compareTo("quit") != 0) {
            System.out.println("Why did you type " + word + "?");
            word = inp.next();
        }
    }
}