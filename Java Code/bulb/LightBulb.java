package bulb;

public class LightBulb {

	private int _power;
	private int _type;
	private float _price;
	private boolean _status;
	private boolean _installed;

	public int get_power() {
		return _power;
	}

	public void set_power(int _power) {
		this._power = _power;
	}

	public int get_type() {
		return _type;
	}

	public void set_type(int _type) {
		this._type = _type;
	}

	public float get_price() {
		return _price;
	}

	public void set_price(float _price) {
		this._price = _price;
	}

	public boolean is_status() {
		return _status;
	}

	public void set_status(boolean _status) {
		if (this.is_installed() == true) {
			if (_status)
				System.out.println("\nTurned ON successfully");
			else
				System.out.println("\nTurned OFF successfully");
			this._status = _status;
		} else if(this.is_installed()==false && _status==true)
			System.out.println("\nBulb is not Installed till now");
	}

	public boolean is_installed() {
		return _installed;
	}

	public void set_installed(boolean _installed) {
		if (_installed && this.is_installed() == false)
			System.out.println("\nInstalled Successfully");
		else if (!_installed && this.is_installed() == true) {
			System.out.println("\nUninstalled Successfully");
			set_status(false);
		} else if (_installed == true && this.is_installed() == true)
			System.out.println("\nAlready Installed");
		else
			System.out.println("\nAlready Uninstalled");

		this._installed = _installed;

	}

	public boolean isGreater(LightBulb lb) {
		if (this.get_power() > lb.get_power())
			return true;
		else
			return false;
	}
	
	public String toString() {
		System.out.println("\nBulb Description");
		String bulbtype = "NONE";
		if (get_type() == 1)
			bulbtype = "CFL";
		else if (get_type() == 2)
			bulbtype = "Tubelight";
		else if (get_type() == 3)
			bulbtype = "Filament";
		else if (get_type() == 4)
			bulbtype = "LED";
		else if (get_type() == 5)
			bulbtype = "Halogen";
		else
			bulbtype = "None";

		return "Type : " + bulbtype + "\nPower : " + get_power() + "\nPrice : " + get_price();
	}

	public String toString(boolean detail) {
		String isInstalled = "NO";
		String status = "OFF";
		if (detail) {
			if (is_installed() == true)
				isInstalled = "Yes";
			else
				isInstalled = "No";
			if (is_status() == true)
				status = "ON";
			else
				status = "OFF";
			return toString() + "\nInstalled : " + isInstalled + "\nStatus : " + status;
		} else
			return toString();

	}

	// constructor
	public LightBulb() {
		_power = 0;
		_status = false;
		_installed = false;

	}

}
