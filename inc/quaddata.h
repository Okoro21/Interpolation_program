
#ifndef QUADDATA_H
#define QUADDATA_H

#include "data.h"
#include "IO_file.h"
//#include "inverse_mat.h"

#define COLS 3

namespace okoroData
{
    class QuadData : public Data
    {
        public:
            ~QuadData();
            void quadInterpolate();

        private:
        	void init_array(double A_array[][COLS]);
			void init_Qcoeff(double inv_A[][COLS]);
			void init_quadYmid();
            void quadp_error();
            //void rowReduce(double A[][4]);
            void print();

            FloatArrayPtr quadCoeff;
			FloatArrayPtr quad_ymid;
			FloatArrayPtr quadError;
    };

}

#endif //QUADDATA_H