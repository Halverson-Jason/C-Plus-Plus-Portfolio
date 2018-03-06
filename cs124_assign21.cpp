/***********************************************************************
* Program:
*    Assignment 21, DEBUGGING
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary:
*    Sue wants to write a program to help her determine how much money she 
*    is spending on her car. Specifically, she wants to know how much she 
*    spends per day having the car sit in her driveway and how much she spends 
*    per mile driving it.
*
*    Estimated:  0.5 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

// stub function declarations
double getPeriodicCost();
double promptDevalue();
double promptInsurance();
double promptParking();

double getUsageCost();
double promptMileage();
double promptGas();
double promptRepairs();
double promptTires();

void display(double costUsage, double costPeriodic);


int main()
{
   display(getPeriodicCost(), getUsageCost());
   return 0;
}

double getPeriodicCost()
{
   promptDevalue() + promptInsurance() + promptParking() ;
   return 0.0;
}

double promptDevalue()
{
   return 0.0;
}

double promptInsurance()
{
   return 0.0;
}

double promptParking()
{
   return 0.0;
}

double getUsageCost()
{
   promptMileage() * (promptGas() + promptGas() + promptRepairs() + promptTires()); 
   return 0.0;
}

double promptMileage()
{
   return 0.0;
}

double promptGas()
{
   return 0.0;
}

double promptRepairs()
{
   return 0.0;
}

double promptTires()
{
   return 0.0;
}

void display(double costUsage, double costPeriodic)
{
   cout << "Success\n";
}