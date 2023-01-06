//Christopher Okoro Program
#ifndef DATA_H
#define DATA_H

#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/dislin.h"
#include <fstream>

namespace okoroData //Data class definiton is contained within okoroData namespace
{  
	typedef float* FloatArrayPtr;  // User defined data type for pointers that point to arrays of type float

	class Data {
		
		public:
		//Need to create destructor for class
		void print(std::ofstream& outs);
		void intro();
		void initial_x();
		void initial_y();
		void initial_xmid();
		void initial_ymid();
		void initial_slope();
		void initial_yint();
		void inital_L_ymid();
		void initial_array(double A_array[][3]);
		void initial_Qcoeff(double invertedArray[][3]);
		void initial_Q_ymid();
		void initial_plotP();
		void plot();
		void p_error();
		void garbage();
			
		private:
			FloatArrayPtr x_values;
			FloatArrayPtr y_values;
			FloatArrayPtr x_mid;
			FloatArrayPtr y_mid;
			FloatArrayPtr plot_y;
			FloatArrayPtr plot_x;
			FloatArrayPtr slope;
			FloatArrayPtr y_int;
			FloatArrayPtr L_ymid;
			FloatArrayPtr Q_coeff;
			FloatArrayPtr Q_ymid;
			FloatArrayPtr Q_error;
			FloatArrayPtr L_error;
			
			int low_lim = -5;  //Lower limit of independent variable 
			int up_lim = 5;   // Upper limit of the independent variable 
			int N_seg = 10;  // Number of segments
			int plot_seg = 1000;  // Number of desired line segements 
			int size = 11;  // Number of normal x and y values
			int plot_size = 1001; // Size of array that will plot points 
	}; 
}
		
#endif //DATA_H





