package interfaceExample;

public class McaReal implements McaNumber {

	float value;

	public McaReal() {
		value = 123.4f;
	}

	public McaReal(float value) {
		this.value = value;
	}

	int getIntPart() {
		return (int) value;
	}

	int countDigit(int n) {
		return (int) Math.floor(Math.log10(n) + 1);
	}

	int getFracPart() {
		String n = String.valueOf(value);
		int digit = 0;
		int dot_pos = -1;
		for (char ch : n.toCharArray()) {
			if (ch == '.')
				dot_pos++;
			else
				digit++;
		}
		int frac = Integer.parseInt(n.substring(dot_pos));

//		return (int) (value*Math.pow(10, digit-dot_pos ))%(int) (Math.pow(10, (digit-dot_pos) ));
		return frac;

	}

	@Override
	public String toString() {
		String str;
		str = "value = " + value;
		return str;
	}

	@Override
	public boolean equalsTo(Object num) {
		// TODO Auto-generated method stub
		return this == num;
	}

	@Override
	public int compareTo(Object num) {
		McaReal real = (McaReal) num;
		int result = (int) (this.value - real.value);
		if (result == 0)
			return 0;
		else if (result > 0)
			return 1;
		else
			return -1;
	}

	@Override
	public McaNumber addTo(Object num) {
		McaReal real = (McaReal) num;
		real.value += this.value;
		return real;
	}

	@Override
	public McaNumber subFrom(Object num) {
		McaReal real = (McaReal) num;
		real.value -= this.value;
		return real;
	}

	@Override
	public McaNumber multWith(Object num) {
		McaReal real = (McaReal) num;
		real.value *= this.value;
		return real;
	}

	@Override
	public McaNumber divideBy(Object num) {
		McaReal real = (McaReal) num;
		real.value /= this.value;
		return real;
	}

}
