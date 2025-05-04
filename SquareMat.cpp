#include "SquareMat.h"
#include "cmath"

SquareMat::SquareMat(int num)
{
	if (num <= 0) throw std::invalid_argument("Size must be greater than zero");
	this->size = num;
	this->mat = new double*[this->size];
	for (int i = 0; i < size; i++) {
		mat[i] = new double[size];
	}
	double d;
	std::cout << "enter number";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			std::cin >> d;
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000000, '\n');
				std::cout << "eror type";
				std::cin >> d;
			}
			mat[i][j] = d;
		}
	}
}
SquareMat::~SquareMat() {
	for (size_t i = 0; i < this->size; i++)
	{
		delete[]  mat[i];

	}
	delete[] mat;
}
SquareMat::SquareMat(const SquareMat& other) {
	this->size = other.size;
	this->mat = new double* [this->size];
	for (int i = 0; i < size; i++) {
		mat[i] = new double[size];
		for (int j = 0; j < size; j++)
		{
			mat[i][j] = other.mat[i][j];
		}
		}
}

SquareMat& SquareMat:: operator=(const SquareMat& other){
	// delete the old one
	for (int i = 0; i < size; i++) {
		delete [] this->mat[i];
	}
	delete[]  this->mat;
	// aloocate and put value
	this->size = other.size;
	this->mat = new double* [this->size];
	for(int i = 0; i < size; i++) {
		mat[i] = new double[size];
		for (int j = 0; j < size; j++)
		{
			mat[i][j] = other.mat[i][j];
		}
	}
	return *this ;
}

SquareMat SquareMat::operator+(const SquareMat& b)
{
	if (b.size != this->size) { throw std::invalid_argument("the matrix not in the same size");}
	SquareMat a = *this;// use deep copy
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			a.mat[i][j] = a.mat[i][j] + b.mat[i][j];
		}
	}
	return a;
}
void SquareMat::operator-() const
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			this->mat[i][j] = this->mat[i][j] * -1;
		}
	}
}
SquareMat SquareMat::operator-(const SquareMat& b)
{
	if (b.size != this->size) { throw std::invalid_argument("the matrix not in the same size"); }
	SquareMat a = *this;// use deep copy
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			a.mat[i][j] = a.mat[i][j] - b.mat[i][j];
		}
	}
	return a;
}
std::ostream& operator<<(std::ostream& os, const SquareMat& mat)
{
	for (size_t i = 0; i < mat.size; i++)
	{
		std::cout << std::endl;
		for (size_t j = 0; j < mat.size; j++)
		{
			os << mat.mat[i][j];
		}
	}
	return os;
}

SquareMat operator*(double x, const SquareMat& a)
{
	SquareMat b = a;
	for (size_t i = 0; i < a.size; i++)
	{
		for (size_t j = 0; j < a.size; j++) {
			b.mat[i][j] = a.mat[i][j] *x;
		}
	}
	return b;
}

SquareMat SquareMat:: operator*(double x)
{
	SquareMat b = *this;
	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = 0; j < this->size; j++) {
			b.mat[i][j] = this->mat[i][j] * x;
		}
	}
	return b;
}
SquareMat SquareMat:: operator/(double x)
{
	if (x== 0) { throw std::invalid_argument("cant divide in zero "); }
	SquareMat b = *this;
	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = 0; j < this->size; j++) {
			b.mat[i][j] = this->mat[i][j] / x;
		}
	}
	return b;
}
SquareMat SquareMat::operator%(const SquareMat& b)
{
	if (b.size != this->size) { throw std::invalid_argument("the matrix not in the same size"); }
	SquareMat a = *this;// use deep copy
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			a.mat[i][j] = a.mat[i][j] * b.mat[i][j];
		}
	}
	return a;
}
SquareMat SquareMat::operator%(double x)
{
	SquareMat a = *this;// use deep copy
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			a.mat[i][j] = std::fmod(a.mat[i][j],x);
		}
	}
	return a;
}

SquareMat& SquareMat::operator++()
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			this->mat[i][j] = this->mat[i][j] + 1;
		}
	}
	return *this;
}

SquareMat SquareMat::operator--(int )// int is fake parmeter (x++/++x)
{
	SquareMat a(*this); // call deep copy
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			this->mat[i][j] = this->mat[i][j] - 1;
		}
	}
	return a;
}

SquareMat& SquareMat::operator--()
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			this->mat[i][j] = this->mat[i][j] - 1;
		}
	}
	return *this;
}

SquareMat SquareMat::operator++(int)// int is fake parmeter (x++/++x)
{
	SquareMat a(*this); // call deep copy
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			this->mat[i][j] = this->mat[i][j] + 1;
		}
	}
	return a;
}

SquareMat SquareMat::operator~()const {
	SquareMat a(*this);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			a.mat[i][j] = this->mat[j][i];
		}
	}
	return a;
}

SquareMat SquareMat::operator^(double x) const
{
	SquareMat a(*this);
	for (int i = 0; i< x; i++) {
		a = ((*this) * (*this));
	}
}

double SquareMat::sum() const // check the sum of the Mat
{
	double sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++) {
			sum = sum + this->mat[i][j];
		}
	}
	return sum;
}

bool SquareMat:: operator== (const SquareMat& a)const {
	if (this->sum() == a.sum()) {
		return true;
	}
	 return false;
}
bool SquareMat:: operator!= (const SquareMat& a)const {
	if (this->sum() == a.sum()) {
		return false;
	}
	return true;
}
bool SquareMat:: operator< (const SquareMat & a)const {
	if (this->sum() < a.sum()) {
		return true; 
	}
	return false;
}
bool SquareMat:: operator> (const SquareMat& a)const {
	if (this->sum() > a.sum()) {
		return true;
	}
	return false;
}
bool SquareMat:: operator<= (const SquareMat& a)const {
	if (*this == a) { return true; }
	if (this->sum() < a.sum()) {
		return true;
	}
	return false;
}
bool SquareMat:: operator>= (const SquareMat& a)const {
	if (*this == a) { return true; }
	if (this->sum() < a.sum()) {
		return false;
	}
	return true;
}
const double* SquareMat::operator[](int i)const {
	if(i>= this->size || i<0) { throw std::invalid_argument("index out of bounds "); }
	return this->mat[i];
}

SquareMat SquareMat::operator*(const SquareMat& a) const
{
	double sum = 0;
	SquareMat b(*this); // we override b!
	for (size_t i = 0; i < a.size; i++)
	{
		for (size_t j = 0; j < a.size; j++) {
			for (size_t z = 0; z < a.size; z++) {
				sum += this->mat[i][z] * a.mat[z][j];
			}
			b.mat[i][j] = sum;
			sum = 0;
		}
	}
	return b;
}


