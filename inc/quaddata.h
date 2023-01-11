
#ifndef QUADDATA_H
#define QUADDATA_H

#include "data.h"
#include "IO_file.h"
//#include "inverse_mat.h"

namespace okoroData
{
    class QuadData : public Data
    {
        public:
            ~QuadData();
            void quadInterpolate();

        private:
        	void init_array(double A_array[][3]);
			void init_Qcoeff();
			void init_Qymid();
            void quadp_error();
            void print();

            FloatArrayPtr quadCoeff;
			FloatArrayPtr quad_ymid;
			FloatArrayPtr quadError;
    };

}

#endif //QUADDATA_H