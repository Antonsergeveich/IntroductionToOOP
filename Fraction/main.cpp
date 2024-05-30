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
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
	}
	void Print()const
	{
		cout << "Integer = \t" << integer << endl;
		cout << "Numerator = \t" << numerator << endl;
		cout << "Denominator = \t" << denominator << endl;
	}
};



void main()
{
	setlocale(LC_ALL, "");
	Fraction fract_1(0,2,3);
	fract_1.Print();
	cout << delimeter << endl;
	Fraction fract_2(0,3,4);
	fract_2.Print();
	cout << delimeter << endl;
	
	
}