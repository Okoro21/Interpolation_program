//Christopher Okoro Program
//Opens an output file

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <ostream>

using namespace std;

void output_open(ofstream & output, string file_name);
// Takes the file stream and file name as an parameters.
// Checks to ensure that the outputfile was created successfully


void output_open(ofstream & output, string file_name)
{
	output.open(file_name.c_str());
	if (output.fail())
	{
		cout << "The input file failed to open.";
		exit(1);
	}

}