package interfaceExample;

public class McaMain {

	public static void main(String[] args) {
		McaInteger mcaI = new McaInteger(1435);
		McaInteger mcaI2 = new McaInteger(1);
		McaFraction mcaF=new McaFraction(1,2);
		McaFraction mcaF2=new McaFraction(2,5);
		System.out.println(mcaI.get_digits(2));
		McaReal mcaR = new McaReal(2.36f);
		McaReal mcaR2 = new McaReal(4.07f);
//		System.out.println("Integer Part : " + mcaR.getIntPart());
//		System.out.println("Fractional Part : " + mcaR.getFracPart());
//		System.out.println(mcaI.equalsTo(mcaR));
//		System.out.println(mcaR);
//		System.out.println(mcaR2);
//		System.out.println(mcaR.addTo(mcaR2));
//		System.out.println(mcaI.addTo(mcaI2));
		System.out.println(mcaF);
		System.out.println(mcaF2);
		
//		System.out.println(mcaF.addTo(mcaF2));
//		System.out.println(mcaF.subFrom(mcaF2));
//		System.out.println(mcaF.multWith(mcaF2));
		System.out.println(mcaF.compareTo(mcaF2));

	}

}
