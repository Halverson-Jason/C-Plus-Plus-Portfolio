/***********************************************************************
* Program:
*    Checkpoint 02a, Exceptions 
*    Brother Alvey, CS165
* Author:
*    Jason Halverson
* Summary: 
*    Write a C++ program that prompts the user for a positive even 
*    number, less than 100. If the user enters a number that is not 
*    valid, an exception message should be thrown from one function, 
*    caught in another and displayed to the user
*
*    Estimated:  0.5 hrs   
*    Actual:     0.05 hrs
*      Throwing the error in one function and catching in another
************************************************************************/

#include <iostream>
#include <string>

using namespace std;

// prompt for user input
int prompt() throw(string);

/**********************************************************************
 * Calls the prompt() function
 * catches any error from said funciton.
 ***********************************************************************/
int main()
{
   try
   {
      cout << "The number is " << prompt() << "." << endl;
   }
   
   catch (string message)
   {
      cout << "Error: " << message;
   }
   return 0;
}

/**********************************************************************
* Get a number from user
* validate number is an possitive even number and less than 100
***********************************************************************/
int prompt() throw(string)
{
   int userNumber;
   cout << "Enter a number: ";
   cin >> userNumber;

  
      if (userNumber < 0)
      {
         throw string("The number cannot be negative.\n");
      }
      else if (userNumber > 100)
      {
         throw string("The number cannot be greater than 100.\n");
      }
      else if (userNumber % 2)
      {
         throw string("The number cannot be odd.\n");
      }
   return userNumber;
}