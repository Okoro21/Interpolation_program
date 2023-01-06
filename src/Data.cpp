//Christopher Okoro Program

#include "C:\Vs_code\Updated_Interpolation_program\inc\Data.h"
// #include "C:\dislin\dislin.h"

// #include "C:\Dev_C_scripts\header_files\ofile_open.h" 
// #include "C:\Dev_C_scripts\ENGR_50_project\inverse_mat.h" // Header file containing the inverse program
// #include "C:\Dev_C_scripts\header_files\ifile_open.h"
// #include "C:\Dev_C_scripts\ENGR_50_project\initializing_invert.h" // Header file that initializes the invert array
// s
// using namespace std;

namespace okoroData 
{
	void Data::intro()
	{
		cout << "Hello, this program approximates the midpoints of the function f(x) = 1/(1+x^2) using 1st degree and second degree interpolation\n\n";
		cout << "Once The program is finished the data will be output to a data file of your choosing (.txt are the only permissible files)\n\n";
	}

	void Data::initial_x() //Initializes the x-values
	{
		x_values = new float[size];
		int delta_x;
		
		delta_x = (up_lim-low_lim)/N_seg;
		
		for (int i = 0; i < size; i++)
		{
			x_values[i] = low_lim + delta_x*i;
		}
		
	}

	void Data::initial_y() //Initializes the y-values
	{
		y_values = new float[size];
		
		for (int i = 0; i < size; i++)
		{ 
			y_values[i] = 1/(1+pow(x_values[i],2));
		}
	}

	void Data::initial_xmid()  //Initializes the x-mid points
	{
		x_mid = new float[size-1];
		
		for (int i = 0; i < size-1; i++)
		{
			x_mid[i] = (x_values[i] + x_values[i+1])/2.0; 
		}
	}

	void Data::initial_ymid()
	{
		y_mid = new float[size-1];
		
		for (int i = 0; i < size-1; i++)
		{
			y_mid[i] = 1/(1+pow(x_mid[i],2));  // Creating 10 y midpoint values 
		}
	}

	void Data::initial_slope()
	{
		slope = new float[size-1];
		
		for (int i = 0; i < size-1; i++)
		{
			slope[i] = (y_values[i+1]-y_values[i])/(x_values[i+1]-x_values[i]);  // Determining the slope for each line 
		}
	}

	void Data::initial_yint()
	{
		y_int = new float[size-1];
		
		for (int i = 0; i < size-1; i++)
		{
			y_int[i] = (y_values[i])-slope[i]*x_values[i];  // Determining the y-intercept of each line 
		}
	}

	void Data::inital_L_ymid()
	{
		L_ymid = new float[size-1];
			
		for (int i = 0; i < size-1; i++)
		{
			L_ymid[i] = slope[i]*x_mid[i]+y_int[i]; // Producing the linear interpolated y-midpoints
		}
	}

