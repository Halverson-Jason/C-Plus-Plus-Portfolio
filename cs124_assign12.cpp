/***********************************************************************
* Program:
*    Assignment 12, Input & Variables
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary: 
*     Program that prompts the user for his or her income and displays the result on the screen. 
*
*    Estimated:  0.5 hrs   
*    Actual:     0.25 hrs
*      Submiting code
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Get users income
 * Display income on screen
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed); // no scientific notation except for the deficit 
   cout.setf(ios::showpoint); // always show the decimal point 
   cout.precision(2); // two decimals for cents

   double income;
   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "Your income is: $ " << setw(8) << income << endl;
   return 0;
}
