//Christopher Okoro Program
// Opens input file
// If the input file fails to open, the user is notified 

#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/open_close_file.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

namespace okorofile //Contains the implemention for the functions within open_close_file.h
{
	void input_open(std::ifstream &read, std::string file_name)
	{
		read.open(file_name.c_str());
		if (read.fail())
		{
			std::cout << "The input file failed to open.";
			exit(1);
		}
	}

	void output_open(std::ofstream & output, std::string file_name)
	{
		output.open(file_name.c_str());
		if (output.fail())
		{
			std::cout << "The input file failed to open.";
			exit(1);
		}
	}
}