	void Data::initial_array(double A_array[][3])
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
				A_array[q][0] = pow(A_array[q][0],2);
				A_array[q][2] = 1;
				
			}
		}
	}
		
	void Data::initial_Qcoeff(double invertedArray[][3]) //Initalizing the Q_coeff array with coefficents generated from inverse solving the system of equations
	{
		Q_coeff = new float[15];
		string ifile = "inverse_mat2.txt";
		ifstream read;
		
		input_open(read, ifile); //User defined function to verify if input file opened successfully
		
		*Q_coeff = 0; //Initalizing all the values in the coefficent array to 0;
		
		for (int z = 0; z < 5; z++)
		{
			
			initialize_inv(invertedArray, read);  // Makes a call to a function that initalilizes the inverse array.
		
			for (int j = 0; j < 3; j++)
			{
				for (int i = 0; i < 3; i++)
				{
					Q_coeff[(3*z)+j] = Q_coeff[(3*z)+j] + invertedArray[j][i]*y_values[(2*z)+i];   
				}	
			}
		}
			
	}

	void Data::initial_Q_ymid() // Initalizes the dynamic array Q_ymid with the quadratic interpolated y_midpoints
	{
		Q_ymid = new float[size-1];
		
		for (int z = 0; z < 5; z++)
		{
			for (int i = 0; i < 2; i++)
			{
				Q_ymid[(2*z)+i] = Q_coeff[3*z]*pow(x_mid[(2*z)+i],2) + Q_coeff[3*z+1]*x_mid[(2*z)+i] + Q_coeff[3*z+2]; //Quadratic interpolated ymid points 
			}
		}
	}

	void Data::initial_plotP()
	{
		plot_x = new float[plot_size];
		plot_y = new float[plot_size];
		float plot_dx;	
		
		plot_dx = static_cast<float>((up_lim-low_lim))/plot_seg;  // Determines the width of the interval for the actual plot of the function 
		
		for (int j = 0; j < plot_size; j ++)
		{
			plot_x[j] = low_lim + plot_dx*j;
			plot_y[j] = 1/(1+pow(plot_x[j],2));  // Creating the actual y-values that will make up the smooth curve
		}
	}

	// void Data::plot()
	// {
	// 	int ic;
	// 	char charBuff[30];
	// //	 double fpi = 3.1415926/180., step, x;
	// //  step = 360. / (size-1);
	
	// //***************Plot Configuration****************** // 
	//   metafl("cons"); //Creates screen output. To create PDF output use "pdf"
	//   disini();
	//   pagera();
	//   complx();
	//   axspos(450,1800);
	//   axslen(2200,1200);
	//   name("X-axis","x");
	//   name("Y-axis","y");
	//   labdig(-1,"x");
	//   ticks(9,"x");
	//   ticks(10,"y");
	//   titlin("Demonstration of CURVE",1);
	//   titlin("1/(1+x^2)",3);
	//   ic=intrgb(0.95,0.95,0.95);
	//   axsbgd(ic);
	//   graf(-7.,7.,-5.,0.5,0.,1.2,0,0.5);
	//   setrgb(0.7,0.7,0.7);
	//   grid(1,1);
	//   color("fore");
	//   height(50);
	//   title();
	// //********************Create Plot********************
	// 	color("magenta");
	//   curve(plot_x,plot_y,plot_size); //Plots actural curve
	// 	marker(4);
	// 	incmrk(-1); 
	//   color("blue");
	//   curve(x_mid,y_mid,size-1);
	//   color("green");
	//   curve(x_mid,L_ymid, size-1);  //Plots Linear interpolated _mid values 
	// //	marker(3);
	// //	incmrk(-1);
	//   color("red");
	//   curve(x_mid,Q_ymid,size-1); //Plots quadratic interpolated y_mid values
	//   legini(charBuff,4,50);
	//   leglin(charBuff, "Actual Function",1);
	//   leglin(charBuff,"Actual Value",2);
	//   leglin(charBuff, "Linear Interp",3);
	//   leglin(charBuff, "Quadratic Interp", 4);
	//   legtit("LEGEND");	
	//   legpos(1,1);
	//   legend(charBuff,7);
	//   disfin(); //Ends plot session. Must include

	// }

	void Data::p_error()
	{
		Q_error = new float[size-1];
		L_error = new float[size-1];
		
		for (int i = 0; i < size-1; i++)
		{
			L_error[i] = (fabs(y_mid[i]-L_ymid[i]))*100/(y_mid[i]);
			Q_error[i] = (fabs(y_mid[i]-Q_ymid[i]))*100/(y_mid[i]);
		}
	}


	void Data::print(ofstream& outs)  
	{
		string ofile;
		
		cout << "Please enter the name of the output file (include the .txt extension)" << endl;
		cin >> ofile;
		output_open(outs, ofile); //Verify if output file opened successfully
		
		outs.setf(ios::fixed);
		outs.setf(ios::showpoint);
		outs.precision(3);
		
		outs << "\t\t\t\t\tLinear interpolation" << endl;
		outs << "---------------------------------------------------------------------------------\n\n";
		
		
		outs << "Actual X mid" << "\tActual Y midpoints" << "\tApproximated Y mid" << "\tPercent error %" << endl;
		
		for (int i = 0; i < size-1; i++)
		{
			outs << x_mid[i] << setw(23) << y_mid[i] << setw(23) << L_ymid[i] << setw(23) << L_error[i] << endl;
			outs << L_error[i] << endl;
		}
		
		outs <<"\n\n";
		
		outs << "\t\t\t\t\tQuadratic interpolation" << endl;
		outs << "---------------------------------------------------------------------------------\n\n";
		
		
		outs << "Actual X mid" << "\tActual Y midpoints" << "\tApproximated Y mid" << "\tPercent error %" << endl;
		
		for (int i = 0; i < size-1; i++)
		{
			outs << x_mid[i] << setw(23) << y_mid[i] << setw(23) << Q_ymid[i] << setw(23) << Q_error[i] << endl;
			outs << Q_error[i] << endl;
		}
		
	}

	void Data::garbage()
	{

		delete []x_values;
		delete []y_values;
		delete []x_mid;
		delete []y_mid;
		delete []plot_y;
		delete []plot_x;
		delete []slope; 
		delete []y_int; 
		delete []L_ymid;
		delete []Q_coeff;
		delete []Q_ymid;
		delete []Q_error;
		delete []L_error;
		
	} 

}


