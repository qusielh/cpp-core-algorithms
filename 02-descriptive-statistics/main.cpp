#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

// just declaring the function so that we can use it in the array function with out putting the code before the array function
void quartile(const int* const array, const size_t size, float& med, float& q, const int which_quartile);


// the function's purpose is just to calculate statistics of an array
void array(const size_t size, float& avg, float& med, float& q1, float& q3, float& rng, const int typ)
{
	// declaring and defining a dynamic array
	int* array = new int[size];
	// defining unsigned integers that we will use later as indices
	unsigned int m1_index = 0;
	unsigned int m2_index = 0;
	unsigned int M_index = 0;

	// taking in the elements of the array, also calculating the average through this process
	std::cout << "Please enter the elements of the array: ";
	for (int i = 0; i < size; i++)
	{
		std::cin >> array[i];
		avg += array[i];
	}

	// after we have added up all the integers together, we just need to divide it by the size/number of integers
	avg = avg / size;

	// I used std::sort function from the standard library "algorithm", it uses Quick sort & Heap sort & Insertion sort depending on the array
	std::sort(array, array + size);

	// after sorting the array we know for a fact that the first element is the smallest and the last element is the biggest, so we can just subtract them to get the range
	rng = array[size - 1] - array[0];

	switch (typ)
	{
	case 0:
		// in the case of even-sized array, we need to get the left and right side of the middle ( if that makes sense )
		m1_index = ((size - 1) / 2);
		m2_index = ((size - 1) / 2) + 1;
		// after we get the indices of those left-right elements of the middle, we just add them up and divide them by two, to get the median
		med = ((float)array[m1_index] + array[m2_index]) / 2;
		break;
	case 1:
		// in the case of odd-sized array, all we need is just to get the middle element, thats basically the median
		M_index = std::ceil((size - 1) / 2);
		med = array[M_index];
		break;
	}

	// calling the quartile function for the first quartile
	quartile(array, size, med, q1, 1);
	// calling the quartile function for the third quartile
	quartile(array, size, med, q3, 3);

	delete[] array;
	array = nullptr;
}

/* the function's purpose is to get the first and the third quartile, depending on the arguments
*  it takes the pointer of the array ( const int* const is to ensure the data wont change and the pointer wont either )
*  the size as constant
*  median and quartile as reference
*  and an integer as constant that will let the function know which quartile we are looking for
*/
void quartile(const int* const array, const size_t size, float& med, float& q, const int which_quartile)
{
	/* to get the quartiles we need a data structure that can have its size changes
	*  and a vector is the easiest one to use
	*  I used the std::vector class from the standard library "vector"
	   it can change the size of it by allocating a larger block of memory move 
	   the data from the old one then delete the old one and free the memory
	*/
	std::vector<int> temp;

	/* I used here the ternary operator, if the condition is satisfied 
	   it will assign "i" to 0 otherwise it will assign it to almost 
	   the middle index, this process is used to determine which half
	   of the array are we gonna need depending on which quartile we
	   want to find.
	*/
	int i = (which_quartile == 1) ? 0 : (std::ceil(size - 1) / 2);

	// case of first quartile
	if (i == 0)
	{
		// taking the part of the array thats less than the median
		while (true)
		{
			if (array[i] < med)
			{
				temp.push_back(array[i]);
			}
			else
			{
				break;
			}
			i++;
		}
	}
	// case of third quartile
	else
	{
		// taking the part of the array that greater than the median
		while (true)
		{
			if (array[i] > med)
			{
				temp.push_back(array[i]);
			}
			else if (i == size)
			{
				break;
			}
			i++;
		}
	}

	// we do the same thing as we did before to find the median, the media is basically the second quartile of an array
	// the case of even-sized array
	if (temp.size() % 2 == 0)
	{
		int m1_index = ((temp.size() - 1) / 2);
		int m2_index = ((temp.size() - 1) / 2) + 1;

		q = ((float)temp[m1_index] + temp[m2_index]) / 2;
	}
	// the case of odd-sized array
	else
	{
		int M_index = std::ceil((temp.size() - 1) / 2);
		q = temp[M_index];
	}
}

int main()
{
	// declaring size
	size_t size;
	// defining variables for the average, median, first quartile, third quartile and range
	float average = 0, median = 0, quartile1 = 0, quartile3 = 0, range = 0;
	// defining a variable that will be used to know if the size of the array is even or odd
	int type = 0;

	// taking in the size of the array
	std::cout << "Please enter the desired size of the array: ";
	std::cin >> size;
	while (size < 1)
	{
		std::cout << "please enter an integer no less than 1" << std::endl;
		std::cin >> size;
	}

	// checking if the size of the array is even or odd, 0 for even and 1 for odd obviously
	if (size % 2 == 0)
	{
		type = 0;
	}
	else
	{
		type = 1;
	}

	// we pass size and type as constants, and the rest are passed by reference so that we can modify them in the function
	array(size, average, median, quartile1, quartile3, range, type);

	// printing the results
	std::cout
		<< "arthmetic mean: " << average << '\n'
		<< "median: " << median << '\n'
		<< "first quartile: " << quartile1 << '\n'
		<< "third quartile: " << quartile3 << '\n'
		<< "range: " << range
		<< std::endl;
	return 0;
}