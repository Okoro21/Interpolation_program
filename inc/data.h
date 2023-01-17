//Christopher Okoro Program
#ifndef DATA_H
#define DATA_H

#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/dislin.h"

namespace okoroData
{
	typedef float* FloatArrayPtr;  // User defined data type for pointers that point to arrays of type float
}

namespace okoroData //Data class definiton is contained within okoroData namespace
{  
	class Data {
		public:
			~Data();
			Data();
			//void initial_plotP();
			//void plot(); //maybe make plot a virtual function that derive classes can redefine
			//void p_error();
			
		protected:
			void print();

			FloatArrayPtr x_values;
			FloatArrayPtr y_values;
			FloatArrayPtr x_mid;
			FloatArrayPtr y_mid;

			// FloatArrayPtr plot_y;
			// FloatArrayPtr plot_x;

			int low_lim = -5;  //Lower limit of independent variable 
			int up_lim = 5;   // Upper limit of the independent variable 
			int N_seg = 10;  // Number of segments
			int plot_seg = 1000;  // Number of desired line segements 
			int size = 11;  // Number of normal x and y values
			int plot_size = 1001; // Size of array that will plot points 
	}; 
}
#endif //DATA_H





