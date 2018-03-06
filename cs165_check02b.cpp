/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Alvey, CS165
* Author:
*    Jason Halverson
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

// TODO: Define your Complex struct here
struct Complex {
	double realNumber;
	double imaginaryNumber;
};

// TODO: Add your prompt function here
void prompt(Complex & userNumber)
	{
		cout << "Real: ";
		cin >> userNumber.realNumber;
		cout << "Imaginary: ";
		cin >> userNumber.imaginaryNumber;
	}

// TODO: Add your display function here
void display(Complex & userNumber) 
	{
	cout << userNumber.realNumber << " + " << userNumber.imaginaryNumber << "i";
	}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex & x, const Complex & y)
{
   // TODO: Fill in the body of the add function
	Complex z;
	z.realNumber = x.realNumber + y.realNumber;
	z.imaginaryNumber = x.imaginaryNumber + y.imaginaryNumber;
	return z;
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
	Complex c1, c2;


   // Call your prompt function twice to fill in c1, and c2 
	prompt(c1);
	prompt(c2);

   // Declare another Complex for the sum
	Complex sum;

   // Call the addComplex function, putting the result in sum;
	sum = addComplex(c1, c2);
 
   cout << "\nThe sum is: ";
   display(sum);
   cout << endl;
 
   return 0;
}


