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

	Fraction& operator = (const Fraction& fract)
	{
		this->integer = fract.integer;
		this->numerator = fract.numerator;
		this->denominator = fract.denominator;
		return *this;
	}
	Fraction& operator ++()//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator ++(int)//Postfix increment
	{
		Fraction old = *this;
		integer++;
		return old;
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

Fraction operator+(const Fraction& left, const Fraction& right) //сложение дробей
{
	Fraction result;
	result.set_numerator(((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator()) + ((right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator()));
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.set_integer(result.get_numerator() / result.get_denominator());
	int n = result.get_numerator(); int d = result.get_denominator(); int i = result.get_integer();
	if ((n > d) || (i == 0))
	{
		result.set_numerator(result.get_numerator() - result.get_integer() * result.get_denominator());
	}
	return result;
}
Fraction operator+(const Fraction& left, const int value) //сложение дроби с целым числом
{
	Fraction result;
	result.set_integer(left.get_integer() + value);
	result.set_numerator(left.get_numerator());
	result.set_denominator(left.get_denominator());
	return result;
}
Fraction operator/(const Fraction& left, const int value) //деление дроби на целое число
{
	Fraction result;
	int n = result.get_numerator(); int d = result.get_denominator(); int i = result.get_integer();
	result.set_numerator((left.get_numerator() + (left.get_denominator() * left.get_integer())) * 1);
	result.set_denominator(left.get_denominator() * value);
	result.set_integer(result.get_numerator() / result.get_denominator());
	if ((n > d) || (i == 0))
	{
		result.set_numerator(result.get_numerator() - result.get_integer() * result.get_denominator());
	}
	return result;
}

Fraction operator/(const Fraction& left, const Fraction& right) //деление дробей
{
	Fraction result;
	result.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator());
	result.set_denominator((right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator());
	result.set_integer(result.get_numerator() / result.get_denominator());
	int n = result.get_numerator(); int d = result.get_denominator(); int i = result.get_integer();
	if ((n > d) || (i == 0))
	{
		result.set_numerator(result.get_numerator() - result.get_integer() * result.get_denominator());
	}
	return result;
}

void main()
{
	setlocale(LC_ALL, "");
	Fraction F1(2,1,2);
	F1.Print();
	cout << delimeter << endl;
	Fraction F2(1,3,4);
	F2.Print();
	cout << delimeter << endl;
	F1 = F1 + 2;
	F1.Print();
	cout << delimeter << endl;
	Fraction F3 = F1 / F2;
	F3.Print();
	/*cout << delimeter << endl;
	F1++;
	F1.Print();
	cout << delimeter << endl;
	++F1;
	F1.Print();
	cout << delimeter << endl;
	F1 = F1 / 2;
	F1.Print();*/
}