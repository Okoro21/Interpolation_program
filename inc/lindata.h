/*
    This is the interface file for the derived class LinData
    The implementation for this file is in lindata.cpp
*/

#ifndef LINDATA_H
#define LINDATA_H

#include "data.h"
#include "IO_file.h"

namespace okoroData
{
    class LinData : public Data  //Derived class of base class Data
    {
        public:
        	virtual ~LinData();
            void linInterpolate();

        private:
            void initial_slope();
			void initial_yint();
			void inital_L_ymid();
            void linp_error();
            void print();

            FloatArrayPtr slope;
			FloatArrayPtr y_int;
			FloatArrayPtr lin_ymid;
            FloatArrayPtr linError;
    };
}

#endif //LINDATA_H