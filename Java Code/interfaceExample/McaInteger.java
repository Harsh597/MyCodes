package interfaceExample;

public class McaInteger implements McaNumber {

	private int num;
	private int num_digits;

	public int getNum() {
		return num;
	}

	public int getNum_digits() {
		return num_digits;
	}

	public McaInteger() {
		num = 234;
		num_digits = (int) Math.floor(Math.log10(num) + 1);

	}

	public McaInteger(int n) {
		num = n;
		num_digits = (int) Math.floor(Math.log10(num) + 1);

	}

	int get_digits(int dnum) {
		int temp;
		if (dnum > num_digits)
			return -1;
		temp = (int) (num / (Math.pow(10, (num_digits - (dnum + 1)))));
		return temp % 10;

	}

	@Override
	public String toString() {
		String str;
		str = "Integer : " + num;
		return str;
	}

	@Override
	public boolean equalsTo(Object num) {
		return this == num;
	}

	@Override
	public int compareTo(Object num) {

		McaInteger mca = (McaInteger) num;
		int result = this.num - mca.num;
		if (result == 0)
			return 0;
		else if (result > 0)
			return 1;
		else
			return 0;
	}

	@Override
	public McaNumber addTo(Object num) {
		McaInteger mca = (McaInteger) num;
		mca.num = this.num + mca.num;
		return mca;
	}

	@Override
	public McaNumber subFrom(Object num) {
		McaInteger mca = (McaInteger) num;
		mca.num = mca.num - this.num;
		return mca;
	}

	@Override
	public McaNumber multWith(Object num) {
		McaInteger mca = (McaInteger) num;
		mca.num = this.num * mca.num;
		return mca;
	}

	@Override
	public McaNumber divideBy(Object num) {
		McaInteger mca = (McaInteger) num;
		mca.num = this.num / mca.num;
		return mca;
	}

}
