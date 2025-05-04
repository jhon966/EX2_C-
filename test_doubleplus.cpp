#include "SquareMat.h"
# include "cassert"
int main17() {
	SquareMat a = SquareMat(3);
	double x = a[0][2];
	double y = a[2][2];
	double z= a[1][2];
	a++;
	assert((x+1) == a[0][2]);
	assert(y + 1 == a[2][2]);
	assert(z+1 == a[1][2]);
	++a;
	assert((x + 2) == a[0][2]);
	assert(y + 2 == a[2][2]);
	assert(z + 2 == a[1][2]);
	std::cout  << a << std::endl;
	return 0;
}