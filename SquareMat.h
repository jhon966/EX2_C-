#pragma once
#include "iostream"
#include "stdexcept"
class SquareMat {
private:
	int size;
	double** mat;

public:
	SquareMat(int num); // constructor 
	~SquareMat();// destructor
	SquareMat(const SquareMat& other ); // copy constructor
	SquareMat& operator=(const SquareMat& other);
	friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);// copy assigment  operator 
	SquareMat operator+(const SquareMat& b);
	void operator-()const ;
	SquareMat operator-(const SquareMat& b);
	SquareMat operator*(double x);
	SquareMat operator* (const SquareMat& a)const;
	friend SquareMat operator*(double x, const SquareMat& a);
	SquareMat operator/(double x);
	SquareMat operator%(const SquareMat& b);
	SquareMat operator%(double x);
	SquareMat& operator++();
	SquareMat operator++(int x);
	SquareMat operator--(int);
	SquareMat& operator--();
	SquareMat operator~() const;
	SquareMat operator^(double x)const;
	double sum()const ;
	bool operator== (const SquareMat& a)const;
	bool operator!= (const SquareMat& a)const;
	bool operator<(const SquareMat& a) const;
	bool operator>(const SquareMat& a) const;
	bool operator<=(const SquareMat& a) const;
	bool operator>=(const SquareMat& a) const;

	const double* operator[](int i) const;
};