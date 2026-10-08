#include <iostream>

/* the function's purpose is to count the words that end with a specific character
*  it takes a pointer to an array of string
*  the size of the array as constant
*  the desired character as constant
*  and the count as reference
*/
void last_char_freq_counter(std::string* words, const size_t size, const char character, int& count)
{
	for (int i = 0; i < size; i++)
	{
		if (words[i][words[i].length() - 1] == character)
		{
			count++;
		}
	}
}

int main()
{
	// declaring size
	size_t size;
	// declaring a pointer of the type "string"
	std::string* words;
	// declaring character
	char character;
	// defining count
	int count = 0;
	std::cout << "Please enter the number of word: ";
	std::cin >> size;

	// defining words, allocating memory for it
	words = new std::string[size];

	// taking input for words
	std::cout << "Please enter the words: ";
	for (int i = 0; i < size; i++)
	{
		std::cin >> words[i];
	}

	// taking the desired character
	std::cout << "Please enter the character: ";
	std::cin >> character;
	std::cout << "----------------------------------" << std::endl;

	/* calling the function that will check which words end with the desired character
	*  and count them, storing the result in the variable "count" straight away since
	*  its passed by reference
	*/
	last_char_freq_counter(words, size, character, count);

	std::cout << "The number of words that end with the character '" << character << "' is: " << count << std::endl;

	// deallocating memory
	delete[] words;
	// setting the pointer to nullptr
	words = nullptr;
	return 0;
}