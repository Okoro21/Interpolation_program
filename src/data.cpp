//Christopher Okoro Program

#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/data.h"
#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/IO_file.h"
// Header file containing the inverse program
// #include "C:\dislin\dislin.h"


#include <fstream>
#include <string>
#include <iostream>
#include <ostream>	
#include <cmath>
#include <iomanip>

using namespace std;

namespace okoroData //Implementation of Data class is contained within okoroData namespace
{

	void Data::getCoordinates()
	{
		initial_x();
		initial_y();
		initial_xmid();
		initial_ymid();
		print_data();
	}

	void Data::initial_x() //Initializes the x-values
	{
		x_values = new float[size];

		int delta_x = (up_lim - low_lim)/N_seg;
		
		for (int i = 0; i < size; i++) 
			x_values[i] = low_lim + delta_x*i;
	}

	void Data::initial_y() //Initializes the y-values
	{
		y_values = new float[size];
		
		for (int i = 0; i < size; i++)
			y_values[i] = 1/(1+pow(x_values[i],2));
	}

	void Data::initial_xmid()  //Initializes the x-mid points
	{
		x_mid = new float[size-1];
		
		for (int i = 0; i < size-1; i++)
			x_mid[i] = (x_values[i] + x_values[i+1])/2.0; 
	}

	void Data::initial_ymid()
	{
		y_mid = new float[size-1];
		
		for (int i = 0; i < size-1; i++)
			y_mid[i] = 1/(1+pow(x_mid[i],2));  // Creating 10 y midpoint values 
	}

	// void Data::initial_plotP()
	// {
	// 	plot_x = new float[plot_size];
	// 	plot_y = new float[plot_size];
	// 	float plot_dx;	
		
	// 	plot_dx = static_cast<float>((up_lim-low_lim))/plot_seg;  // Determines the width of the interval for the actual plot of the function 
		
	// 	for (int j = 0; j < plot_size; j ++)
	// 	{
	// 		plot_x[j] = low_lim + plot_dx*j;
	// 		plot_y[j] = 1/(1+pow(plot_x[j],2));  // Creating the actual y-values that will make up the smooth curve
	// 	}
	// }

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

	// void Data::p_error()
	// {
	// 	Q_error = new float[size-1];

	// 	for (int i = 0; i < size-1; i++)
	// 	{
	// 		Q_error[i] = (fabs(y_mid[i]-Q_ymid[i]))*100/(y_mid[i]);
	// 	}
	// }

	void Data::print_data()
	{
		cout << "\t\t\t\t\tLinear Interpolation" << endl;
		cout << "---------------------------------------------------------------------------------\n\n";
		
		cout << "x values " << "\ty values" << "\tActual x mid" << "\tActual y midpoints" << endl;
		for (int i = 0; i < size -1; i++)
		{
			cout << x_values[i] << "\t" << y_values[i] << "\t" << x_mid[i] << "\t" << y_mid[i] << endl;
		}

	}

	Data::~Data()
	{
		delete []x_values;
		delete []y_values;
		delete []x_mid;
		delete []y_mid;
		// delete []plot_y;
		// delete []plot_x;
	} 
}


