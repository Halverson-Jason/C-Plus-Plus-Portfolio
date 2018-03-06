/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy  
*    Brother Alvey, CS165
* Author:
*    Jason Halverson
* Summary: 
*	Estimated: 1 hr
*	Actual : 3 hrs
*	Most difficult part:
*	Checking that the DNA markers matched.

*	DNA sequencing check , this progam will receive a 10 character DNA 
*	marker sequence from the end user along with a list of possible 
*	relatives and their DNA markers. Markers use A, T, C, and G
************************************************************************/


#include <iostream>
#include <string>
using namespace std;

// function declarations

// receive array of DNA marker sequence for user
string getUserDnaMarker(void);

//get list of potential relatives and place into array;
void getRelativeList(int numberOfRelatives, string relativeList[]);

// get list of relatives dna markers;
void getRelativeDnaMarkers(int numberOfRelatives, string relativeList[], 
	string relativeMarker[]);

// calculate percentage match and display results
void calculateMatch(int numberOfRelatives, string relativeList[], 
	string relativeMarker[], string userDna);



/**********************************************************************
 * Function will step through the logic first calling function to get
 * users DNA marker, then receive number of relatives and their DNA 
 * Markers. Then call the function to calculate and display matches.
 ***********************************************************************/
int main()
{
	// variable declarations
	const int MAX_NUMBER_OF_RELATIVES = 50;
	const int NUMBER_OF_DNA_NUCLEOTIDES = 10;

	int numberOfPotentials;
	string relativeList[MAX_NUMBER_OF_RELATIVES];
	string relativeDna[NUMBER_OF_DNA_NUCLEOTIDES];


	// receive array of DNA marker sequence for user
	cout << "Enter your DNA sequence: ";
	string userDnaMarker = getUserDnaMarker();

	// get number of potential relatives
	cout << "Enter the number of potential relatives: ";
	cin >> numberOfPotentials;
	cout << "\n";

	// get relative names
	getRelativeList(numberOfPotentials, relativeList);
	cout << "\n";

	// get DNA sequence for relatives
	getRelativeDnaMarkers(numberOfPotentials, relativeList, relativeDna);
	cout << "\n";

	//calculate percentage match
	calculateMatch(numberOfPotentials, relativeList, relativeDna, userDnaMarker);
	

   return 0;
}

// receive array of DNA marker sequence for user
string getUserDnaMarker(void) 
{
	string dnaMarker;
	cin >> dnaMarker;
	return dnaMarker;
}

//get list of potential relatives and place into array;
void getRelativeList(int numberOfRelatives, string relativeList[]) 
{
	for (int i = 0; i < numberOfRelatives; i++) 
	{
		int relativeNumber = i + 1;
		cout << "Please enter the name of relative #" << relativeNumber << ": ";
		cin >> relativeList[i];
	}

	return;
}

// get list of relatives dna markers;
void getRelativeDnaMarkers(int numberOfRelatives, string relativeList[], 
	string relativeMarker[]) 
{

	for (int i = 0; i < numberOfRelatives; i++) 
	{
		cout << "Please enter the DNA sequence for " << relativeList[i] <<": ";
		cin >> relativeMarker[i];
	}

	return;
}

// calculate percentage match and display results

void calculateMatch(int numberOfRelatives, string relativeList[], 
	string relativeMarker[], string userDna) 
{

	// Loop through potential relatives
	for (int i = 0; i < numberOfRelatives; i++) 
	{
		int percentRelated = 0;
		string dnaMark = relativeMarker[i];
	
		// loop through markers
		for (int j = 0; j < userDna.size(); j++) 
		{

			// if match to same sequence in users dna add 10
			if (dnaMark[j] == userDna[j]) 
			{
				percentRelated += 10;
			}
		}
		
		cout << "Percent match for " << relativeList[i] << ": " 
			<< percentRelated << "%\n";

	}


	return;
}