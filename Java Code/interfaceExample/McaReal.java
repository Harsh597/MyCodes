package interfaceExample;

public class McaReal implements McaNumber {

	private float value;

	public float getValue() {
		return value;
	}

	public McaReal() {
		value = 123.4f;
	}

	public McaReal(float value) {
		this.value = value;
	}

	int getIntPart() {
		return (int) value;
	}

	int getFracPart() {
		String str_real = String.valueOf(value);
		int dot_pos = 0;
		for (char ch : str_real.toCharArray()) {
			if (ch == '.') {
				break;
			}
			dot_pos++;
		}
		int frac = Integer.parseInt(str_real.substring(dot_pos + 1));
		return frac;

	}

	@Override
	public String toString() {
		String str;
		str = "McaReal : " + String.format("%.4f", value);
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
		real.value = this.value/real.value;
		return real;
	}

}
