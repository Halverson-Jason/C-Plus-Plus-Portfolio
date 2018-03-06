/***********************************************************************
* Program:
*    Assignment 26, FILES
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary:
*    Please write a program to read 10 grades from a file and display 
*    the average. This will include the functions getFileName(), 
*    displayAverage() and readFile():
*    Estimated:  0.5 hrs
*    Actual:     0.5 hrs
*      Typecasting and rounding.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

float readFile(char fileName[]);
void getFileName(char fileName[]);
void display(float average);

int main()
{
   char fileName[256];
   float average;

   getFileName(fileName);
   average = readFile(fileName);
   display (average);

   return 0;
}

/**********************************************************************
 * This function will read the file and return the average score of the 
 * ten values.
 ***********************************************************************/
float readFile(char fileName[])
{
   float average;
   float sum;
   float grade;
   int numGrades = 0;
   //Error reading file "grades.txt"
   ifstream fin(fileName);

   if (fin.fail())                             
   {
      // inform user of the error
      cout << "Error reading file \"" << fileName << "\"" << endl;
      return -1;                   
   } 

   // read data from file and calculate the average
   while (fin >> grade) 
   {
      sum += grade;
      numGrades++;
   }

   fin.close(); 

   average = sum / numGrades;

   if(numGrades != 10)
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      return -1;
   }

   else
   {
      return average;
   }


}

/**********************************************************************
 * This function get the filename
 * to read grades.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
}

/**********************************************************************
 * This function will display the average score to zero decimals 
 * of accuracy (rounded)
 ***********************************************************************/
void display(float average)
{
   if (average != -1)
   {
      cout << "Average Grade: " << (int) (average+ 0.5) << "%" << endl;
   }

}