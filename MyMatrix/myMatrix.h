#include <iostream>
using namespace std;

//  global variables of mxn matrixes 
const int m = 2, n = 2;

//  my class matrix
// part A
class myMatrix {

public:
	float mat_array[m][n];
	int col;
	int row;

public:
	// constuctors 
	myMatrix();
	myMatrix(float mat[m][n], int row, int col); // alows to assing doemthing to privates 
	void overwriting(float mat[m][n], int row, int col);
	void print(); //  display matrix 

	// Part B
	myMatrix Addtion(myMatrix m2);
	myMatrix Subtraction(myMatrix m2);
	myMatrix Scal_Multi(int x);

	// part C
	myMatrix Multiplication(myMatrix m2);

	//  part g
	myMatrix Pow(int pow);

	// part d  // hard time with this ones but I tried 
	float Determinant();
	myMatrix Inverse();


	//  overloading operators to return operations done to main
	myMatrix operator-(myMatrix& m2) {return Subtraction(m2);}
	myMatrix operator+(myMatrix& m2) {return Addtion(m2);}
	myMatrix operator^(int& pow) {return Pow(pow);}
	myMatrix operator*(int& x) {return Scal_Multi(x);}
	myMatrix operator*(myMatrix& m2) {return Multiplication(m2);}
};
