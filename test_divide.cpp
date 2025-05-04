#include "SquareMat.h"
# include "cassert"
int main6() {//6
	SquareMat mat = SquareMat(3);
	double x = mat[0][2];
	double y = mat[2][2];
	double z = mat[1][2];
	mat = mat / 3;
	assert( (x / 3) == mat[0][2]);
	assert( (y / 3) == mat[2][2]);
	assert( (z/3) == mat[1][2]);
	std::cout << mat;
	return 0;
}