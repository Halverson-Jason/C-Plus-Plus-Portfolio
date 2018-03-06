/*********************************************************************** 
* Program: 
* Checkpoint 01b, C++ Review
* Brother Alvey, CS165 
* Author: 
* Jason Halverson
* Summary: 
* No summary needed for Checkpoints 
************************************************************************/

#include <iostream>

using namespace std;

int getSize();
void getList(int passedArray[], int count);
void displayMultiples(int passedArray[], int arraySize);


int main() {
	
	int myArray[25];
	int arraySize = getSize();
	getList(myArray, arraySize);
	cout << "\n";
	displayMultiples(myArray, arraySize);

	return 0;
}

// prompts for the size of the list, or the number of integers to be read in.
int getSize() {
	int getArraySize;
	cout << "Enter the size of the list: ";
	cin >> getArraySize;

	return getArraySize;
}

// getList, that accepts an array of integers and a count. It should prompt the 
// user for the list of numbers and store them in the passed array.

void getList(int passedArray[], int count) {
	int usersIndex;
	for (int i = 0; i < count; i++) {
		cout << "Enter number for index " << i << ": ";
		cin >> passedArray[i];
	}

	return;
}

// displayMultiples that accepts the array and its size. It should loop through 
// each element in the array and display it if it is divisible by 3.
// You may assume that the size of the list will always be less than 20

void displayMultiples(int passedArray[], int arraySize ) {
	int isDivisable;
	cout << "The following are divisible by 3:\n";
	for (int i = 0; i < arraySize; i++) {
		
		if (passedArray[i] % 3 == 0) {
			cout << passedArray[i] << "\n";
		}
			

	}
	return;
}
