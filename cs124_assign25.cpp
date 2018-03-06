/***********************************************************************
* Program:
*    Assignment 25, LOOP DESIGN
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary:
*    Write a function (displayTable()) to display a calendar on the 
*    screen. The function will take two parameters:
*    numDays: The number of days in a month.
*    offset: The offset from Monday. If the offset is zero, then the 
*    month starts on Monday. If the offset is 2, the month starts on 
*    Wednesday. If the offset is 6, the month starts on Sunday.
*    Estimated:  0.5 hrs
*    Actual:     0.1 hrs
*      Already completed this for Calendar project. Hardest part was
*      not displaying if the offset was greater that 7.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

void displayTable(int offset, int numDays);

int main()
{
   int numDays;
   int offset;
   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;
   displayTable(offset, numDays); 
   return 0;
}
/**********************************************************************
 * take the number of days in a month (numDays) and the offset (offset) 
 * as parameters and will display the calendar table
 ***********************************************************************/
void displayTable(int offset, int numDays)
{

   // set to -1 to compensate for first week offset
   int weekDayCounter = -1;

   cout << setw(4) << "Su" << setw(4) << "Mo" << setw(4) << "Tu" 
      << setw(4) << "We" << setw(4) << "Th" << setw(4) << "Fr" << setw(4) 
      << "Sa" << endl;

      // count offset
   if (offset < 6)
   {
      for (int i = 0; i <= offset; i++)
      {
         cout << setw(4) << "  ";
         weekDayCounter++;
      }
   }


   // start counting days of month
   for (int i = 1; i <= numDays; i++)
   {
      if (weekDayCounter >= 6)
      {
         cout << endl << setw(4) << i;
         weekDayCounter = 0;
      }
      else
      {
         cout << setw(4) << i;
         ++weekDayCounter;
      }

      
   }
   
   cout << endl;
}