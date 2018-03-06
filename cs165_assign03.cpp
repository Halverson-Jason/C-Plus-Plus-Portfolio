/***********************************************************************
* Program:
*    Assignment 03, DIGITAL FORENSICS
*    Brother Alvey, CS165
* Author:
*    Jason Halverson
* Summary:
* ACME Widget Corporation had another break in. They loved the work you 
* did last time, so they've come to you again. Unfortunately, this time, 
* their log file was corrupted, so your program from before crashes when 
* run on the log.
*
* They recognize that the results of your program won't be perfect, 
* because the file they gave you has issues, but they hope that you'll 
* be able to give them as much help as possible. In particular, they want 
* your program to ignore any records that are corrupt, but report on all 
* the good lines in the file.
*
* Write a program to scan through a log to identify users who accessed 
* files in a particular window of time. When a line with bad data is 
* encountered, display a message noting the bad line, but then skip it 
* and move on.
*
*    Estimated:  2.0 hrs
*    Actual:     8.0 hrs
*      Fighting differences in newline chars in Windows and Linux
*      Fixing logic error by adding a counter int to verify struct length
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// define constants
#define MAXARRAYSIZE 500
#define MINTIMESTAMP 1000000000
#define MAXTIMESTAMP 10000000000

// record that contains a username, a filename and a long in timestamp
struct AccessRecord
{
   string username;
   string accessedFile;
   long timestamp;
};

// prototype functions
void getLogFile(string &fileName);
void displayRecord(AccessRecord accessList[], long &beginningTime,
   long &endTime, int &counter);
void parseLine(string fileLine, AccessRecord accessList[], 
   int &lineCount) throw(const char *);
bool parseFile(string &fileName, AccessRecord accessList[], 
   int &counter);
void getTimeStamps(long &beginningTime, long &endTime);

/**********************************************************************
* Main initializes all needed variables, calls getLogFile() , parseFile()
* prompts for getTimeStamps() and calls displayRecord()
***********************************************************************/
int main()
{
   // variable declarations
   string fileName;
   long begginingTime;
   long endTime;
   AccessRecord accessList[MAXARRAYSIZE];
   int counter = 0;

   // get user input
   getLogFile(fileName);

   // read file
   parseFile(fileName, accessList, counter);

   // get user time input
   getTimeStamps(begginingTime, endTime);

   // output display
   cout << "\nThe following records match your criteria:\n\n";
   cout << setw(15) << "Timestamp" << setw(20) << "File" << setw(21)
      << "User\n";
   cout << "---------------" << setw(20) << "-------------------"
      << setw(21) << "-------------------\n";

   // display matching records.
   displayRecord(accessList, begginingTime, endTime, counter);
   cout << "End of records\n";

   return 0;
}

/**********************************************************************
* prompts user for filename
* gets fileName by reference
***********************************************************************/
void getLogFile(string &fileName)
{
   cout << "Enter the access record file: ";
   cin >> fileName;
   cin.get();
   return;
}

/**********************************************************************
* verifies if timestamp is within the specified window and outputs
* appropriate records within the time requested
***********************************************************************/
void displayRecord(AccessRecord accessList[], long &beginningTime,
   long &endTime, int &counter)
{
   for (int i = 0; i < counter; i++)
   {
      if (accessList[i].timestamp >= beginningTime &&
         accessList[i].timestamp <= endTime)
      {
         cout << setw(15) << accessList[i].timestamp << setw(20)
            << accessList[i].accessedFile << setw(20)
            << accessList[i].username << endl;
      }

   }

   return;
}

/**********************************************************************
* accepts a line (a string),populates a struct for the AccessRecord
* throws errors for malformed data
***********************************************************************/
void parseLine(string fileLine, AccessRecord accessList[], 
   int &lineCount) throw(const char *)
{
   stringstream ss(fileLine);
   ss >> accessList[lineCount].accessedFile;
   if (ss.fail())
   {
      throw "Error parsing line: ";
   }

   ss >> accessList[lineCount].username;
   if (ss.fail())
   {
      throw "Error parsing line: ";
   }

   ss >> accessList[lineCount].timestamp;
   if (ss.fail())
   {
      throw "Error parsing line: ";
   }

   else if ((accessList[lineCount].timestamp < MINTIMESTAMP) || 
      (accessList[lineCount].timestamp > MAXTIMESTAMP))
   {
      throw "Error parsing line: ";
   }

   return;
}

/**********************************************************************
* parses the file one line at a time 
* passes that line to parseLine function
***********************************************************************/
bool parseFile(string &fileName, AccessRecord accessList[], int &counter)
{
   // variable for string stream
   string line;
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
   // read data from file and parse each line to parseLine()
 
   while (getline(fin, line))
   {
      // get each line in file and pass to parseLine;
      try
      {
         parseLine(line, accessList, counter);
      }
      catch (const char * errorMessage)
      {
         cout << errorMessage << line << endl;
      }
      
      counter++;
   }

   fin.close();

   return true;
}

/**********************************************************************
* prompts user for timestamps
* gets timestamps
***********************************************************************/
void getTimeStamps(long &beginningTime, long &endTime)
{
   cout << "\nEnter the start time: ";
   cin >> beginningTime;
   cout << "Enter the end time: ";
   cin >> endTime;

   return;
}
