/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary: 
*    Create a calendar for any month of any year from 1753 forward. 
*    This is similar to the cal utility on the Linux system. Prompt 
*    the user for the numeric month and year to be displayed as shown 
*    in the example below. Your calculations to determine the first day 
*    of the month shall start with January 1, 1753 as a Monday. This 
*    will also include leap years.
*
*    Estimated:  2.0 hrs   
*    Actual:     3.0 hrs
*      writing the display function , along with setting up the offset
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

#define BEGGINING_YEAR 1753
#define DAYS_IN_YEAR 365
#define DAYS_IN_LEAP_YEAR 366
#define JANUARY 31
#define FEBRUARY 28
#define MARCH 31
#define APRIL 30
#define MAY 31
#define JUNE 30
#define JULY 31
#define AUGUST 31
#define SEPTEMBER 30
#define OCTOBER 31
#define NOVEMBER 30
#define DECEMBER 31

#define SUNDAY 6
#define MONDAY 0
#define TUESDAY 1
#define WEDNESDAY 2
#define THURSDAY 3
#define FRIDAY 4
#define SATURDAY 5

// functions
void promptMonth(int &month);
bool validateMonth(int &month);
void promptYear(int &year);
bool validateYear(int &year);

int computeOffSet(int year, int month, int daysInMonths[]);

int numDaysInYear(int &year);
int numDaysInMonth(int &year, int month, int daysInMonths[]);

bool isLeapYear(int year);

void displayTable(int offset, int numDays);



/**********************************************************************
 * Initializes variable to be passed by reference and
 * prompts for month , prompts for year, calls display
 ***********************************************************************/
int main()
{
   int month;
   int year;
   int daysInMonths[] = {JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE,JULY,
      AUGUST,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER};
   string months[] = {"","January","February","March","April","May",
      "June","July","August","September","October","November","December"};
   int offset;
   int numDays;

   bool leapYear;
   int leapYearCount;
   int daysInMonth;
   int daysSinceBeggining;

   promptMonth(month);
   promptYear(year);
   numDays = numDaysInMonth(year, month, daysInMonths);
   offset = computeOffSet(year, month, daysInMonths);
   cout << months[month] << ", " << year << endl;
   displayTable(offset, numDays);

   return 0;
}

/**********************************************************************
 * retrieves input from user to set month. Passes value to validateMonth
 * if not a month re-prompts
 ***********************************************************************/
void promptMonth(int &month)
{
   do
   {
      cout << "Enter a month number: ";
      cin >> month;
       
   }while (!validateMonth(month));

}

/**********************************************************************
 * validates month 
 * If not in between 1-12 returns false
 ***********************************************************************/
bool validateMonth(int &month)
{


   if ((month >= 1) && (month <= 12))
   {
      return true;
   }
   
   else
   {
      cout << "Month must be between 1 and 12.\n";
      return false;
   }
   
}

/**********************************************************************
 * retrieves input from user to set year. Passes value to validateYear
 * if not validated re-prompt
 ***********************************************************************/
void promptYear(int &year)
{
   do
   {
      cout << "Enter year: ";
      cin >> year;
   } while (!validateYear(year));
   cout << endl;

}

/**********************************************************************
 * validates year
 * If not greater than 1953 return false.
 ***********************************************************************/
bool validateYear(int &year)
{
   if (year >= BEGGINING_YEAR)
   {
      return true;
   }
   
   else
   {
      cout << "Year must be 1753 or later.\n";
      return false;
   }
   
}

/**********************************************************************
 * computes offset between 1753 and current year / month
 * returns the modulus of 7 to get offset
 ***********************************************************************/
int computeOffSet(int year, int month, int daysInMonths[])
{
   int numDays = 0;
   int offset = 0;

   for (int i = BEGGINING_YEAR; i < year; i++)
   {
      numDays += numDaysInYear(i);
   }

   for (int j = 1; j < month; j++)
   {
      numDays += numDaysInMonth(year, j, daysInMonths);
   }

   offset = numDays % 7 ;
   return offset;

}

/**********************************************************************
 * computes number of days in a year
 * Calls isLeapYear to verify if it should be 366 days
 ***********************************************************************/
int numDaysInYear(int &year)
{
   bool x = isLeapYear(year);

   if (x)
   {
      return DAYS_IN_LEAP_YEAR;
   }

   else
   {
      return DAYS_IN_YEAR;
   }
}

/**********************************************************************
 * computes number of days in a given month
 *  if leap year february returns 29 if not 28
 ***********************************************************************/
int numDaysInMonth(int &year, int month, int daysInMonths[])
{
   month -= 1;

   if (isLeapYear(year) && (month == 1))
   {
      return daysInMonths[month] + 1;
   }
   else
   {
      return daysInMonths[month];
   }
}

/**********************************************************************
 * computes if a year is a leap year
 * returns true / false
 ***********************************************************************/
bool isLeapYear(int year)
{
   if ( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) )
   {
      return true;
   }

   else
   {
      return false;
   }
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