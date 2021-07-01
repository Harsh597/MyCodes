package bulb;

public class MainLightBulb {

	public static void main(String[] args) {
		// Bulb Type:
		// CFL=1,Tubelight=2,Filament =3,LED=4,Halogen=5;
		LightBulb lb=new LightBulb();
		LightBulb lb1=new LightBulb();
		System.out.println(lb.toString(true));
		lb.set_type(1);
		lb.set_power(30);
		lb.set_price(560);
		lb.set_installed(true);
		lb.set_status(true);
		System.out.println(lb.toString(true));	
		lb.set_installed(false);
		System.out.println(lb.toString(true));
		lb1.set_power(50);
		System.out.println(lb1.isGreater(lb));

	}

}
