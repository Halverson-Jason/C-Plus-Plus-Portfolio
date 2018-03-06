/***********************************************************************
* Program:
*    Assignment 13, Expressions
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary: 
* Write a program to convert Fahrenheit to Celsius. This program will 
* prompt the user for the Fahrenheit number and convert it to Celsius. 
* The program will prompt the user for the temperature, compute the 
* Celsius value, and display the results.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      Setting up the initial program structure ( Heading , ect.)
************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

/**********************************************************************
 * Prompt user for input and convert from Fahrenheit to Celsius
 ***********************************************************************/
int main()
{
   cout.precision(0);

   int tempFahrenheit;
   int tempCelsius;

   cout << "Please enter Fahrenheit degrees: ";
   cin >> tempFahrenheit;

   tempCelsius = round(5.0 / 9.0 * (tempFahrenheit - 32.0));

   cout << "Celsius: " << tempCelsius << endl;

   return 0;
}
