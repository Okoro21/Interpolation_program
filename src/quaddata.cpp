
/*
    This is the impelentation file for the derived class QuadData
*/

#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/quaddata.h"
#include <iostream>
#include <iomanip>
#include <cmath>

#define ROWS 3
#define COLS 3


using namespace std;



namespace //Using unnamed namesapce to define helper functions
{
// Initalizing the inverse array
// Reads the values of the inverted from a data file into a 3x3 array

	void rowReduce(double A[][COLS], double Inv[][COLS])
	{
		int lead = 0;

		while (lead < ROWS)
		{
			double d,m;

			for (int r = 0; r < ROWS; r++)
			{
				d = A[lead][lead];
				m = A[r][lead] / A[lead][lead];

				for (int c = 0; c < COLS; c++)
				{
					if (r == lead)
						A[r][c] /= d;
					else
						A[r][c] -= A[lead][c] * m;
				}
			}

			lead++;
		}

		for (int i = 0; i < ROWS;i++)
		{
			for (int j = 0; j < COLS; j++)
				Inv[i][j] = A[i][j];
		}
	}

	void inverse(double mat[][3], double inv_A[][3])
	{		
		float determinant = 0;
		float inv_value = 0;
		for (int i = 0; i < 3; i++)
			determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));

		cout<<"\nSdeterminant: "<< determinant;
		cout<<"\nInverse of matrix: \n";
		// out_data <<"\n\ndeterminant: "<< determinant;
		// out_data<<"\nInverse of matrix is: \n";
		
		for (int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				inv_value = ((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant;
				cout << inv_value << " ";
				inv_A[i][j] = inv_value;
	//			out_data << ((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant;
			}
			
			cout<<"\n";
		}

	}


}


namespace okoroData
{
    void QuadData::quadInterpolate()
	{
		double A_array[ROWS][COLS] = {0};
		quadCoeff = new float[15];
		*quadCoeff = 0;

		getCoordinates();
		init_array(A_array);

		cout << "\n";
		
		for (int i = 0; i < 15; i++)
			cout << quadCoeff[i] << endl;
		// init_Qymid();
		// print();
	}

    void QuadData::init_array(double A_array[][COLS])
	{
		int index = 0;
		double inv_A[ROWS][COLS] = {0};
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

			//Make a call to initialize Q_coeff

			cout << "Augmented Array:\n";
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS; j++)
					cout << A_array[i][j] << " ";

				cout << "\n";
			}

			inverse(A_array,inv_A);

			init_Qcoeff(inv_A);
		}
	}

    /*
		Need to adjust iniatial_Qcoeff() such that invertedArray[3][3] can have its values populated by the inverse
		matrix algorithm directly
	*/
	void QuadData::init_Qcoeff(double inv_A[][COLS]) //Initalizing the quad_coeff array with coefficents generated from inverse solving the system of equations
	{
		static int index = 0;
		static int fiveCount = 0;

		int y_index = 0;

		for (int i = 0; i < ROWS; i++)
		{
			index++;
			for (int j = 0; j < COLS; j++)
			{
				y_index = 2*fiveCount + j;
				quadCoeff[index] += inv_A[i][j] * y_values[y_index];
			}
		}

		fiveCount++;
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
		// delete [] quad_ymid;
		// delete [] quadError;
    }
}