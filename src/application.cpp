//Christopher Okoro Program
#include "C:\Vs_code\Updated_Interpolation_program\inc\Data.h"
#include "Data.cpp"

using namespace okoroData;

int main()
{
	Data values;
	double A_array[3][3], invert_array[3][3];
	ofstream outs;

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
	//values.plot();
	values.garbage();


return 0;
}
