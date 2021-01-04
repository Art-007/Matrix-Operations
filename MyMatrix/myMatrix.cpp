#include "myMatrix.h"

myMatrix::myMatrix() {

	row = m;
	col = n;
	// intilaizing the matrix 
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat_array[i][j] = 0;
		}
	}
}
// construction 
myMatrix::myMatrix(float mat[m][n], int r, int c) {

	row = r;
	col = c;
	// costroctor 
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat_array[i][j] = mat[i][j];
		}
	}
	
}

// overwrite method my matrix 
void myMatrix::overwriting(float mat[m][n], int r, int c) {

	row = r;
	col = c;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat_array[i][j] = mat[i][j];
		}
	}
	
}

// display the matrixes 
void myMatrix::print() {
	for (int i = 0; i < col; i++) 
	{
		cout << "[";

		for (int j = 0; j < row; j++)
		{
			cout << mat_array[i][j] <<  " " ;
		}
		cout << "] \n" ;
	}
} 
myMatrix myMatrix::Addtion(myMatrix m2) {

	float new_mat[m][n]; //  temp varibales to hold the additon matrix 

	for (int i = 0; i < m; i++)
	{
		// 2nd row 
		for (int j = 0; j < n; j++)
		{
			// adding mattrix 1 and matrix 2 and a new mattrix is created 
			new_mat[i][j] = mat_array[i][j] + m2.mat_array[i][j];

			// n= 2,  first row 00, 01, 10,11
		}
	}

	myMatrix main_mat(new_mat, row, col); //  new matrix to be used on main

	return main_mat;  // return the matric to be done on the main 
}

myMatrix myMatrix::Subtraction(myMatrix m2) {

	float new_mat[m][n];  // new varibale for new matric after the operation is done 

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// subtracting mattrix 1 and matrix 2 and a new mattrix is created 
			new_mat[i][j] = mat_array[i][j] - m2.mat_array[i][j];
		}
	}
	myMatrix main_mat(new_mat, row, col); //  new matrix to be used on main 

	return main_mat; // return the matric to be done on the main 
}

// passing a number x to be multpliy to scale the matrix 
myMatrix myMatrix::Scal_Multi(int x) {

	float new_mat[m][n];   // new varibale for new matric after the operation is done 

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// mattrix 1 and matrix 2 and a new mattrix is created 
			new_mat[i][j] = mat_array[i][j] * x;   // we just mutlply the number to multi the mat array
		}
	}

	myMatrix main_mat(new_mat, row, col); //  new matrix to be used on main

	return main_mat; // return the matric to be done on the main 
}

myMatrix myMatrix::Multiplication(myMatrix m2) {

	myMatrix multi_mat; //  creating new empty object to hold the new mattrix 
	if( row == m2.col)  // one of the matrix rules are that 
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < m2.col; j++) 
			{
				multi_mat.mat_array[i][j] = 0;   // initilaize the new crated object to zero 

				for (int x = 0; x < m2.col; x++) 
				{
					// we find the mutplication 
					multi_mat.mat_array[i][j] += mat_array[i][x] * m2.mat_array[x][j] ;
				}
			}
		}
		multi_mat.col = col;  // multi_mat has the same col as m1 matrix 

		multi_mat.row = m2.row; // multi_mat has the same row size as m2 
		
	}
	return multi_mat;   // return the multiplication matrix 
}

//  rsie a matrix to a power, if matric A need to be A^2, we can just mutiply it self
// using this logic we can use a for loop with two 
myMatrix myMatrix::Pow(int pow)
{
	//  we are crating two object matrixes 
	myMatrix power_mat_1(mat_array, row, col);
	myMatrix power_mat_2(mat_array, row, col);

	//  for find the power matrix 
	for (int i = 1; i < pow; i++)
	{
		power_mat_2 = power_mat_2.Multiplication(power_mat_1);
	}
	return power_mat_2;  // return the new power matric we found in the loop 
}

//  doing the invarse and determinant 
myMatrix myMatrix::Inverse()
{
	myMatrix temp(mat_array, m, n);
	double det = temp.Determinant();
	myMatrix temp2;
	if (det != 0)
	{
		if (m == 3)
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					temp.mat_array[i][j] = ((mat_array[(j + 1) % m][(i + 1) % n] * mat_array[(j + 2) % m][(i + 2) % n]) - (mat_array[(j + 1) % m][(i + 2) % n] * mat_array[(j + 2) % m][(i + 1) % n])) / Determinant();
			}
			return temp;
		}
		else if (m == 2) {
			temp.mat_array[0][0] = mat_array[1][1];
			temp.mat_array[1][0] = -mat_array[1][0];
			temp.mat_array[0][1] = -mat_array[0][1];
			temp.mat_array[1][1] = mat_array[0][0];
			temp2 = temp.Scal_Multi(1 / det);
		}
	}
	return temp2;

}

// doing the determinant 
float myMatrix::Determinant()
{
	double det = 1;

	// operations rows for i = 0... n - 2
	for (int i = 0; i < n - 1; i++)
	{
		// finding the row below with largest element in column i
		int r = i;
		double maxA = abs(mat_array[i][i]);
		for (int k = i + 1; k < n; k++)
		{
			double val = abs(mat_array[k][i]);
			if (val > maxA)
			{
				r = k;
				maxA = val;
			}
		}
		if (r != i)
		{
			for (int j = i; j < n; j++) swap(mat_array[i][j], mat_array[r][j]);
			det = -det;
		}

		double pivot = mat_array[i][i];
		if (abs(pivot) < 1.0E-30) return 0.0;        // Singular matrix

		for (int r = i + 1; r < n; r++)             // On lower rows
		{
			double multiple = mat_array[r][i] / pivot;                // Multiple of row in to clear elements in the column
			for (int j = i; j < n; j++) mat_array[r][j] -= multiple * mat_array[i][j];
		}
		det *= pivot;                                        // Determinant is product of diagonal
	}

	det *= mat_array[n - 1][n - 1];

	return det;
}





