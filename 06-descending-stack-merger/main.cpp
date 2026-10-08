#include <iostream>
// including stack to be able to used std::stack class
#include <stack>
// including algorithm for the std::sort sorting function
#include <algorithm>




/* the function's purpose is to fill up the third stack ( stack3 )
*  it works by defining a dynamic array that uses a pointer
*  has the size of ( size1 + size2 ) to ensure theres enough memory
*  stores all the elements of both stack1, and stack2
*  then sorts them in ascending order
*  and eventually pushes them to stack3
*/
void Ascending_Sorted_Stack(std::stack<int>& stack1, std::stack<int>& stack2, const size_t size1, const size_t size2, std::stack<int>& stack3, const int mode)
{
	// defining the size of the array, which is the total of both stack1, stack2 sizes
	size_t total_size = size1 + size2;
	// declaring and defining the array that will hold the elements
	int* array = new int[total_size];
	
	size_t index = total_size;
	// pushing stack1 elements to the array
	while(!stack1.empty())
	{
		// grabbing the top element of stack1, and pushing it to the array
		array[index - 1] = stack1.top();
		// popping the top element of stack1
		stack1.pop();
		// decrementing the total size to go, so we can go to the next index in the array
		index--;
	}
	// same for the second stack
	while(!stack2.empty())
	{
		array[index - 1] = stack2.top();
		stack2.pop();
		index--;
	}

	// sorting the array in ascending order using std::sort function from the standard library "algorithm"
	// it uses Quick sort, Heap sort and Insertion sort, and its highly optimized
	std::sort(array, array + total_size);
	
	// checking if the mode is 1, if it is the condition will be true, and it will remove duplicates
	if (mode)
	{
		/*
			this algorithm works by considering the first element to be always unique
			and starts from the second one, and keeps checking if the current element
			if equal to the previous one, it will increment read
			if its not equal, it will take that element in put it in th index of write
			then increments write ...etc

			for example, "1 1 2 3 3 4":
			1 is unique it sits at the index 0
			write is 1, read is 1, now the array[read] is equal to array[write - 1]
			so we ignore it, we increment read, and write remains the same
			write is 1, read is 2, now the array[read] is not equal to array[write - 1]
			so we take that element which is "2" and we put it in the index of write
			now the array would look like "1 2 2 3 3 4", when we keep doing that
			the array will look like "1 2 3 4 3 4"
			notice that we will set the total size to the value of write, so basically
			the elements we are gonna be using "1 2 3 4" and the rest are ignored
		*/
		int write = 1;
		for (int read = 1; read < total_size; read++)
		{
			if (array[read] != array[write - 1])
			{
				array[write] = array[read];
				write++;
			}
		}

		total_size = write;
	}

	// filling stack3
	for (int i = 0; i < total_size; i++)
	{
		// we used emplace because it constructs the element in place, instead of constructing the place then copying the element
		stack3.emplace(array[i]);
	}
	
	// deleting the array to free up the memory, to avoid any memory leaks
	delete[] array;
	// its better to set array to nullptr
	array = nullptr;
}

/* the function's purpose is to fill the original stack, while avoiding 
   copying by taking the stack as a reference.
   also takes the size because the class "stack" doesn't provide
   a function that returns the size of the stack
*/
void fill_stack(std::stack<int>& stack, const size_t size)
{
	// defining a temporary int to capture the input before pushing it onto the stack
	int temp = 0;
	// filling the stack with user input
	for (int i = 0; i < size; i++)
	{
		std::cin >> temp;
		stack.emplace(temp);
	}
}

// main function
int main()
{
	// definition of size1 for stack1, and size2 for stack2
	size_t size1, size2;
	// declaring stack1, stack2 and stack3 ( I used	the std::stack data structure from the standard library "stack" )
	std::stack<int> stack1, stack2, stack3;
	// defining mode, used to let the user choose between keeping duplicates, or removing them
	// the default mode is 0, which keeps them
	int mode = 0;

	std::cout << "Please enter the size of each stack to proceed\n";
	std::cout << "Size of first stack: ";
	// taking in the size of stack1
	std::cin >> size1;
	std::cout << "Size of second stack: ";
	// taking in the size of stack2
	std::cin >> size2;

	std::cout << "-------------------------\n";
	std::cout << "Now please input the elements of each stack with this format\n";
	std::cout << "e.g. '1 2 3 4 5..'  | or one by one following each with an 'Enter'\n";
	std::cout << "Elements of the first stack: ";
	
	// fill_stack function takes 2 arguments, the stack passed by reference, and its size as a const
	// calling fill_stack for stack1, to fill it with elements
	fill_stack(stack1, size1);
	std::cout << "Done! now lets move on and fill the second stack\n";
	std::cout << "Elements of the second stack: ";
	// calling fill_stack for stack2, to fill it with elements
	fill_stack(stack2, size2);
	std::cout << "Would you like to keep iterated integers or remove them?\n";
	std::cout << "(0 to keep them, 1 to remove them): ";
	// taking in the preferred mode
	std::cin >> mode;
	std::cout << "Great! please wait for couple nanoseconds so\nthe program can process the data haha!\n";

	/* Ascending_Sorted_Stack function takes 6 arguments :
	*  stack1 and its size ( size1 )
	*  stack2 and its size ( size2 )
	*  stack3
	*  and the mode
	* 
	*  all stacks are passed by reference, all sizes are taken as a const, the same applies for mode
	*/ 
	Ascending_Sorted_Stack(stack1, stack2, size1, size2, stack3, mode);
	
	// printing the elements of stack3
	std::cout << "The Resulting Stack: ";
	while (!stack3.empty())
	{
		// reading the top element
		std::cout << stack3.top() << " ";
		// popping the top element
		stack3.pop();
	}
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}