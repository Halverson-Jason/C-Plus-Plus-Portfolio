/***********************************************************************
* Program:
*    Assignment 02, DIGITAL FORENSICS
*    Brother Alvey, CS165
* Author:
*    Jason Halverson
* Summary: 
* ACME Widget Corporation just experienced their first digital security 
* breach. One of their secret widget designs just appeared on the Internet. 
* Now they've hired you as a digital forensics investigator to help 
* determine what additional data might have been involved in the breach.

* One of the first steps in digital forensics is to inspect system logs, 
* particularly file access and user account logs. To assist you in this 
* investigation, you've been given a log from ACME's network server that 
* contains a list of file access times and the users that accessed them.
*
* Write a program to scan through that log to identify users who accessed 
* files in a particular window of time.
*
*    Estimated:  2.0 hrs   
*    Actual:     2.0 hrs
*      Figuring out how I wanted to loop through the file Reading
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// record that contains a username, a filename and a long in timestamp
struct AccessRecord
{
   string username;
   string accessedFile;
   long timestamp;
};

// prototype functions
void getLogFile(string &fileName, long &beginningTime, long &endTime);
bool readFile(string &fileName, AccessRecord accessList[]);
void displayRecord(AccessRecord accessList[], long &beginningTime, 
   long &endTime);

/**********************************************************************
 * Main initializes all needed variables, calls getLogFile() , readFile()
 * displays initial matching records header and calls displayRecord()
 ***********************************************************************/
int main()
{
   // variable initializations
   string fileName;
   long begginingTime;
   long endTime;
   AccessRecord accessList[500];

   // get user input
   getLogFile(fileName, begginingTime, endTime);
   
   // read file
   readFile(fileName, accessList);

   // output display
   cout << "\nThe following records match your criteria:\n\n";
   cout << setw(15) << "Timestamp" << setw(20) << "File" << setw(21) 
      << "User\n";
   cout << "---------------" << setw(20) << "-------------------" 
      << setw(21) << "-------------------\n";

   // display matching records.
   displayRecord(accessList, begginingTime, endTime);
   cout << "End of records\n";

   return 0;
}
/**********************************************************************
* get filename , a beginning timestamp and ending timestamp
***********************************************************************/
void getLogFile(string &fileName, long &time1, long &time2)
{
   cout << "Enter the access record file: ";
   cin >> fileName;
   cout << "\nEnter the start time: ";
   cin >> time1;
   cout << "Enter the end time: ";
   cin >> time2;
   return;
}
/**********************************************************************
* Read the file provided , fill data from file and close file
***********************************************************************/
bool readFile(string &fileName, AccessRecord accessList[])
{
   // open the file for reading changed string to c_string
   ifstream fin(fileName.c_str()); 
   
   // error check  
   if (fin.fail())                             
   {
      // inform user of the error
      cout << "Unable to open file "    
         << fileName
         << endl;
      return false;                   
   }
   // read data from file and fill out the AccessRecord struct
   for (int i = 0; !fin.eof(); i++) 
   {
      fin >> accessList[i].accessedFile >> accessList[i].username 
         >> accessList[i].timestamp;

   }

   fin.close(); 
   return true;
}
/**********************************************************************
* verifies if timestamp is within the specified window and outputs
***********************************************************************/
void displayRecord(AccessRecord accessList[], long &beginningTime, 
   long &endTime)
{

   for (int i = 0; accessList[i].timestamp > 0; i++)
      if (accessList[i].timestamp >= beginningTime && 
         accessList[i].timestamp  <= endTime )
      {
         cout << setw(15) << accessList[i].timestamp << setw(20) 
            << accessList[i].accessedFile << setw(20) 
            << accessList[i].username << endl;
      }
   

   return;
}