/***********************************************************************
* Program:
*    Project 03, MONTHLY BUDGET
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
*    Actual:     1.5 hrs
*      writing all the functions
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
* Prototype functions
***********************************************************************/
void getIncome(double &monthlyIncome);
void getBudgetLiving(double &budgetedLivingExpenses);
void getActualLiving(double &actualLivingExpenses);
void getActualOther(double &actualOtherExpenses);
void getActualTithing(double &actualTithe);
void getActualTax(double &actualTaxes);
double computeTax(double &monthlyIncome);
double computeTithing(double &monthlyIncome);
void display(double &monthlyIncome, double &actualTaxes, 
   double actualTithe, double &budgetedLivingExpenses, 
   double &actualLivingExpenses, double &actualOtherExpenses);

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
   double monthlyIncome;
   double budgetedLivingExpenses;
   double actualLivingExpenses;
   double actualTaxes;
   double actualTithe;
   double actualOtherExpenses;

    // greeting
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";

   // Functions
   getIncome(monthlyIncome);
   getBudgetLiving(budgetedLivingExpenses);
   getActualLiving(actualLivingExpenses);
   getActualTax(actualTaxes);
   getActualTithing(actualTithe);
   getActualOther(actualOtherExpenses);
   display(monthlyIncome,actualTaxes, actualTithe, budgetedLivingExpenses, 
      actualLivingExpenses, actualOtherExpenses);
   
   return 0;
}
/**********************************************************************
* Prompts user for monthly income 
* Updates the monthly income variable pointer
***********************************************************************/
void getIncome(double &monthlyIncome)
{
   cout << "\tYour monthly income: ";
   cin >> monthlyIncome;
   return;
}
/**********************************************************************
* Prompts user for budgeted living expenses
* Updates the variable pointer
***********************************************************************/
void getBudgetLiving(double &budgetedLivingExpenses)
{
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetedLivingExpenses;
   return;
}
/**********************************************************************
* Prompts user for actual living expenses
* Updates the variable pointer
***********************************************************************/
void getActualLiving(double &actualLivingExpenses)
{
   cout << "\tYour actual living expenses: ";
   cin >> actualLivingExpenses;
   return;
}
/**********************************************************************
* Prompts user for actual other expenses
* Updates the variable pointer
***********************************************************************/
void getActualOther(double &actualOtherExpenses)
{
   cout << "\tYour actual other expenses: ";
   cin >> actualOtherExpenses;
   return;
}
/**********************************************************************
* Prompts user for actual tithing
* Updates the variable pointer
***********************************************************************/
void getActualTithing(double &actualTithe)
{
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithe;
   return;
}
/**********************************************************************
* Prompts user for actual taxes
* Updates the variable pointer
***********************************************************************/
void getActualTax(double &actualTaxes)
{
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTaxes;
   return;
}
/**********************************************************************
* Receives pointer for monthly income
* Calculates taxes and returns a double
***********************************************************************/
double computeTax(double &monthlyIncome)
{
   return 0.0;
}
/**********************************************************************
* Receives pointer to monthly income
* Calculates tithing of 10% and returns a double
***********************************************************************/
double computeTithing(double &monthlyIncome)
{
   return monthlyIncome * .10;
}
/**********************************************************************
* receive all information gathered, computes tithing and taxes and 
* displays information in desired console output
***********************************************************************/
void display(double &monthlyIncome, double &actualTaxes, 
   double actualTithe, double &budgetedLivingExpenses, 
   double &actualLivingExpenses, double &actualOtherExpenses)
{
   // call computeTithing  and computeTax
   double budgetedTithing = computeTithing(monthlyIncome);
   double budgetedTax = computeTax(monthlyIncome);
   // calculate the budgeted other expenses
   double budgetOther = monthlyIncome - budgetedTax - budgetedTithing - 
      budgetedLivingExpenses;
   // calculate the actual difference
   double actualDifference = monthlyIncome - actualTaxes - actualTithe - 
      actualLivingExpenses - actualOtherExpenses;
   // set the budgeted difference
   double budgetDifference = 0;
   // display all gathered information
   cout << "\nThe following is a report on your monthly expenses\n";
   cout << "\tItem" << setw(24) << "Budget" << setw(17) << "Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome" << setw(11) << "$" << setw(11) << monthlyIncome
      << setw(5) << "$" << setw(11) << monthlyIncome << endl;

   cout << "\tTaxes" << setw(12) << "$" << setw(11)
      << "0.00" << setw(5) << "$" << setw(11)
      << actualTaxes << endl;

   cout << "\tTithing" << setw(10) << "$" << setw(11)
      << budgetedTithing << setw(5) << "$" << setw(11)
      << actualTithe << endl;

   cout << "\tLiving" << setw(11) << "$" << setw(11)
      << budgetedLivingExpenses << setw(5) << "$" << setw(11)
      << actualLivingExpenses << endl;

   cout << "\tOther" << setw(12) << "$" << setw(11)
      << budgetOther << setw(5) << "$" << setw(11)
      << actualOtherExpenses << endl;

   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference" << setw(7) << "$" << setw(11)
      << budgetDifference << setw(5) << "$" << setw(11)
      << actualDifference << endl;

}