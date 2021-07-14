package matrixDeterminant;

public class Determinant {

	static double det(double[][] mat,int c, int rows, int cols) {
		int ans = 0;
		int sign = -1;
		if (rows != cols) {
			System.out.println("Determinant is not possible");
			return Double.MAX_VALUE;
		}
		// calculating determinant of order 2 directly
		if (rows == 2 && cols == 2) {
			return (mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1]);

		} else {

			for (int i = 0; i < rows; i++) {
				double[][] submat = new double[rows - 1][cols - 1];
				int srow = 0;
				int scol = 0;
				for (int j = 1; j < rows; j++) {     // expanding determinant through first row i.e. skipping the first row
					for (int k = 0; k < cols; k++) {
						if (k == i)
							continue;
						if (scol >= cols - 1) {
							srow++;
							scol = 0;
						}
						submat[srow][(scol)] = mat[j][k];
						scol++;

					}

				}
				// recursively solving the sub-determinant
				ans += (sign *= -1) * mat[0][i] * det(submat,i, rows - 1, cols - 1); 
			}
			return ans;

		}

	}

	public static void main(String[] args) {
		Matrix mat1 = new Matrix();
		Matrix mat2 = new Matrix();
		mat1.set_Element(0, 0, 6);
		mat1.set_Element(0, 1, 1);
		mat1.set_Element(0, 2, 1);
		mat1.set_Element(1, 0, 4);
		mat1.set_Element(1, 1, -2);
		mat1.set_Element(1, 2, 5);
		mat1.set_Element(2, 0, 2);
		mat1.set_Element(2, 1, 8);
		mat1.set_Element(2, 2, 7);

		mat1.get_Matrix();
		mat2.get_Matrix();
		System.out.println("After Multiplication:");
		//Matrix.mul(mat1, mat2);
		System.out.println("Determinant : " + det(mat1.getMat(), 0, mat1.getRows(), mat1.getCols()));

	}

}
