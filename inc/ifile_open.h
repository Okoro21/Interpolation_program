//Christopher Okoro Program
// Opens input file
// If the input file fails to open, the user is notified 

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>


void input_open(std::ifstream & read, std::string file_name)
{
	read.open(file_name.c_str());
	if (read.fail())
	{
		std::cout << "The input file failed to open.";
		exit(1);
	}

}
