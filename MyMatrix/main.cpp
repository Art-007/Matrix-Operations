// Question_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "myMatrix.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	float m1[m][n] = { {1, 1},
					   {1, 0} };

	float m2[m][n] = { {2, 1},
					   {1, 0} };

	myMatrix a (m1, m, n); // one object 
	myMatrix b(m2, m, n); // 2nd object 	
	
	// matrix A
	float mA[m][n] = { {1, 1},
					   {1, 0} };
	// matrix B
	float mB[m][n] = { {1, 1},
					   {0, 1} };
	// matrix C
	float mC[m][n] = { {1, 1},
					   {1, 1} };


	cout << "Matrix A: " << endl;
	myMatrix matA(mA, m, n);
	matA.print();
	cout << endl << "Matrix B: " << endl;
	myMatrix matB(mB, m, n);
	matB.print();

	cout << endl << "Matrix C: " << endl;
	myMatrix matC(mC, m, n);
	matC.print();

	
	cout << endl << "Part B " << endl;
	cout << endl << "Addition" << endl;
	cout << "Creating matrix D by adding  Matrix A  and  Matrix B " << endl;
	myMatrix matD = matA + matB;
	matD.print();

	cout << endl << "Subtraction" << endl;
	cout << "Creating matrix F by subtracting  Matrix A  and  Matrix C " << endl;
	myMatrix matF = matA - matC;
	matF.print();

	int x;
	cout << endl << "Enter a constant to sclare matrix A" << endl;
	cin >> x;
	cout << endl << "Sacalar Multiplication" << endl;
	cout << "Creating matrix G by Sacalar Multiplication Matrix A  " << endl;
	myMatrix matG = matA * x;
	matG.print();


	cout << endl << "Part C ";
	cout << endl << "Multiplication" << endl;
	cout << "Creating matrix H by Multiplication Matrix C and Matrix B " << endl;
	myMatrix matH = matC * matB;
	matH.print();

	int y;
	cout << endl << "Powers Part ";
	string answer = " " ;
	do {
		cout << endl << "Enter a power to raise matrix A " << endl;
		cin >> y;
		cout << endl << "Power" << endl;
		cout << " Doing Matrix A to the power of " << y << endl;
		myMatrix matE = matA ^ y;
		matE.print();
		cout << "Enter yes to do another power to matrix A or no to stop:  ";
		cin >> answer;
	} while (answer != "no");

	int z;
	string answer_1 = " ";
	do {
		cout << endl << "Enter a power to raise matrix B " << endl;
		cin >> z;
		cout << endl << "Power" << endl;
		cout << " Doing Matrix B to the power of " << y << endl;
		myMatrix matJ = matB ^ z;
		matJ.print();
		cout << "Enter yes to do another power to matrix B or no to stop:  ";
		cin >> answer_1;
	} while (answer_1 != "no");


	int w;
	string answer_2 = " ";
	do {
		cout << endl << "Enter a power to raise matrix C " << endl;
		cin >> w;
		cout << endl << "Power" << endl;
		cout << " Doing Matrix C to the power of " << w << endl;
		myMatrix matK = matC ^ w;
		matK.print();
		cout << "Enter yes to do another power to matrix C or no to stop:  ";
		cin >> answer_2;
	} while (answer_2 != "no");

	
	//  These two parts the detrminate and the invarse 
	cout << endl << "Part D" << endl;
	cout <<  "Finding the determinant of B " << endl;
	cout << " The Determinate for B  = "
	<< matB.Determinant() << endl;

	cout << endl << "Part E" << endl;
	cout << "Finding the inverse " << endl;
	cout << "Finding the inverse of A " << endl;
	myMatrix matL = matA.Inverse();
	matL.print();
	
	return 0;
}