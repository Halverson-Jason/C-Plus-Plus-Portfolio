/***********************************************************************
* Program:
*    Checkpoint 03b, CHECKPOINT B 
*    Brother Alvey, CS165
* Author:
*    Jason Halverson
* Summary: 
*    Write a C++ program that prompts the user for a number, but if the 
*    user enters a word instead, the program handles it gracefully and 
*    re-prompts for a number.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.05 hrs
*      Throwing the error in one function and catching in another
************************************************************************/

#include <iostream>
#include <string>

using namespace std;

// prompt for user input
int prompt();

/**********************************************************************
 * Calls the prompt() function
 * displays validaded input.
 ***********************************************************************/
int main()
{
   int userNumber = prompt();
   cout << "The number is " << userNumber << "." << endl;
   
   return 0;
}

/**********************************************************************
* Get a number from user
* validate number is an integer
***********************************************************************/
int prompt()
{
   int userNumber;
   
   cout << "Enter a number: ";
   cin >> userNumber;
  
      while (cin.fail())
      {
         cout << "Invalid input.\n";
         cin.clear();
         cin.ignore(256, '\n');
         cout << "Enter a number: ";
         cin >> userNumber;
      }

   return userNumber;
}