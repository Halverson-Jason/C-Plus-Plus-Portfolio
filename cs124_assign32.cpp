/***********************************************************************
* Program:
*    Assignment 32, Strings
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary:
*    Traversing a string (or any other type of array for that matter) 
* is a common programming task. This assignment is the first part in a 
* two-part series (the other is Assignment 3.5) where we will learn 
* different techniques for visiting every member of a string. Your 
* assignment is to write the function countLetters() then a driver 
* program to test it.

*  countLetters()
* Write a function to return the number of letters in a string. This 
* involves traversing the string using the array notation (with an 
* index as we have been doing all semester). We will re-write this 
* function in Assignment 3.5 to do the same thing using a pointer.
*    Estimated:  0.5 hrs
*    Actual:     0.5 hrs
*      Testing function
************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int countLetters(char myString[], char myChar);


int main()
{
   char myStringArray[256];
   char myLetter;
   int letterCount;

   cout << "Enter a letter: ";
   cin >> myLetter;
   cout << "Enter text: ";
   cin.ignore();
   cin.getline(myStringArray, 256);

   letterCount = countLetters(myStringArray, myLetter);

   cout << "Number of '" << myLetter << "'s: " << letterCount << endl;

   return 0;
}

/**********************************************************************
* Write a function to return the number of letters in a string. This 
* involves traversing the string using the array notation (with an 
* index as we have been doing all semester). We will re-write this 
* function in Assignment 3.5 to do the same thing using a pointer.
 ***********************************************************************/
int countLetters(char myString[], char myChar)
{
   int count;
   for(int i = 0; myString[i]; i++)
   {
      if(myString[i] == myChar)
      {
         count++;
      }
   }

   return count;
}

