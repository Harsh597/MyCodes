package interfaceExample;

public class McaMain {

	public static void main(String[] args) {
		try {
			McaInteger mcaI = new McaInteger(145);
			McaInteger mcaI2 = new McaInteger(5);
			System.out.println(mcaI);
			System.out.println("digits at position 3  in " + mcaI + " is " + mcaI.get_digits(2));
			System.out.println("Comparison between " + mcaI + " &  " + mcaI2 + " is " + mcaI.compareTo(mcaI2));
			System.out.println("No. of digits in " + mcaI + " is " + mcaI.getNum_digits());
//			System.out.println("Addition of " + mcaI + " & " + mcaI2 + " is " + mcaI.addTo(mcaI2));
			System.out.println("Divison  of " + mcaI + " by " + mcaI2 + " is " + mcaI.divideBy(mcaI2));

//			McaReal mcaR = new McaReal(10.0f);
//		McaReal mcaR2 = new McaReal(123.4f);
//		System.out.println(mcaR);
//		System.out.println(mcaR2);
//		System.out.println(mcaR2.divideBy(mcaR));
//		System.out.println("Integer Part : " + mcaR2.getIntPart());
//		System.out.println("Fractional Part : " + mcaR2.getFracPart());

//			McaFraction mcaF = new McaFraction(1, 2);
//			McaFraction mcaF2 = new McaFraction(2, 5);
//			System.out.println(mcaF);
//			System.out.println(mcaF2);
//			System.out.println(mcaF2.toDecimal());
//			System.out.println(mcaF.addTo(mcaF2));
//			System.out.println(mcaF.subFrom(mcaF2));
//			System.out.println(mcaF2.toDecimal());
//			System.out.println("comparison result : " + mcaF.compareTo(mcaF2));

		} catch (ClassCastException e) {
			System.out.println("ClassCastException : Operations can be performed only on object of similar classes");
		} catch (ArithmeticException ae) {
			System.out.println("DivisionbyZeroException : Denominator cannot be zero ");
		}
	}

}
