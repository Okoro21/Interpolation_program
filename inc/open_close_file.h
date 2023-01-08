//Christopher Okoro Program
//Opens an output file

#ifndef OPEN_CLOSE_FILE_H
#define OPEN_CLOSE_FILE_H

#include <fstream>
#include <string>

namespace okorofile
{
	// Takes the file stream and file name as an parameters.
	// Checks to ensure that the outputfile was created successfully
	void output_open(std::ofstream & output, std::string file_name);
	void input_open(std::ifstream &read, std::string file_name);
}

#endif