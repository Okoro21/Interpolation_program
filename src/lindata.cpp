/*
    This is the implementation file for the derived class LinData
    The interface for this file is in lindata.h
*/

#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/lindata.h"
#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/IO_file.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

namespace okoroData
{
    void LinData::linInterpolate()
	{
        getCoordinates();
		initial_slope();
		initial_yint();
		inital_L_ymid();
		print();
	}

    void LinData::initial_slope()
	{
		slope = new float[size-1];
		
		for (int i = 0; i < size-1; i++)
			slope[i] = (y_values[i+1] - y_values[i]) / (x_values[i+1] - x_values[i]);  // Determining the slope for each line 
	}

	void LinData::initial_yint()
	{
		y_int = new float[size-1];
		
		for (int i = 0; i < size-1; i++)
			y_int[i] = (y_values[i])- slope[i]*x_values[i];  // Determining the y-intercept of each line 
	}

    void LinData::inital_L_ymid()
	{
		lin_ymid = new float[size-1];
			
		for (int i = 0; i < size-1; i++)
			lin_ymid[i] = slope[i] * x_mid[i] + y_int[i]; // Producing the linear interpolated y-midpoints
	}

    void LinData::linp_error()
	{
		linError = new float[size-1];
		
		for (int i = 0; i < size-1; i++)
		    linError[i] = (fabs(y_mid[i] - lin_ymid[i])) * 100/(y_mid[i]);
	}
    
    void LinData::print()
    {
        using okorofile::output_open;
		string ofile;
        ofstream outs;
		
		cout << "Please enter the name of the output file (include the .txt extension)" << endl;
		cin >> ofile;

		output_open(outs, ofile); //Verify if output file opened successfully
		
		outs.setf(ios::fixed);
		outs.setf(ios::showpoint);
		outs.precision(3);

        linp_error();
		
		outs << "\t\t\t\t\tLinear Interpolation" << endl;
		outs << "---------------------------------------------------------------------------------\n\n";
		
		outs << "Actual X mid" << "\tActual Y midpoints" << "\tApproximated Y mid" << "\tPercent error %" << endl;
		
		for (int i = 0; i < size-1; i++)
			outs << x_mid[i] << setw(23) << y_mid[i] << setw(23) << lin_ymid[i] << setw(23) << linError[i] << endl;
		
		outs <<"\n\n";

        outs.close();
    }

    LinData::~LinData() //Destuctor to base class is automatically called
    {
        delete [] slope; 
		delete [] y_int; 
		delete [] lin_ymid;
        delete [] linError;
    }

}