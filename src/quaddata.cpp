
/*
    This is the impelentation file for the derived class QuadData
*/

#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/quaddata.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

namespace //Using unnamed namesapce to define helper functions
{
// Initalizing the inverse array
// Reads the values of the inverted from a data file into a 3x3 array

	void init_inv(double invert_array[][3], ifstream & read)
	{
		for (int n = 0; n < 3; n++)
		{
			for (int m = 0; m < 3; m++)
				read >> invert_array[n][m]; 
		}
	}
}


namespace okoroData
{
    void QuadData::quadInterpolate()
	{
		getCoordinates();
		double A_array[3][3];
		init_array(A_array);
		init_Qcoeff();
		init_Qymid();
		print();
	}

    void QuadData::init_array(double A_array[][3])
	{
		for (int index = 0; index < 5; index++) // Initializing the values of the matrix A (3x3 matrix  of known values)
		{	
			for(int j = 0; j < 3; j++)
				A_array[0][j] = x_values[index*2];
			
			for(int k = 0; k < 3; k++)
				A_array[1][k] = x_values[1+(index*2)];
			
			for(int z = 0; z < 3; z++)
				A_array[2][z] = x_values[2+(index*2)];
			
			for(int q = 0; q < 3; q++)
			{
				A_array[q][0] = pow(A_array[q][0],2); // column 1 contains x_values ^2 column 2 contains x_values^1 column 3 contains x_values^0  
				A_array[q][2] = 1;
			}
		}
	}

    /*
		Need to adjust iniatial_Qcoeff() such that invertedArray[3][3] can have its values populated by the inverse
		matrix algorithm directly
	*/
	void QuadData::init_Qcoeff() //Initalizing the quad_coeff array with coefficents generated from inverse solving the system of equations
	{
		using okorofile::input_open;
		
		double invertedArray[3][3]; //Values of the inverted array are not populated yet
		
		quadCoeff = new float[15];
		string ifile = "inverse_mat2.txt";
		ifstream read;
		
		input_open(read, ifile); //User defined function to verify if input file opened successfully
		
		*quadCoeff = 0; //Initalizing all the values in the coefficent array to 0;
		
		for (int z = 0; z < 5; z++)
		{
			init_inv(invertedArray, read);  // Makes a call to a function that initalilizes the inverse array.
		
			for (int j = 0; j < 3; j++)
			{
				for (int i = 0; i < 3; i++)
				{
					quadCoeff[(3*z)+j] = quadCoeff[(3*z)+j] + invertedArray[j][i]*y_values[(2*z)+i];   
				}	
			}
		}
	}

	void QuadData::init_Qymid() // Initalizes the dynamic array Q_ymid with the quadratic interpolated y_midpoints
	{
		quad_ymid = new float[size-1];
		
		for (int z = 0; z < 5; z++)
		{
			for (int i = 0; i < 2; i++)
			{
				quad_ymid[(2*z)+i] = quadCoeff[3*z]*pow(x_mid[(2*z)+i],2) + quadCoeff[3*z+1]*x_mid[(2*z)+i] + quadCoeff[3*z+2]; //Quadratic interpolated ymid points 
			}
		}
	}

	void QuadData::quadp_error()
    {
        quadError = new float[size-1];

        for (int i = 0; i < size-1; i++)
            quadError[i] = (fabs(y_mid[i] - quad_ymid[i])) * 100/(y_mid[i]);
    }

    void QuadData::print()
    {
        using okorofile::output_open;
		string ofile;
		ofstream outs;

		quadp_error();
		
		cout << "QUADRATIC INTERPOLATION DATA:\nEnter output file (include the .txt extension)" << endl;
		cin >> ofile;
		output_open(outs, ofile); //Verify if output file opened successfully
		
		outs.setf(ios::fixed);
		outs.setf(ios::showpoint);
		outs.precision(3);
		
		outs << "\t\t\t\t\tQuadratic interpolation" << endl;
		outs << "---------------------------------------------------------------------------------\n\n";
		
		outs << "Actual X mid" << "\tActual Y midpoints" << "\tApproximated Y mid" << "\tPercent error %" << endl;
		
		for (int i = 0; i < size-1; i++)
		{
			outs << x_mid[i] << setw(23) << y_mid[i] << setw(23) << quad_ymid[i] 
			<< setw(23) << quadError[i] << endl;
		}
    }

    QuadData::~QuadData() //~QuadData automatically calls Data constructor due to parent child relationship
    {
        delete [] quadCoeff;
		delete [] quad_ymid;
		delete [] quadError;
    }
}