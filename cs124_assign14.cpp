/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      Tried to return a string when I should have returned an int
************************************************************************/

#include <iostream>

using namespace std;

/**********************************************************************
* Function Prototypes
***********************************************************************/
void questionPeter();
int responseLord();

/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}

/**********************************************************************
* Function Declarations
***********************************************************************/

void questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me, and I forgive"
      << " him?\nTill seven times?\n";
   return ;
}

int responseLord()
{
   int response = 490;
   return response;
}