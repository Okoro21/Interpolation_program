
#ifndef INVERSE_H
#define INVERSE_H

#include <iostream>
#include <cmath>
#include <fstream>
#include "data.h"

using okoroData::FloatArrayPtr;

// void inverse(double mat[][3], ofstream & out_data);
// void inverse(FloatArrayPtr mat[][3]);

void inverse(double mat[][3], std::ofstream &out_data)
{
	using namespace std;

	//string file_name = "inverse_mat.txt";
	//ofstream out_data;
	//output_open(out_data, file_name); // userdefinded function checks to ensure the output file is opened properly
	
	float determinant = 0;

	for (int i = 0; i < 3; i++)
		determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << ((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant;
			out_data << ((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant;
		}
		
		cout<<"\n\n";
		out_data << "\n\n";
	}

}

//void inverse(FloatArrayPtr mat[][3])
//{
//	//string file_name = "inverse_mat.txt";
//	//ofstream out_data;
//	//output_open(out_data, file_name); // userdefinded function checks to ensure the output file is opened properly
//	
//	float determinant = 0;
//	for(int i = 0; i < 3; i++)
//	determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
////	cout<<"\n\ndeterminant: "<< determinant;
////	cout<<"\nInverse of matrix is: \n";
////	out_data <<"\n\ndeterminant: "<< determinant;
////	out_data<<"\nInverse of matrix is: \n";
//	
//	for(int i = 0; i < 3; i++)
//	{
//		for(int j = 0; j < 3; j++)
//		{
//			cout << ((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant;
////			out_data << ((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant;
//		}
//		
//		cout<<"\n\n";
////		out_data << "\n\n";
//	}
//
//}

#endif //INVERSE_H