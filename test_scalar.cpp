#include "SquareMat.h"
# include "cassert"
int test2() {//test4
	SquareMat mat = SquareMat(3);
	double x = mat[0][2];
	double z = mat[1][2];
	double y = mat[2][2];
	mat = 3*mat;
	assert(x * 3 == mat[0][2] );
	assert(y * 3 == mat[2][2]);
	assert(z * 3 == mat[1][2]);
	std::cout << mat;
	mat = mat*3;
	assert(x * 9 == mat[0][2]);
	assert(y * 9 == mat[2][2]);
	assert(z * 9 == mat[1][2]);
	std::cout << mat << std::endl;
	return 0;
}