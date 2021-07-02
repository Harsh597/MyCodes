package complexNumber;

import java.util.Scanner;

public class MainComplex {

	public static void main(String[] args) {
		Complex cmplx = new Complex();
		Complex c1 = new Complex();
		Complex c2 = new Complex();
		Scanner sc = new Scanner(System.in);
		char choice = 'y';
		do {
			System.out.println("Choose below operations to perform on Complex Number");
			System.out.println("1) Addition\n2) Subtraction\n3) Multiplication\n4) Inverse\n5) Comjugate");
			choice = sc.next().charAt(0);
			switch (choice) {
			case '1':

				System.out.println("Enter First Complex Number");
				c1.set_complex();
				System.out.println(c1);
				System.out.println("Enter Second Complex Number");
				c2.set_complex();
				System.out.println(c2);
				cmplx.add_complex(c1, c2);
				System.out.println("After Additon");
				System.out.println(cmplx);

				break;
			case '2':
				System.out.println("Enter First Complex Number");
				c1.set_complex();
				System.out.println(c1);
				System.out.println("Enter Second Complex Number");
				c2.set_complex();
				System.out.println(cmplx);
				cmplx.sub_complex(c1, c2);
				System.out.println("After Subtraction");
				System.out.println(c2);

				break;
			case '3':
				System.out.println("Enter First Complex Number");
				c1.set_complex();
				System.out.println(c1);
				System.out.println("Enter Second Complex Number");
				c2.set_complex();
				System.out.println(c2);
				cmplx.mul_complex(c1, c2);
				System.out.println("After Multiplication");
				System.out.println(cmplx);

				break;
			case '4':
				System.out.println("Enter  Complex Number");
				c1.set_complex();
				System.out.println(c1);
				cmplx.inverse_complex(c1);
				System.out.println("After Inverse");
				System.out.println(cmplx);
				break;

				
			case '5':
				System.out.println("Enter  Complex Number");
				c1.set_complex();
				System.out.println(cmplx);
				cmplx.conju_complex(c1);
				System.out.println("After Conjugate");
				System.out.println(cmplx);
				break;

			default:
				break;
			}
			System.out.println("Do you want to continue: y/n?");
			choice=sc.next().charAt(0);
		} while (choice=='y'||choice=='Y');

	}

}
