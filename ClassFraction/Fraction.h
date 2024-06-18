#pragma once
#include"StdAfx.h"

class Fraction;

bool operator == (Fraction left, Fraction right);
bool operator != (const Fraction& left, const Fraction& right);
bool operator > (Fraction left, Fraction right);
bool operator < (Fraction left, Fraction right);
bool operator >= (const Fraction& left, const  Fraction& right);
bool operator <= (const Fraction& left, const Fraction& right);

Fraction operator* (Fraction left, Fraction right);
Fraction operator/ (const Fraction& left, const Fraction& right);
Fraction operator+ (Fraction& left, Fraction& right);
Fraction operator- (Fraction& left, Fraction& right);

std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	Fraction& operator=(const Fraction& other);
	Fraction& operator *= (const Fraction& other);
	Fraction& operator /= (const Fraction& other);
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
	Fraction& operator += (int rvalue);
	Fraction& operator -= (int rvalue);
	Fraction& operator += (Fraction& other);
	Fraction& operator -= (Fraction& other);
	explicit operator int();
	explicit operator double();
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction inverted()const;
	Fraction& reduction();
	void print()const;
};