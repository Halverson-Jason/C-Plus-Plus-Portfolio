/***********************************************************************
* Program:
*    Assignment 16, IF STATEMENTS
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary:
*    Write a function (computeTax()) to determine which tax bracket a user is in.
*    The yearly income is passed as a parameter to the function. The function
*    returns the percentage bracket that the user's income falls in.

*
*    Estimated:  0.5 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

#define BRACKET_1_MIN 0
#define BRACKET_1_MAX 15100
#define BRACKET_1_TAX 10
#define BRACKET_2_MIN 15100
#define BRACKET_2_MAX 61300
#define BRACKET_2_TAX 15
#define BRACKET_3_MIN 61300
#define BRACKET_3_MAX 123700
#define BRACKET_3_TAX 25
#define BRACKET_4_MIN 123700
#define BRACKET_4_MAX 188450
#define BRACKET_4_TAX 28
#define BRACKET_5_MIN 188450
#define BRACKET_5_MAX 336550
#define BRACKET_5_TAX 33
#define BRACKET_6_MIN 336550
#define BRACKET_6_TAX 35


// yearly income is passed (long) , percentage bracket(int) returned

int computeTax(long yearlyIncome);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   long yearlyIncome;

   cout << "Income: ";
   cin >> yearlyIncome;
   cout << "Your tax bracket is " << computeTax(yearlyIncome) << "%" << endl;

   return 0;
}

/**********************************************************************
 * yearly income is passed (long) , percentage bracket(int) returnedt
 * Evalutates bracket through if statements
 ***********************************************************************/
 int computeTax(long yearlyIncome)
{
   if((yearlyIncome > BRACKET_1_MIN) && (yearlyIncome < BRACKET_1_MAX))
   {
      return BRACKET_1_TAX;
   }

   else if((yearlyIncome > BRACKET_2_MIN) && (yearlyIncome < BRACKET_2_MAX))
   {
      return BRACKET_2_TAX;
   }

   else if((yearlyIncome > BRACKET_3_MIN) && (yearlyIncome < BRACKET_3_MAX))
   {
      return BRACKET_3_TAX;
   }

   else if((yearlyIncome > BRACKET_4_MIN) && (yearlyIncome < BRACKET_4_MAX))
   {
      return BRACKET_4_TAX;
   }

   else if((yearlyIncome > BRACKET_5_MIN) && (yearlyIncome < BRACKET_5_MAX))
   {
      return BRACKET_5_TAX;
   }

   else if(yearlyIncome > BRACKET_6_MIN)
   {
      return BRACKET_6_TAX;
   }
}
