#include <iostream>
#include <vector>
#include <cmath>

/* I used "using" to define a type alias, basically a 'nickname'
*  instead of typing std::vector<float> everytime I would only
*  need to type f_poly, which is a "float polynomial"
*/
using f_poly = std::vector<float>;

// takes the vector as a reference
void Poly_Init(f_poly& Poly)
{
	float temp = 0.0f;
	for (int i = 0; i < Poly.capacity(); i++)
	{
		std::cin >> temp;
		Poly[i] = temp;
	}
}
void Ops_On_Poly(f_poly& Poly1, f_poly& Poly2,
					f_poly& add, f_poly& sub, f_poly& multi, size_t diff)
{
	size_t temp = diff;
	if (temp & 1)// in case the difference is odd
	{
		temp++;
	}
	if (Poly1.size() == Poly2.size())// in case both polys have the same degree
	{
		for (int i = 0; i < add.size(); i++)
		{
			add[i] = Poly1[i] + Poly2[i];
			sub[i] = Poly1[i] - Poly2[i];
		}
	}
	else
	{
		// this for loop is going to add and subtract the parts of the two polynomials that have the same degree
		for (int i = Poly1.size() - 1, j = Poly2.size() - 1, k = add.size() - 1; i + 1 >= temp - 1 && j + 1 >= temp - 1; i--, j--, k--)
		{
			add[k] = Poly1[i] + Poly2[j];
			sub[k] = Poly1[i] - Poly2[j];
		}
		// those two conditions, will ensure that we add the remaining part of the larger polynomial to the resulting addition and subtraction polynomials
		if (Poly1.size() > Poly2.size())// case if the first poly was larger
		{
			for (int i = diff - 1; i >= 0; i--)
			{
				add[i] = Poly1[i];
				sub[i] = Poly1[i];
			}
		}
		else if (Poly2.size() > Poly1.size())// case if the second poly was larger
		{
			for (int i = diff - 1; i >= 0; i--)
			{
				add[i] = Poly2[i];
				sub[i] = -Poly2[i];
			}
		}
	}

	//                                               -----------
	// 2x^2 + 4x - 5                                            |
	// 3x + 2                                                   |
	//                                                          |---------------------------------------------------|
	// 6x^3 m[0], 4x^2 m[1]      +                              |---------------------------------------------------|
	// 12x^2 m[1], 8x m[2]      ===>   6x^3 + 16x^2 -7x -10     |                                                  ||
	// -15x m[2], -10 m[3]                                      |                                                  ||
	//                                                -----------                                                  ||
	//                                                                                                             ||
	//                                                                                                             ||
	/* how the multiplication works is the basic logic is to take every element                                    ||
	*  of the any poly, but in this case the first poly, then multiply it by                                       ||
	*  every other element in the second poly.                                                                     ||
	*  but to ensure the combination is included in this process, we need to                                       ||
	*  add the result of the multiplication to the right place in the resulting multiplication polynomial          ||
	*  which is determined by the degree of the two elements we are multiplying                                    ||
	*  and we know there degrees by the index of that element in the poly/vector                                   ||
	*  it might be confusing, 0 index is the highest degree element                                                ||
	*  1 is the second highest degree element                                                                      ||
	*  I included a comment with an example to make it more clear --------------------------------------------------
	*/
	for (int i = 0; i < Poly1.size(); i++)
	{
		for (int j = 0; j < Poly2.size(); j++)
		{
			multi[i + j] += Poly1[i] * Poly2[j];
		}
	}
}


// overloading the operator '<<' so it can print the vectors
std::ostream& operator<<(std::ostream& stream, const f_poly& poly)
{
	// printing first element
	std::cout << "{ " << poly[0] << ", ";
	// printing middle elements
	for (int i = 1; i < poly.size() - 1; i++)
	{
		std::cout << poly[i] << ", ";
	}
	// printing last element
	std::cout << poly[poly.size() - 1] << " }" << std::endl;

	return stream;
}

int main()
{
	// declaring sizes
	size_t size1, size2, smallest_size, largest_size, difference;
	// Im gonna be using vector for this one, Im tired of pointers
	// I used std::vector from the standard library "vector"
	f_poly poly1, poly2;
	f_poly addition, subtraction, multiplication;

	// taking in the size of each polynomial
	std::cout << "Please enter the size of each Polynomial\n";
	std::cout << "size of first poly: ";
	std::cin >> size1;
	std::cout << "size of second poly: ";
	std::cin >> size2;

	// detemining which size is the largest and which is the smallest
	smallest_size = std::min(size1, size2);
	largest_size = std::max(size1, size2);
	// taking the difference 
	difference = largest_size - smallest_size;

	// allocating memory ( I used resize because its easier to deal with, reserve will cause "out of range" because it only changes the capacity )
	poly1.resize(size1);
	poly2.resize(size2);
	/* for the addition and subtraction polynomials, I took the largest size 
	*  because the resulting poly will be of the highest degree between 
	*  the other two polynomials
	*/
	addition.resize(largest_size);
	subtraction.resize(largest_size);
	/* for the multiplication we need enough space for the ( degree of poly1 + degree of poly2 )
	*  the "-1" is because we only need one space for the constant
	*  since both polys have the last elements as a constat "5" or "-2"
	*  and its not counted in the degree, then we need one space for it
	*  in the resulting poly that holds the multiplication results
	*/
	multiplication.resize(size1 + size2 - 1);


	// initializing polynomials
	std::cout << "for the polynomials input, you just have to enter the coefficients\n";
	std::cout << "instead of '2x^2 + 4x -5' you can do 2 4 -5\n";
	std::cout << "please when you enter polys ensure that degrees go one by one\n";
	std::cout << "this code is unable to solve polys that have missing degrees \nlike '2x^3 + 5' because the degree of x^2 and x are missing\n";
	std::cout << "Please enter the elements of the first polynomial: ";
	Poly_Init(poly1);
	std::cout << "Please enter the elements of the second polynomial: ";
	Poly_Init(poly2);
	// running arthmetic operations
	Ops_On_Poly(poly1, poly2, addition, subtraction, multiplication, difference);

	// some spacing
	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;

	// printing results
	std::cout
		<< "Addition: " << addition << std::endl
		<< "Subtraction: " << subtraction << std::endl
		<< "Multiplication: " << multiplication << std::endl;

	return 0;
}