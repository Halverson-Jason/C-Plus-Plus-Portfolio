/***********************************************************************
* Program:
*    Project 02, MONTHLY BUDGET
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary: 
*    Program to manage your personal finances for a month. This program 
*    will ask user for a budget income and expenditures, then for how 
*    much the user actually made and spent. The program will then display
*    a report of whether the user is on target to meet their financial 
*    goals.
*
*    Estimated:  2.0 hrs   
*    Actual:     1.0 hrs
*      Commenting appropriately , not to vague not to in depth
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Display program entry text, prompt user for budget input and display
 * the budgeted and actual monthly expense information
 ***********************************************************************/
int main()
{
   // set cout properties
   cout.setf(ios::fixed); // no scientific notation 
   cout.setf(ios::showpoint); // always show the decimal point 
   cout.precision(2); // two digits for money

   // variable declarations
   float monthlyIncome;
   float budgetedLivingExpenses;
   float actualLivingExpenses;
   float actualTaxes;
   float actualTithe;
   float actualOtherExpenses;
   float unknownBudgetedExpenses = 0.00;

    // prompt user for information
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   cout << "\tYour monthly income: ";
   cin >> monthlyIncome;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetedLivingExpenses;
   cout << "\tYour actual living expenses: ";
   cin >> actualLivingExpenses;
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTaxes;
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithe;
   cout << "\tYour actual other expenses: ";
   cin >> actualOtherExpenses;

   // display budget information
   cout << "\nThe following is a report on your monthly expenses\n";
   cout << "\tItem" << setw(24) << "Budget" << setw(17) << "Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome" << setw(11) << "$" << setw(11) << monthlyIncome 
      << setw(5) << "$" << setw(11) << monthlyIncome << endl;

   cout << "\tTaxes" << setw(12) << "$" << setw(11) 
      << unknownBudgetedExpenses << setw(5) << "$" << setw(11) 
      << actualTaxes << endl;

   cout << "\tTithing" << setw(10) << "$" << setw(11) 
      << unknownBudgetedExpenses << setw(5) << "$" << setw(11) 
      << actualTithe << endl;

   cout << "\tLiving" << setw(11) << "$" << setw(11) 
      << budgetedLivingExpenses << setw(5) << "$" << setw(11) 
      << actualLivingExpenses << endl;

   cout << "\tOther" << setw(12) << "$" << setw(11) 
      << unknownBudgetedExpenses << setw(5) << "$" << setw(11) 
      << actualOtherExpenses << endl;

   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference" << setw(7) << "$" << setw(11) 
      << unknownBudgetedExpenses << setw(5) << "$" << setw(11) 
      << unknownBudgetedExpenses << endl;

   return 0;
}
