#include"Fraction.h"
int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
Fraction::Fraction()
{
	integer = 0;
	numerator = 0;
	denominator = 1;
	cout << "DefaultConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer)//Single-argument Constructor
{
	//explicit - �����
	//implicit - �������
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "1ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(double decimal)
{
	decimal += 1e-10; // 0,0000000001 �� ������� ������� �� ����� ���������
	//����������� �� ���� �������� ������� ��� ����� 
	integer = decimal;
	decimal -= integer;
	denominator = 1e+9;// �������� 1 000 000 000, ���� � ������ ����� ����� �������
	// ��������� int 4 294 967 295(� ���� ����� 9 �������� ������� ���������� �� 0 �� 9) 
	numerator = decimal * denominator;
	reduction();
	cout << "Consttructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction :: ~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}
Fraction& Fraction :: operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
Fraction& Fraction :: operator *= (const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction :: operator /= (const Fraction& other)
{
	return *this = *this / other;
}
Fraction& Fraction :: operator++()//Prefix increment
{
	// ���� ���������� ������������ �� ������, 
	// �� ��� ����������� ������ � �������� ����� ��������� ��������� 
	// ������� ����� ��� ��������
	integer++;
	return *this;
}
Fraction Fraction :: operator++(int)//Postfix increment
{
	// ���� �������� ������������ �� ��������,
	// �� ����� ������ �������� 
	// ��������� ���������� ������
	// �� ���������� ������ � �������� ����� ��������� ��� ������� ������� ��������
	// ��������� ���������� ������ �������� �����������
	// � ��������� �������� ������
	Fraction old = *this;
	integer++;
	return old;
}
Fraction& Fraction ::operator--()//Prefix decrement
{
	integer--;
	return *this;
}
Fraction Fraction :: operator--(int)//Postfix decrement
{
	Fraction old = *this;
	integer--;
	return old;
}
Fraction& Fraction :: operator += (int rvalue)
{
	this->integer = integer + rvalue;
	return *this;
}
Fraction& Fraction :: operator -= (int rvalue)
{
	this->integer = integer - rvalue;
	return *this;
}
Fraction& Fraction :: operator += (Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction :: operator -= (Fraction& other)
{
	return *this = *this - other;
}
Fraction :: operator int()
{
	return integer;
}
Fraction :: operator double()
{
	return integer + (double)numerator / denominator;
	/*double a;
	to_improper();
	a = (double)numerator / denominator;
	return a;*/
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator); // swap - ������ ������� ��������
	return inverted;
}
Fraction& Fraction::reduction()
{
	//https://www.webmath.ru/poleznoe/formules_12_7.php
	int more, less, rest;
	if (numerator > denominator)more = numerator, less = denominator;
	else more = denominator, less = numerator;
	do
	{
		rest = more % less;//�������
		more = less;//�������
		less = rest;//�������
	} while (rest);
	int GCD = more; //GCD - Greatest Common Divesor
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
void Fraction::print()const
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

bool operator == (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}
bool operator != (const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator > (Fraction left, Fraction right)
{
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator < (Fraction left, Fraction right)
{
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator >= (const Fraction& left, const  Fraction& right)
{
	return!(left < right);
	//return left > right || left == right;
}
bool operator <= (const Fraction& left, const Fraction& right)
{
	return!(left > right);
	//return left < right || left == right;
}
Fraction operator* (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduction();
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
	).to_proper();
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
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	//istream - input sream (����� �����)
	//cin - Console In
	const int SIZE = 32;
	char buffer[SIZE]{};
	//is >> buffer;
	is.getline(buffer, SIZE);// ���� �� ����� ������� ����� ������
	//�� ����� �������� ������� getline()
	int number[3];
	int n = 0;
	const char delimiters[] = "(/) +";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		//������� strtok() ��������� ������ �� ������: ����� - ��� �� ��� ����� ������� �� ������;
		//https://legacy.cplusplus.com/reference/cstring/strtok/
		// ������� strtok() �������� ������� ������ !!!
		number[n++] = atoi(pch);
	//pch - Pointer to Character (��������� �� ������)
	//������� atoi() - "ASCII string to int" ��������� ������,
	//https://legacy.cplusplus.com/reference/cstdlib/atoi/
	//� ���������� �������� ���� int ��������� � ���� ������;
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	switch (n)
	{
	case 1: obj = Fraction(number[0]); break;
	case 2: obj = Fraction(number[0], number[1]); break;
	case 3: obj = Fraction(number[0], number[1], number[2]); break;
	}
	return is;
}