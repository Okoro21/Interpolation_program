//Christopher Okoro Program
#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/Data.h"
#include <fstream>

using namespace okoroData;

int main()
{
	Data values; //Instantiated an object of type Data
	double A_array[3][3], invert_array[3][3];
	std::ofstream outs;

	values.intro();
	values.initial_x();
	values.initial_y();
	values.initial_xmid();
	values.initial_ymid();
	values.initial_slope();
	values.initial_yint();
	values.inital_L_ymid();
	values.initial_array(A_array);
	values.initial_Qcoeff(invert_array);
	values.initial_Q_ymid();
	values.initial_plotP();
	values.p_error();
	values.print(outs);
	//values.plot(); //Need to adjust dislin functions 
	values.garbage();


return 0;
}
