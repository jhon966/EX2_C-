#include "SquareMat.h"
# include "cassert"
int test1() {
	SquareMat a = SquareMat(3);
	SquareMat b = a - a;
	assert(0 == b[1][1]);
	assert(0 == b[2][1]);
	assert(0 == b[0][2]);
	 b = a + a;
	assert(a[1][1]*2 == b[1][1]);
	assert(a[2][1] * 2 == b[2][1]);
	assert(a[0][2] * 2 == b[0][2]);
	std::cout << b;
	return 0;
}