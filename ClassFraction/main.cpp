#include<iostream>
using namespace std;

#define delimeter "\n-------------------------------\n"

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
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
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//       Constructors:
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//           Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator++()//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)//Postfix increment
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()//Prefix decrement
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)//Postfix decrement
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	Fraction& operator += (int rvalue)
	{
		this->integer = integer + rvalue;
		return *this;
	}
	Fraction& operator -= (int rvalue)
	{
		this->integer = integer - rvalue;
		return *this;
	}
	Fraction& operator += (Fraction& right)
	{
		Fraction old = *this;
		old.to_improper();
		right.to_improper();
		numerator = old.numerator * right.denominator + old.denominator * right.numerator;
		denominator = old.denominator * right.denominator;
		integer = 0;
		to_proper();
		reduction();
		return old;
	}
	Fraction& operator -= (Fraction& right)
	{
		Fraction old = *this;
		old.to_improper();
		right.to_improper();
		numerator = old.numerator * right.denominator - old.denominator * right.numerator;
		denominator = old.denominator * right.denominator;
		integer = 0;
		to_proper();
		reduction();
		return old;
	}
	Fraction& operator *= (int rvalue)
	{
		to_improper(); numerator = numerator * rvalue;
		to_proper();
		reduction();
		return *this;
	}
	Fraction& operator /= (int rvalue)
	{
		to_improper(); denominator = denominator * rvalue;
		to_proper();
		reduction();
		return *this;
	}
	Fraction& operator *= (Fraction& right)
	{

	}

	//              Methods:
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator); // swap - меняет местами элементы
		return inverted;
	}
	Fraction& reduction()
	{
		int i = 0, j = 0;
		while (i == 0 || j == 0)
		{
			if (numerator & 1 != 0 || denominator & 1 != 0)break;
			i = numerator & 1;
			j = denominator & 1;
			numerator = numerator >> 1;
			denominator = denominator >> 1;
		}
		return *this;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};

Fraction operator* (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/ (const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
Fraction operator+ (Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		(left.get_numerator() * right.get_denominator()) + (left.get_denominator() * right.get_numerator()),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduction();
}
Fraction operator- (Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		(left.get_numerator() * right.get_denominator()) - (left.get_denominator() * right.get_numerator()),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduction();
}

//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;  //Default constructor
	A.print();

	Fraction B = 5; //Single - argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK
	Fraction A(2, 4, 8);
	A.print();

	/*Fraction B(2, 2, 8);
	B.print();*/

	A /= 2;
	A.print();

	

}
