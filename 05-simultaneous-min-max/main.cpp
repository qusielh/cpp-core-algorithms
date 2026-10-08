#include <iostream>
#include <chrono>


int main()
{
	/* in order to make cin faster, we need to disable the synchronization
	* between C and C++ standard streams, and untie cin from cout
	*/
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);// we also untie cin from cout, so it reads the input faster

	// declaring the size, a dynamic array, minimum and maximum variables, some other variables
	int size;
	int* arr;
	int temp1, temp2, min, max, i;

	// taking in the size of the array
	std::cout << "Please enter the size of the array: ";
	std::cin >> size;

	// defining the array/allocating memory for it
	arr = new int[size];

	std::cout << "the algorithm has not started yet, it will start when all the inputs\n are taken.\n";
	std::cout << "Please enter the elements of the array: ";
	for (i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}


	// I used std::chrono from the standard library "chrono"
	/* it works by taking the time before the algorithm starts
	*  and then taking the time after the algorithm ends
	*  and then calculating the duration by subtracting the start time from the end time
	*  and then converting it to milliseconds
	*/
	// starting the timer
	std::cout << "-------------------------------------------------------------------------------------\n";
	std::cout << "the algorithm has started, and the timer is running . . .\n";
	auto start = std::chrono::high_resolution_clock::now();

	// we run the algorithm for 100,000 to get a more accurate time
	for (int j = 0; j < 100000; j++)
	{
		i = 0;
		
		// comparisons = 3 * ((size - 1) / 2) for odd | 1 + 3 * ((size - 2) / 2 ) for even
		// TA(n,d) = (3/2)·n + O(1)

		// compares the fit bit of the right, if its 1 then its odd-sized, if its 0 its even-sized
		if (size & 1)
		{
			// we assign both min and max to the first element
			min = arr[0];
			max = min;
			// we set "i" to 1 so it starts from the second element
			i = 1;
		}
		else
		{
			// we take the first pair
			temp1 = arr[0];
			temp2 = arr[1];
			// we compare them
			if (temp1 > temp2)// if the first one is greater
			{
				// min takes the second one
				min = temp2;
				// max takes the first one
				max = temp1;
			}
			else// if the second one is greater
			{
				// min takes the first one
				min = temp1;
				// max takes the second one
				max = temp2;
			}
			// we set "i" to 2 so it starts from the third element
			i = 2;
		}

		// the loop that will compare pairs of the array one by one, until the end of the array
		for (; i < size; i += 2)
		{
			// we take a pair
			temp1 = arr[i];
			temp2 = arr[i + 1];
			// we compare the pair
			if (temp1 > temp2)
			{
				// then we compare the greater one with the max
				if (temp1 > max)
				{
					max = temp1;
				}
				// and we compare the smaller one with the min
				if (temp2 < min)
				{
					min = temp2;
				}
			}
			else
			{
				// the opposite happens here
				if (temp2 > max)
				{
					max = temp2;
				}
				if (temp1 < min)
				{
					min = temp1;
				}
			}
		}
	}
	
	// we stop the timer
	auto end = std::chrono::high_resolution_clock::now();
	// we calculate the duration
	std::chrono::duration<long double> duration = end - start;
	
	// we calculate the average duration per one loop/running the algorithm once
	auto average_duration = duration / 100000;
	// we calculate it in nano seconds and milliseconds
	auto ns = std::chrono::duration_cast<std::chrono::duration<long double, std::nano>>(average_duration);
	auto ms = std::chrono::duration_cast<std::chrono::duration<long double, std::milli>>(average_duration);

	std::cout << "Minimum value: " << min << "\nMaximum value : " << max << '\n';
	std::cout << "Time taken: " << average_duration.count() << "seconds | " << ms.count() << " milliseconds | " << ns.count() << " nanoseconds\n";

	// we deallocate memory
	delete[] arr;
	arr = nullptr;
	return 0;
}