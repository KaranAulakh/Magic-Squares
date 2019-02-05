
/* Attempt at eight configurations
Notes on how to start this project

DO NOT declare a variable size area like
cin >> n
array[n]
Two ways to do it, easier-> vectors, harder -> dynamic arrays

declare it using pointers
	int foo[size] // Not Allowed
	int * foo = new int [size] //allowed

Magic squares: 
	N*N squares
	Summation of all rows/colomns/diagonals = n(n^2+1)/2
	https://www.geeksforgeeks.org/magic-square/  ... deeper explanation of magic sqaures and a way of creating one
*/

/*
int main () {
	int n; 
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
//	intitalizes an array to contain the magic square
	int** magic = new int *[n]; 
	for (int i = 0; i < n; i++) {
		magic[i] = new int[n];
	}	
// delete array
	for (int i = 0; i < n; i++){  
		delete[] magic[i];
	}
	delete[] magic;

	return (0);
}

void magicSquare (int** x, int y, int z){
	magicSquare = x;
	squareNumber = y;
	n = z;
	int counter = 0, sum, row = 0, col = 0; // sum used multiple times to represent rows, columns and diagonals as needed
//	Starting position
	if (squareNumber == (1 || 2)) { // Starts at Middle right
		int i = (n-1) / 2;
		int j = n-1; 
	}
	else if (squareNumber == (3 || 4)) { // Starts at top middle
		int i = 0;
		int j = (n-1) / 2;
	}
	else if (squareNumber == (5 || 6)) { // Starts at mid left
		int i = (n-1) / 2;
		int j = 0
	}
	else if (squareNumber == 7 || 8) { // Starts bottom mid 
		int i = n - 1
		int j = (n-1) / 2;
	}

//	Algorithim for setting numbers is contained in this for loop, derived from 'https://www.geeksforgeeks.org/magic-square/'
	for (int x = 1; x-1 < (n*n); x++) {
		magic[i][j] = x;
		counter++; // keeps track of how many numbers have been stored
//	When one entire diagonal has been stored it moves one to the left to place numbers in the next diagonal
		if (counter >= n){
			j--;
			counter = 0;
		}
//	For every other moment, it moves the position one to the right and one up to store numbers in a diagonal manner
		else {
			i--;
			j++;
		}
//	Whenever the desired position is off the grid, it moves it to the other side of the grid.
		if (i == n) { // If position is to far to the bottom, it resets to the top 
			i = 0;
		}
		if (i == -1) { // If position is to far to the top, it resets to the bottom
			i = n-1;
		}
		if (j == n){ // If position is to far to the right, it resets to the left
			j = 0;
		}
		if (j == -1) { // If position is to far to the left, it resets to the right
			j = n-1;
		}
	}	

//	print the magic squares
	std::cout << "Magic Square #1 is: \n\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << magic[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
//	determine and print the sum of all the rows
	std::cout << "Checking the sums of every row:      ";
	for (int i = 0; i < n; i++){
		int sum = 0;
		for (int j = 0; j < n; j++){
			sum = sum + magic[i][j];
		}
		std::cout << sum << " ";
	}
	std::cout << std::endl;
//	determine and print the sum of all the columns
	std::cout << "Checking the sums of every column:   ";
	for (int j = 0; j < n; j++){
		int sum = 0;
		for (int i = 0; i < n; i++){
			sum += magic[i][j];
		}
		std::cout << sum << " ";
	}
	std::cout << std::endl;
//	determine and print the sum of the diagonals 
	std::cout << "Checking the sums of every diagonal: ";
// 	represents the diagonal from top left to bottom right
	sum = 0;
	for (int i = 0; i < n; i++){
		sum += magic[row][col];
		row++;
		col++;
	}
	std::cout << sum << " "; 
//	represents the diagonal from bottom left to top right
	sum = 0;
	row = 0;
	col = n - 1;
	for (int i = 0; i < n; i++){
		sum += magic[row][col];
		row++;
		col--;
	}
	std::cout << sum << std::endl; // represents the diagonal from top left to bottom right
}
*/