package complexNumber;
import java.util.Scanner;
public class Complex {
	private float _real;
	private float _imag;

	public float get_real() {
		return _real;
	}

	public void set_real(float _real) {
		this._real = _real;
	}

	public float get_imag() {
		return _imag;
	}

	public void set_imag(float _imag) {
		this._imag = _imag;
	}
	
	public void set_complex()
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("real = ");
		_real=sc.nextFloat();
		System.out.print("imaginary = ");
		_imag=sc.nextFloat();
	}
	
	public void add_complex(Complex c1,Complex c2)
	{
		_real=c1.get_real()+c2.get_real();
		_imag=c1.get_imag()+c2.get_imag();
	}
	public void sub_complex(Complex c1,Complex c2)
	{
		_real=c1.get_real()-c2.get_real();
		_imag=c1.get_imag()-c2.get_imag();
	}
	public void mul_complex(Complex c1,Complex c2)
	{
		_real=c1.get_real()*c2.get_real()-c1.get_imag()*c2.get_imag();
		_imag=c1.get_real()*c2.get_imag()+c1.get_imag()*c2.get_real();
	}
	public void conju_complex(Complex c1)
	{
		_real=c1.get_real();
		_imag=c1.get_imag()*-1;
	}
	public String  toString() {
		if (get_imag() >= 0)
			return ("Complex Number : " + get_real() + " + " + get_imag() + "i");
		else
			return ("Complex Number : " + get_real() + " - " + -1*get_imag() + "i");
	}

	public Complex() {
		_real = 0.0f;
		_imag = 0.0f;
	}

	public Complex(float x, float y) {
		_real = x;
		_imag = y;
	}

}
