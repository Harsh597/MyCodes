package interfaceExample;

public class McaFraction extends Exception implements McaNumber {

	private int numerator;
	private int denominator;

	public McaFraction() {
		numerator = 1;
		denominator = 2;
	}

	public McaFraction(int numerator, int denominator) {
		this.numerator = numerator;
		numerator /= denominator;// if division by zero then exception generates here
		this.denominator = denominator;
	}

	public int getNumerator() {
		return numerator;
	}

	public int getDenominator() {
		return denominator;
	}

	public String toString() {
		String str;
		str = "McaFraction : " + numerator + "/" + denominator;
		return str;
	}

	public float toDecimal() {
		float result = ((float) getNumerator() / getDenominator());
		result = Float.parseFloat(String.format("%.4f", result));
		return result;
	}

	@Override
	public boolean equalsTo(Object num) {
		return this == num;
	}

	@Override
	public int compareTo(Object num) {
		McaFraction frac = (McaFraction) num;
		float result = (this.toDecimal() - frac.toDecimal());
		if (result == 0)
			return 0;
		else if (result > 0)
			return 1;
		else
			return -1;
	}

	@Override
	public McaNumber addTo(Object num) {
		McaFraction frac = (McaFraction) num;
		int Dr, Nr;
		Dr = this.denominator * frac.denominator;
		Nr = ((Dr / this.denominator) * this.numerator) + ((Dr / frac.denominator) * frac.numerator);
		frac.numerator = Nr;
		frac.denominator = Dr;
		return frac;
	}

	@Override
	public McaNumber subFrom(Object num) {
		McaFraction frac = (McaFraction) num;
		int Dr, Nr;
		Dr = this.denominator * frac.denominator;
		Nr = ((Dr / frac.denominator) * frac.numerator) - ((Dr / this.denominator) * this.numerator);
		frac.numerator = Nr;
		frac.denominator = Dr;
		return frac;
	}

	@Override
	public McaNumber multWith(Object num) {
		McaFraction frac = (McaFraction) num;
		frac.denominator = this.denominator * frac.denominator;
		frac.numerator = this.numerator * frac.numerator;

		return frac;
	}

	@Override
	public McaNumber divideBy(Object num) {
		McaFraction frac = (McaFraction) num;
		int Nr, Dr;

		Nr = this.numerator * frac.denominator;
		Dr = this.denominator * frac.numerator;
		frac.numerator = Nr;
		frac.denominator = Dr;
		return frac;
	}

}
