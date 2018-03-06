/***********************************************************************
* Program:
*    Project 04, MONTHLY BUDGET
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
*    Actual:     2.0 hrs
*      Setup of all tax calculations
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

#define BRACKET_1_MIN 0
#define BRACKET_1_MAX 15100
#define BRACKET_1_TAX 0.10
#define BRACKET_1_TAX_ADDITION 0
#define BRACKET_2_MIN 15100
#define BRACKET_2_MAX 61300
#define BRACKET_2_TAX 0.15
#define BRACKET_2_TAX_ADDITION 1510
#define BRACKET_3_MIN 61300
#define BRACKET_3_MAX 123700
#define BRACKET_3_TAX 0.25
#define BRACKET_3_TAX_ADDITION 8440
#define BRACKET_4_MIN 123700
#define BRACKET_4_MAX 188450
#define BRACKET_4_TAX 0.28
#define BRACKET_4_TAX_ADDITION 24040
#define BRACKET_5_MIN 188450
#define BRACKET_5_MAX 336550
#define BRACKET_5_TAX 0.33
#define BRACKET_5_TAX_ADDITION 42170
#define BRACKET_6_MIN 336550
#define BRACKET_6_TAX 0.35
#define BRACKET_6_TAX_ADDITION 91043

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
   double yearlyIncome = monthlyIncome * 12;
   double yearlyTax;

   if ((yearlyIncome > BRACKET_1_MIN) && (yearlyIncome < BRACKET_1_MAX))
   {
      yearlyTax = BRACKET_1_TAX_ADDITION + BRACKET_1_TAX * (yearlyIncome -
         BRACKET_1_MIN);
      return yearlyTax  / 12;
   }

   else if ((yearlyIncome > BRACKET_2_MIN) && (yearlyIncome < BRACKET_2_MAX))
   {
      yearlyTax = BRACKET_2_TAX_ADDITION + BRACKET_2_TAX * (yearlyIncome -
         BRACKET_2_MIN);
      return yearlyTax / 12;
   }

   else if ((yearlyIncome > BRACKET_3_MIN) && (yearlyIncome < BRACKET_3_MAX))
   {
      yearlyTax = BRACKET_3_TAX_ADDITION + BRACKET_3_TAX * (yearlyIncome -
         BRACKET_3_MIN);
      return yearlyTax / 12;
   }

   else if ((yearlyIncome > BRACKET_4_MIN) && (yearlyIncome < BRACKET_4_MAX))
   {
      yearlyTax = BRACKET_4_TAX_ADDITION + BRACKET_4_TAX * (yearlyIncome -
         BRACKET_4_MIN);
      return yearlyTax / 12;
   }

   else if ((yearlyIncome > BRACKET_5_MIN) && (yearlyIncome < BRACKET_5_MAX))
   {
      yearlyTax = BRACKET_5_TAX_ADDITION + BRACKET_5_TAX * (yearlyIncome -
         BRACKET_5_MIN);
      return yearlyTax / 12;
   }

   else if (yearlyIncome > BRACKET_6_MIN)
   {
      yearlyTax = BRACKET_6_TAX_ADDITION + BRACKET_6_TAX * (yearlyIncome -
         BRACKET_6_MIN);
      return yearlyTax / 12;
   }
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
      << budgetedTax << setw(5) << "$" << setw(11)
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
