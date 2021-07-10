package matrixDeterminant;

public class Matrix {
	private int rows;
	private int cols;
	double[][] mat;

	public int getRows() {
		return rows;
	}

	public int getCols() {
		return cols;
	}

	// function to set the element at particular location in the matrix
	void set_Element(int i, int j, double val) {
		this.mat[i][j] = val;
	}

	// function to take entry in the matrix
	void get_Matrix() {
		for (int i = 0; i < this.rows; i++) {
			for (int j = 0; j < this.cols; j++) {
				System.out.print(String.format("%5.1f   ", mat[i][j]));
			}
			System.out.println();

		}
		System.out.println();
	}

	void add(Matrix mat2) {
		Matrix mat1 = this;

		if (mat1.getRows() == mat2.getRows() && mat1.getCols() == mat2.getCols()) {
			for (int i = 0; i < mat1.getRows(); i++) {
				for (int j = 0; j < mat1.getCols(); j++) {
					mat1.mat[i][j] = mat1.mat[i][j] + mat2.mat[i][j];
				}
			}
		} else
			System.out.println("Addition not possible");
	}

	void sub(Matrix mat2) {
		Matrix mat1 = this;

		if (mat1.getRows() == mat2.getRows() && mat1.getCols() == mat2.getCols()) {
			for (int i = 0; i < mat1.getRows(); i++) {
				for (int j = 0; j < mat1.getCols(); j++) {
					mat1.mat[i][j] = mat1.mat[i][j] - mat2.mat[i][j];
				}
			}
		} else
			System.out.println("Subtraction not possible");
	}

	static void mul(Matrix mat1, Matrix mat2) {

		double sum;
		if (mat1.getCols() == mat2.getRows()) {
			Matrix ans = new Matrix(mat1.getRows(), mat2.getCols());
			for (int i = 0; i < mat1.getCols(); i++) {
				for (int j = 0; j < mat1.getCols(); j++) {
					sum = 0;
					for (int k = 0; k < mat1.getCols(); k++) {
						sum = sum + mat1.mat[i][k] * mat2.mat[k][j];
						ans.mat[i][j] = sum;
					}
				}
			}
			ans.get_Matrix();
		} else {
			System.out.println("Multiplication not possible");

		}

	}

	// Constructors
	public Matrix() {
		rows = cols = 3;
		mat = new double[rows][cols];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++) {
				if (i == j)
					mat[i][j] = 1;
				else
					mat[i][j] = 0;
			}
	}

	public Matrix(int r, int c) {
		rows = r;
		cols = c;
		mat = new double[rows][cols];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++) {
				mat[i][j] = 0;
			}
	}

	public Matrix(int r, int c, float val) {
		rows = r;
		cols = c;
		mat = new double[rows][cols];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++) {
				mat[i][j] = val;
			}

	}
}
