/*
 * This file accomplishes the same task but with the concept of permutation in order to find every possible magic square. The file is still
 * under construction however. The program woks but at an insupportable time complexity of O(n!) 
 */

#include <iostream>
#include <math.h>
using namespace std;

void print (int** magic, int arraySize, int squareNumber) {
	int row = 0, col = 0, sum; //sum used multiple times to represent different sums
//	print the magic squares
	cout << "Magic Square #" << squareNumber << " is: \n\n";
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < arraySize; j++) {
			cout << magic[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
//	determine and print the sum of all the rows
	cout << "Checking the sums of every row:      ";
	for (int i = 0; i < arraySize; i++){
		int sum = 0;
		for (int j = 0; j < arraySize; j++){
			sum = sum + magic[i][j];
		}
		cout << sum << " ";
	}
	cout << endl;
//	determine and print the sum of all the columns
	cout << "Checking the sums of every column:   ";
	for (int j = 0; j < arraySize; j++){
		int sum = 0;
		for (int i = 0; i < arraySize; i++){
			sum += magic[i][j];
		}
		cout << sum << " ";
	}
	cout << endl;
//	determine and print the sum of the diagonals 
	cout << "Checking the sums of every diagonal: ";
	sum = 0;
//	represents the diagonal from top left to bottom right
	for (int i = 0; i < arraySize; i++){
		sum += magic[col][row];
		col++;
		row++;
	}
	cout << sum << " "; 
	sum = 0;
	col = 0;
	row = arraySize - 1;
//	represents the diagonal from bottom left to top right
	for (int i = 0; i < arraySize; i++){
		sum += magic[col][row];
		col++;
		row--;
	}
	cout << sum << "\n\n";
}
bool isMagicSquare (int** magic, int arraySize){
	int magicSum = arraySize*(arraySize*arraySize+1)/2;
	int mySum = 0; // used multiple times and represents all rows, columns and diagonals
	int col = 0, row = 0; // used to keep track of index's for diagonals\
//	checks the sum of all rows
//	cout << "magicSum: " << magicSum << "\n"; // TESTING
//	cout << "rows:  "; // TESTING
	for (int i = 0; i < arraySize; i++){
		mySum = 0;
		for (int j = 0; j < arraySize; j++){
			mySum += magic[i][j];
		}
//		cout << mySum; // TESTING
		if (magicSum != mySum){
			return(0);
		}
	}
//	checks the sum of all columns
//	cout << "\ncolumns:  "; // TESTING
	for (int j = 0; j < arraySize; j++){
		mySum = 0;
		for (int i = 0; i < arraySize; i++){
			mySum += magic[i][j];
		}
//		cout << mySum; // TESTING
		if (magicSum != mySum){
			return(0);
		}
	}
//	checks the diagonal from top left to bottom right
	mySum = 0;
//	cout << "\ndiagonal: "; // TESTING
	for (int i = 0; i < arraySize; i++){
		mySum += magic[col][row];
		col++;
		row++;
	}
//	cout << mySum; // TESTING
	if (magicSum != mySum){
			return(0);
	}
	mySum = 0;
	col = 0;
	row = arraySize - 1;
//	checks the diagonal from bottom left to top right
	for (int i = 0; i < arraySize; i++){
		mySum += magic[col][row];
		col++;
		row--;
	}
//	cout << mySum; // TESTING
	if (magicSum != mySum){
			return(0);
	}
	return (1);
}
void intSwap(int* array, int a, int b) {
    int temp;
    temp = array[a];
    array[a] = array[b];
	array[b] = temp;
}
void possibleCombinations (int** magic, int* array, int start, int end, int arraySize, int squareNumber){
    int tracker;
    int rowSum = 0;
    int magicSize = sqrt(arraySize);
    int magicSum = magicSize*(magicSize*magicSize+1)/2;
	int arrayIndex = 0;
	bool testMagicSquare = 0;
    if (start == end) {
    	for (int i = 0; i < magicSize; i++){
			rowSum +=  array[i];
		}
		if (magicSum == rowSum) {
			for (int i = 0; i < magicSize; i++) {
				for (int j = 0; j < magicSize; j++) {
					magic[i][j] = array[arrayIndex];
					arrayIndex++;
				}
			}
			testMagicSquare = isMagicSquare(magic, magicSize);
			if (testMagicSquare){
				print(magic, magicSize, squareNumber);
			}
			testMagicSquare = 0;
		}
	}
//      squareNumber++;   
    else {
        for (tracker = start; tracker < arraySize; tracker++) {
            intSwap(array, start, tracker);
            possibleCombinations(magic, array, start + 1, end, arraySize, squareNumber);
            intSwap(array, start, tracker);
        }  
    }
}

int main () {
	int n, squareNumber = 0;
	bool input = 1;
//	loop checks to see if the input is acceptable 
	while (input) {
		cout << "Enter the size of a magic square: ";
		cin >> n;
		cout << endl;
		if (n >= 3 && n <= 15 && (n % 2 == 1))
			input = 0;
		else 
			cout << "Error: Only odd numbers between 3 and 15 are acceptable\n";
	}
//	intitalizes an array to contain the magic square
	int** magic = new int *[n]; 
	for (int i = 0; i < n; i++) {
		magic[i] = new int[n];
	}
//	sets the entire array to zero
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			magic[i][j] = 0;
		}
	}
//	initalizes an easier to work with single dimensional array	
	int* magicFinder = new int [n*n];
	for (int i = 0; i < n*n; i++) {
		magicFinder[i] = i + 1;
	}
//	finds every permutation of a magic square
	possibleCombinations(magic, magicFinder, 0, n*n-1, n*n, squareNumber);

/*
	bool test = 0;
	magic[0][0] = 2;
	magic[0][1] = 9;
	magic[0][2] = 4;
	magic[1][0] = 7;
	magic[1][1] = 5;
	magic[1][2] = 3;
	magic[2][0] = 6;
	magic[2][1] = 1;
	magic[2][2] = 8;
	test = isMagicSquare(magic, n);
	print(magic, n, 1);
	if (test){
		cout << "fuck yeah\n";
	}
	else {
		cout << "WTH\n";
	}
*/
//	delete array
	for (int i = 0; i < n; i++){  
		delete[] magic[i];
	}
	delete[] magic;

	return (0);	
}
