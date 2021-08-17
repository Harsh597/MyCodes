package interfaceExample;


public class McaInteger implements McaNumber {

	int num;
	int num_digits;

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
		System.out.println("num = " + num);
		temp = (int) (num / (Math.pow(10, (num_digits - (dnum + 1)))));
		
			return temp % 10;

//		return (num/(10*(num_digits-(dnum+1))))%10;

	}

	@Override
	public String toString() {
		String str;
		str = "num = " + num;
		return str;
	}

	@Override
	public boolean equalsTo(Object num) {
		return this== num;
	}

	@Override
	public int compareTo(Object num) {
		
	McaInteger mca = (McaInteger) num;
		return this.num - mca.num;
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
		mca.num = this.num - (Integer) num;
		return mca;
	}

	@Override
	public McaNumber multWith(Object num) {
		McaInteger mca = (McaInteger) num;
		mca.num = this.num * (Integer) num;
		return mca;
	}

	@Override
	public McaNumber divideBy(Object num) {
		McaInteger mca = (McaInteger) num;
		mca.num = (Integer) num / this.num;
		return mca;
	}

}
