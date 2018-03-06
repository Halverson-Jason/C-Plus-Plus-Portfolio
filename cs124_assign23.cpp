/***********************************************************************
* Program:
*    Assignment 23, LOOP SYNTAX
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary:
*    Sue's silly brother Steve has a teacher who loves to give tons of 
*    math homework. This week, the assignment is to add all the multiples 
*    of 7 that are less than 100. Last week, he had to add all the 
*    multiples of 3 that are less than 100. Sue wants to make sure that 
*    her brother gets a 100% on each assignment so she decided to write 
*    a program to validate each assignment.
*
*    Estimated:  0.5 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

int main()
{
   int number;
   int multipleReturn = 0;

   cout << "What multiples are we adding? ";
   cin >> number;

   for(int i = 1; i < 100; i++)
   {
      if ((i % number) == 0)
      {
         multipleReturn += i ;
      }

   }
   cout << "The sum of multiples of " << number << " less than 100 are: " << multipleReturn << endl;

   return 0;
}