package complexNumber;
import java.util.Scanner;
import java.lang.Math;
//import java.util.*;
public class Complex {
	private double _real;
	private double _imag;

	public double get_real() {
		return _real;
	}

	public void set_real(double _real) {
		this._real = _real;
	}

	public double get_imag() {
		return _imag;
	}

	public void set_imag(double _imag) {
		this._imag = _imag;
	}
	
	public void set_complex()
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("real = ");
		_real=sc.nextDouble();
		System.out.print("imaginary = ");
		_imag=sc.nextDouble();
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
	
	public void inverse_complex(Complex c)
	{
		if(c.get_real()==0 && c.get_imag()==0)
			System.out.println("\nNot Possible");
		else
		{
			double modC=(Math.pow(2,c.get_real())+Math.pow( 2,c.get_imag()));
			_real= c.get_real()/modC;
			_imag=-1*(c.get_imag()/modC);
		}
	}
	public String  toString() {
		if (get_imag() >= 0)
			return ("Complex Number : " + String.format("%.2f",get_real()) + " + " + String.format("%.2f",get_imag()) + "i");
		else
			return ("Complex Number : " + String.format("%.2f",get_real()) + " - " + String.format("%.2f",-1*get_imag()) + "i");
	}

	public Complex() {
		_real = 0.0f;
		_imag = 0.0f;
	}

	public Complex(double x, double y) {
		_real = x;
		_imag = y;
	}

}
