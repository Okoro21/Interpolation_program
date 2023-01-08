//Christopher Okoro Program
 #include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/data.h"
// #include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/lindata.h"
// #include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/quaddata.h"
#include <iostream>

using namespace okoroData;

int main()
{
	
	std::cout << "Hello, this program approximates the midpoints of the function f(x) = 1/(1+x^2) using 1st degree and second degree interpolation\n\n";
	std::cout << "Once The program is finished the data will be output to a data file of your choosing (.txt are the only permissible files)\n\n";
	
	//Data values; //Instantiated an object of type Data
	Data check;
	// LinData linear;
	// QuadData quad;

	check.getCoordinates();


	// linear.linInterpolate();

	// quad.quadInterpolate();

	//values.getCoordinates();
	// values.quadInter();
	// values.initial_plotP();
	// values.print(outs);
	//values.plot(); //Need to adjust dislin functions 

return 0;
}
