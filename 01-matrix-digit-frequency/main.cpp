#include <iostream>

/* the function's purpose is to first take in the user input for the elements of the matrix
*  during that process it checks that input and increments the count of that digit in the 
*  digit_count array.
*  the function takes the rows and the columns as parameters as constants
*/
int* TwoD_Matrix(const size_t rows, const size_t columns, int (&digits_count)[10])
{
	// declaring and defining a dynamic 2D array that will hold the elements of the input matrix
	int** matrix = new int* [rows];

	/* in order to fully creat the 2D array we need to allocate memory for each for of the array
	*  basically we have an array of pointer and each pointer points to an array of integers
	*/
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[columns];
	}

	std::cout << "------------------" << std::endl;
	std::cout << "to insert the elements of the matrix smoothly\nplease follow this pattern '0 1 2 3..' or do it one by one" << std::endl;
	std::cout << "matrix elements: ";
	// taking the input of the elements of the matrix and counting the digits in it
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matrix[i][j];

			switch (matrix[i][j])
			{
			case 0:
				digits_count[0]++;
				break;
			case 1:
				digits_count[1]++;
				break;
			case 2:
				digits_count[2]++;
				break;
			case 3:
				digits_count[3]++;
				break;
			case 4:
				digits_count[4]++;
				break;
			case 5:
				digits_count[5]++;
				break;
			case 6:
				digits_count[6]++;
				break;
			case 7:
				digits_count[7]++;
				break;
			case 8:
				digits_count[8]++;
				break;
			case 9:
				digits_count[9]++;
				break;
			}
		}
	}
	std::cout << std::endl;

	/* after we are done we have to first delete the inner pointers of the matrix, then delete the matrix it self
	*  this is necessary to free up the allocated memory to avoid memory leaks
	*  we also set the pointers to nullptr because it holds the address of a memory that has been freed
	*  and if we use this pointer to access that address it leads to undefined behavior, also known as a dangling pointer
	*/
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
		matrix[i] = nullptr;
	}
	// here we delete the outer pointer of the matrix
	delete[] matrix;
	matrix = nullptr;
	return digits_count;
}

// overloading the output stream operator "<<" to print the final array
std::ostream& operator<<(std::ostream& stream, int (&array)[10])
{
	std::cout << "result: { ";
	for (int i = 0; i < 9; i++)
	{
		std::cout << array[i] << ", ";
	}
	std::cout << array[9] << " }";

	return stream;
}

int main()
{
	// defining two variables for the rows and the columns of the matrix
	size_t rows, columns;
	// declaring and defining a static array with all its elements initialized to 0
	// we used a static one because we know the size at compile time
	int digits_count[10] = { 0 };
	std::cout << "Please input two integers" << std::endl;
	std::cout << "Rows: ";
	// taking the input of the rows and columns of the matrix
	std::cin >> rows;
	std::cout << "Columns: ";
	std::cin >> columns;
	// defining a pointer ( dynamic array ) and calling the function that creates the matrix and counts the digits in it
	TwoD_Matrix(rows, columns, digits_count);
	// printing the final array
	std::cout << digits_count << std::endl;
	return 0;
}