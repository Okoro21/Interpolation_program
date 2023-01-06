// Initalizing the inverse array
// Reads the values of the inverted from a data file into a 3x3 array

#include <fstream>

using namespace std;

void initialize_inv(double invert_array[][3], ifstream & read);

void initialize_inv(double invert_array[][3], ifstream & read)
{
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 3; m++)
			read >> invert_array[n][m]; 
	}
}
