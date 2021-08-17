package interfaceExample;

public interface McaNumber {
	String toString();

	boolean equalsTo(Object num);

	int compareTo(Object num);

	McaNumber addTo(Object num);

	McaNumber subFrom(Object num);

	McaNumber multWith(Object num);

	McaNumber divideBy(Object num);
}
