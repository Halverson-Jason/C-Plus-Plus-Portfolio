/***********************************************************************
* Program:
*    Assignment 11, Output
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary: 
*    Display monthly budget.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      Lining up the dollar signs
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Display budget
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed); // no scientific notation except for the deficit 
   cout.setf(ios::showpoint); // always show the decimal point 
   cout.precision(2); // two decimals for cents!

   cout << "\tItem  " << setw(19) << "Projected\n";
   cout << "\t=============  ==========\n";
   cout << "\tIncome" << setw(10) << "$" << setw(9) << 1000.00 << endl;
   cout << "\tTaxes" << setw(11) << "$" << setw(9) << 100.00 << endl;
   cout << "\tTithing" << setw(9) << "$" << setw(9) << 100.00 << endl;
   cout << "\tLiving" << setw(10) << "$" << setw(9) << 650.00 << endl;
   cout << "\tOther" << setw(11) << "$" << setw(9) << 90.00 << endl;
   cout << "\t=============  ==========\n";
   cout << "\tDelta  " << setw(9) << "$" << setw(9) << 60.00 << endl;
   return 0;
}
