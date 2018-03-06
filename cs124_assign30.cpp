/***********************************************************************
* Program:
*    Assignment 30, ARRAY SYNTAX
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary:
*    getGrades()
* Write a function to prompt the user for ten grades and return the 
* result back to main(). Note that any variables declared in getGrades() 
* will be destroyed when the function returns. This means that main() 
* will need to declare the array and pass it as a parameter to 
* getGrades().

*  averageGrades()
* Write another function to find the average of the grades and return 
* the answer. Of course, the grades array will need to be passed as a 
* parameter. The return value should be the average.
*    Estimated:  0.5 hrs
*    Actual:     0.5 hrs
*      Testing function
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

void getGrades(int grades[]);
float averageGrades(int grades[]);

int main()
{
   int grades[10];
   float average ;
   getGrades(grades);
   average = averageGrades(grades);

   if(average == -1)
   {
      cout << "Average Grade: ---%" << endl;
   }
   
   else
   {
      cout << "Average Grade: " << (int)(average + 0.5) << "%" << endl;
   }
   
   return 0;
}

/**********************************************************************
* Write a function to prompt the user for ten grades and return the 
* result back to main(). Note that any variables declared in getGrades() 
* will be destroyed when the function returns. This means that main() 
* will need to declare the array and pass it as a parameter to 
* getGrades().
 ***********************************************************************/
void getGrades(int grades[])
{
   for(int i = 0; i < 10; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> grades[i];
   }
   return;
}

/**********************************************************************
* Write another function to find the average of the grades and return 
* the answer. Of course, the grades array will need to be passed as a 
* parameter. The return value should be the average.
 ***********************************************************************/
float averageGrades(int grades[])
{
   float averageGrade = -1;
   int gradeCount = 0;
   for(int i = 0; i < 10; i++)
   {
      if(!(grades[i] == -1))
      {
         averageGrade += grades[i];
         gradeCount++;
      }
      
   }   

   if(averageGrade == -1)
   {
      return averageGrade;
   }

   else{
      return averageGrade = averageGrade / gradeCount ;
   }

}