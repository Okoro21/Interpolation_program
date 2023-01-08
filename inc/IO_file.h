//Christopher Okoro Program
//Opens an output file

#ifndef IO_FILE_H
#define IO_FILE_H

#include <fstream>
#include <string>

namespace okorofile
{
	using namespace std;
	/*
		Pre: An object of type ofstream was declared in the calling function 
			file_name is the name of the end-users textfile, the .txt extension must be included within the string
		
		Post: output was successfully linked to output file "file_name"
			Else, an error is returned and the program terminates  
	*/

	void output_open(ofstream & output, string file_name);
	void input_open(ifstream &read, string file_name);
}

#endif //IO_FILE_H