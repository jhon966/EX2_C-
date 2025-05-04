#include "SquareMat.h"

int main5() {
	SquareMat mat = SquareMat(3);
	mat = mat%3;
	std::cout << mat;
	return 0;
}