#include "SquareMat.h"
# include "cassert"
int test6() {
	SquareMat mat = SquareMat(3);
	double x = mat[0][2];
	double y = mat[2][2];
	double z = mat[1][2];
	-mat;
	assert(x*-1 == mat[0][2]);
	assert(y*-1== mat[2][2]);
	assert(z*-1 == mat[1][2]);
	std::cout << mat;
	return 0;
} 