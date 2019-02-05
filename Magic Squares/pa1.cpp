#include <iostream>

/* 
print is used to print the magic squares and calculate and print the sum of each row, 
column, and diagonal. The int arraySize is the int n passed from main which keeps track of the size of the array.
The int squareNumber is used to count how many squares have been printed so the program can list the correct number.
*/
void print (int** magic, int arraySize, int squareNumber) {
	int row = 0, col = 0, sum; // sum is used multiple times to represent different sums
//	print the magic squares
	std::cout << "Magic Square #" << squareNumber << " is: \n\n";
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < arraySize; j++) {
			std::cout << magic[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
//	determine and print the sum of all the rows
	std::cout << "Checking the sums of every row:      ";
	for (int i = 0; i < arraySize; i++) {
		sum = 0;
		for (int j = 0; j < arraySize; j++) {
			sum = sum + magic[i][j];
		}
		std::cout << sum << " ";
	}
	std::cout << std::endl;
//	determine and print the sum of all the columns
	std::cout << "Checking the sums of every column:   ";
	for (int j = 0; j < arraySize; j++) {
		sum = 0;
		for (int i = 0; i < arraySize; i++) {
			sum += magic[i][j];
		}
		std::cout << sum << " ";
	}
	std::cout << std::endl;
//	determine and print the sum of the diagonals 
	std::cout << "Checking the sums of every diagonal: ";
	sum = 0;
//	represents the diagonal from top left to bottom right
	for (int i = 0; i < arraySize; i++) {
		sum += magic[col][row];
		col++;
		row++;
	}
	std::cout << sum << " "; 
	sum = 0;
	col = 0;
	row = arraySize - 1;
//	represents the diagonal from bottom left to top right
	for (int i = 0; i < arraySize; i++){
		sum += magic[col][row];
		col++;
		row--;
	}
	std::cout << sum << "\n\n";
}

/*
main starts by asking the user for the desired size of the magic square which must be an odd number between
3 and 15, then it creates a dynamic array of that size. The program produces 10 magic squares for any size, except
for 3*3 magic squares since there only are 8 possible squares. Therefore, if the size is 3*3 int possibleSquares is reset 
to 8. int possibleSquares is used to navigate the algorithim that creates each square, such that it takes a different path 
through the loop each time and produces a different square each time. All paths work very similarly, however, differ in 
the starting point (where 1 is placed) and the way it moves around the square (with the next number being place in every
next spot).

For example, squareNumber 1 starts in the middle row of the last column and each subsequent number is placed in the spot
one up and one to the right. If that spot is outside of the square it wraps back around. If that spot is already filled, it 
will instead go one spot to the left.

The algorithim implemented for the first eight was obtained from https://www.geeksforgeeks.org/magic-square/ and 
flipped numerous times to get all eight possibilites. The last two squares were created by observing this picture..
http://www.magic-squares.net/Image_square/Field.gif and following it's path. I realized I could make an additional eight
magic squares using this path but flipping from each central axis numerous times.
*/

int main () {
	int n, row, col, counter = 0, possibleSquares = 10;
	bool input = 1;
//	loop checks to see if the input is acceptable 
	while (input) {
		std::cout << "Enter the size of a magic square: ";
		std::cin >> n;
		std::cout << std::endl;
		if (n >= 3 && n <= 15 && (n % 2 == 1))
			input = 0;
		else 
			std::cout << "Error: Only odd numbers between 3 and 15 are acceptable\n";
	}
	if (n == 3) {
		possibleSquares = 8;
	}
//	intitalizes an array to contain the magic square
	int** magic = new int *[n]; 
	for (int i = 0; i < n; i++) {
		magic[i] = new int[n];
	}	
//	for loop that is 
	for (int squareNumber = 1; squareNumber <= possibleSquares; squareNumber++) {
//	Starting position defined by which square it is
		if (squareNumber == 1 || squareNumber == 2) {
			col = (n-1) / 2;
			row = n-1; 
		}
		else if (squareNumber == 3 || squareNumber == 4) {
			col = 0;
			row = (n-1) / 2;
		}
		else if (squareNumber == 5 || squareNumber == 6) {
			col = (n-1) / 2;
			row = 0;
		}
		else if (squareNumber == 7 || squareNumber == 8) {
			col = n-1;
			row = (n-1) / 2;
		}
		else if (squareNumber == 9) {
			col = 0;
			row = 0;
		}
		else if (squareNumber == 10) { 
			col = n-1; 
			row = 0;
		}
//	Algorithim for setting numbers is contained in this for loop, derived from 'https://www.geeksforgeeks.org/magic-square/'
		for (int x = 1; x-1 < (n*n); x++) {
			magic[col][row] = x;
			counter++; // keeps track of how many numbers have been stored
//	When one entire diagonal has been stored it moves one to the left to place numbers in the next diagonal
			if (counter >= n){
				if (squareNumber == 1 || squareNumber == 2) {
					row--;
				}
				else if (squareNumber == 3 || squareNumber == 4) {
					col++;
				}
				else if (squareNumber == 5 || squareNumber == 6) {
					row++;
				}
				else if (squareNumber == 7 || squareNumber == 8) {
					col--;
				}
				else if (squareNumber == 9) {
					col++;
					row++;
				}
				else if (squareNumber == 10) {
					col--; 
					row++;
				}
				counter = 0;
			}
//	For every other moment, it moves the position one to the right and one up to store numbers in a diagonal manner
			else {
				if (squareNumber == 1 || squareNumber == 3) {
					col--;
					row++;
				}
				else if (squareNumber == 2 || squareNumber == 7) {
					col++;
					row++;
				}
				else if (squareNumber == 4 || squareNumber == 5) {
					col--;
					row--;
				}
				else if (squareNumber == 6 || squareNumber == 8) {
					col++;
					row--;
				}
				else if (squareNumber == 9) {
					col--;
					row += 2;
				}
				else if (squareNumber == 10) {
					col++;
					row += 2;
				}
			}
//	Whenever the desired position is off the grid, it moves it to the other side of the grid.
			if (col == n) { // If position is to far to the bottom, it resets to the top 
				col = 0;
			}
			if (col == n+1) {
				col = 1;
			}
			if (col == -1) { // If position is to far to the top, it resets to the bottom
				col = n-1;
			}
			if (col == -2) {
				col = n-2;
			}
			if (row == n){ // If position is to far to the right, it resets to the left
				row = 0;
			}
			if (row == n+1){
				row = 1;
			}
			if (row == -1) { // If position is to far to the left, it resets to the right
				row = n-1;
			}
			if (row == -2) {
				row = n-2;
			}
		}	
		print(magic, n, squareNumber); 
	}
// delete array
	for (int i = 0; i < n; i++){  
		delete[] magic[i];
	}
	delete[] magic;

	return (0);
}
