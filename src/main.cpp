//Christopher Okoro Program
#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/Data.h"
#include <fstream>

using namespace okoroData;

int main()
{
	Data values; //Instantiated an object of type Data
	std::ofstream outs;

	values.intro();
	values.getCoordinates();
	values.linInterpolate();
	values.quadInter();
	values.initial_plotP();
	values.p_error();
	values.print(outs);
	//values.plot(); //Need to adjust dislin functions 

return 0;
}
