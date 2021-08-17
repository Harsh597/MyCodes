package interfaceExample;

public class McaFraction implements McaNumber {

	int numerator;
	int denominator;

	public McaFraction() {
		numerator = 1;
		denominator = 2;
	}

	public McaFraction(int numerator, int denominator) {
		this.numerator = numerator;
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
		str = "value = " + numerator + "/" + denominator;
		return str;
	}

	public float toDecimal() {
		return (float) (getNumerator() / getDenominator());
	}

	@Override
	public boolean equalsTo(Object num) {
		// TODO Auto-generated method stub
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
		Nr = ((Dr / frac.denominator) * frac.numerator)- ((Dr / this.denominator) * this.numerator) ;
		frac.numerator = Nr;
		frac.denominator = Dr;
		return frac;
	}

	@Override
	public McaNumber multWith(Object num) {
		System.out.println("After multiplication");
		McaFraction frac = (McaFraction) num;
		frac.denominator = this.denominator * frac.denominator;
		frac.numerator = this.numerator * frac.numerator;

		return frac;
	}

	@Override
	public McaNumber divideBy(Object num) {
		McaFraction frac = (McaFraction) num;
		frac.denominator = this.denominator * frac.numerator;
		frac.numerator = this.numerator * frac.denominator;

		return frac;
	}

}
