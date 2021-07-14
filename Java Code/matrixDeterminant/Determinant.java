package matrixDeterminant;

public class Determinant {

	static double det(double[][] mat, int r, int c, int rows, int cols) {
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
				for (int j = 0; j < rows; j++) {
					for (int k = 0; k < cols; k++) {
						if (j == r || k == i)
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
				ans += (sign *= -1) * mat[0][i] * det(submat, 0, i, rows - 1, cols - 1); // expanding determinant
																							// through first row
			}
			return ans;

		}

	}

	public static void main(String[] args) {
		Matrix mat1 = new Matrix();
		Matrix mat2 = new Matrix();
		mat1.set_Element(0, 0, 1);
		mat1.set_Element(1, 2, 2);
		mat1.set_Element(1, 2, 3);
		mat1.set_Element(2, 1, 3);
		mat1.set_Element(2, 2, 4);

		mat1.get_Matrix();
		mat2.get_Matrix();
		System.out.println("After Multiplication:");
		Matrix.mul(mat1, mat2);
		//double [][]matrix=mat1.getMat();
		System.out.println("Determinant : " + det(mat1.getMat(), 0, 0, mat1.getRows(), mat1.getCols()));

	}

}
