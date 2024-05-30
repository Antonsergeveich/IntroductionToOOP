#include<iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

#define delimeter "\n-------------------------------\n"

class Fraction
{
	int numerator;    //числитель
	int denominator;  //знаменатель
	int integer;      //целое число
public:
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 0;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
	}

	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}
	void Print()const
	{
		cout << "Integer = \t" << integer << endl;
		cout << "Numerator = \t" << numerator << endl;
		cout << "Denominator = \t" << denominator << endl;
	}
};

Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator(left.get_numerator()*right.get_denominator()+right.get_numerator()*left.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}

void main()
{
	setlocale(LC_ALL, "");
	Fraction f1(1, 2, 3);
	f1.Print();
	cout << delimeter << endl;
	Fraction f2(1, 2, 3);
	f2.Print();
	cout << delimeter << endl;
	Fraction f3 = f1 + f2;
	f3.Print();
}