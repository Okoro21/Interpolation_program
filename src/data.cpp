//Christopher Okoro Program

#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/data.h"
#include "/home/chris/vsc_programs/C++_programs/projcets/Updated_Interpolation_program/inc/IO_file.h"
// #include "C:\dislin\dislin.h"


#include <fstream>
#include <string>
#include <iostream>
#include <ostream>	
#include <cmath>
#include <iomanip>
#include <cstring>

using namespace std;

namespace okoroData //Implementation of Data class is contained within okoroData namespace
{
	Data::Data()
	{
		//Init x & y values
		x_values = new float[size];
		y_values = new float[size];

		int delta_x = (up_lim - low_lim)/N_seg;
		
		for (int i = 0; i < size; i++) 
		{
			x_values[i] = low_lim + delta_x*i;
			y_values[i] = 1/(1+pow(x_values[i],2));
		}

		//Init x & y mid values
		x_mid = new float[size-1];
		y_mid = new float[size-1];
		
		for (int i = 0; i < size-1; i++)
		{
			x_mid[i] = (x_values[i] + x_values[i+1])/2.0; 
			y_mid[i] = 1/(1+pow(x_mid[i],2));  // Creating 10 y midpoint values 
		}

	}


	void Data::plot(float *yMid, int size, int plot)
	{
		//LinData & QuadData call this function to plot interpolated vals
		plotX = new float[plot_size];
		plotY = new float[plot_size];

		char plot_type[50];

		float plot_delta = (up_lim - low_lim)/ static_cast<float>(plot_size);

		for (int i = 0; i < plot_size; i++) 
		{
			plotX[i] = low_lim + plot_delta*i;
			plotY[i] = 1/(1+pow(plotX[i],2));
		}

		if (plot == 1)
			strncpy(plot_type, "QUADRATIC INTERPOLATION", 50);
		else
			strncpy(plot_type, "LINEAR INTERPOLATION", 50);

		int ic;
		Dislin g;

		//g.setfil("my.PDF");
		g.metafl("PNG"); //Creates screen output. To create PDF output use "pdf"
		g.disini();
		g.pagera();
		g.complx();
		g.axspos(450,1800);
		g.axslen(2200,1200);
		g.name("X-AXIS","x");
		g.name("Y-AXIS","y");
		g.labdig(-1,"x");
		g.ticks(2,"x"); //Number of ticks between marked x-values  
		g.ticks(5,"y"); //Number of ticks between marked y-values  
		g.titlin(plot_type,1);
		g.titlin("DEMONSTRATION OF CURVE",2);
		g.titlin("1/(1+x^2)",3);
		g.titjus("cent"); //Postion of the title, left,right,cent
		g.htitle(50);
		ic = g.intrgb(0.95,0.95,0.95);
		g.axsbgd(ic);
		g.graf(-7,7,-7,1,0,1.2,0,0.5);  //Creates 2D axis system
		g.setrgb(0.7,0.7,0.7);
		g.color("fore");
		g.height(50);
		g.title();
		g.grid(2, 2);
	//  g.gaxpar(min,max, "noextend","x", &low_lim, &up_lim, &first_lab, &step, &precision);

//**********************************PLOT OF CURVES*************************************************************************

		g.color("red");
		g.curve(plotX, plotY, plot_size);
		
		g.marker(SYMBOL_CIRCLE);
		g.incmrk(-1);
		g.mrkclr(2);
		g.hsymbl(12);
		g.color("blue");
		g.curve(x_mid, yMid, size);
		g.disfin();

	}

	void Data::print()
	{
		cout.setf(ios::fixed);
		cout.precision(3);
		
		cout << "\t\t\t\t\tLinear Interpolation" << endl;
		cout << "---------------------------------------------------------------------------------\n\n";
		
		cout << "x values" << "\ty values" << "\tActual x mid" << "\tActual y midpoints" << endl;
		for (int i = 0; i < size -1; i++)
			cout << x_values[i] << "\t" << y_values[i] << "\t" << x_mid[i] << "\t" << y_mid[i] << endl;
	}

	Data::~Data()
	{

		delete []x_values;
		delete []y_values;
		delete []x_mid;
		delete []y_mid;
		delete []plotY;
		delete []plotX;
	} 
}


