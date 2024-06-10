#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#define delimiter "\n---------------------------------\n"
#define double_delimiter "\n================================\n"

class Fraction;
Fraction operator* (Fraction left, Fraction right);
Fraction operator/ (const Fraction& left, const Fraction& right);
Fraction operator+ (Fraction& left, Fraction& right);
Fraction operator- (Fraction& left, Fraction& right);

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
	explicit Fraction(int integer)//Single-argument Constructor
	{
		//explicit - явный
		//implicit - неявный
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;// означает $1 000 000 000, один и девять нулей после единицы
		// потомучто int 4 294 967 295(в этом числе 9 разрядов которые изменяются от 0 до 9) 
		numerator = decimal * denominator;
		reduction();
		cout << "Consttructor:\t" << this << endl;
	}
	//explicit Fraction(double value)//Single-argument Constructor
	//{
	//	this->integer = (int)value;
	//	double x = value - integer;
	//	int y = x;
	//	denominator = 10;
	//	while (x - y >= 0.0000001)
	//	{
	//		x = x * 10;
	//		y = x;
	//		if (x - y <= 0.0000001)break;
	//		denominator *= denominator;
	//	}
	//	this->numerator = x;
	//	this->denominator = denominator;
	//	cout << "2ArgConstructor:\t" << this << endl;
	//}
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
		cout << "Destructor:\t\t" << this << endl;
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
	Fraction& operator *= (const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator /= (const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator++()//Prefix increment
	{
		// Если переменная возвращается по ссылке, 
		// то это полноценный объект к которому можно применить операторы 
		// которые будут его изменять
		integer++;
		return *this;
	}
	Fraction operator++(int)//Postfix increment
	{
		// Если значение возвращается по значению,
		// на месте вызова создаётся 
		// ВРЕМЕННЫЙ БЕЗЫМЯННЫЙ ОБЪЕКТ
		// он существует только в пределах этого выражения где функция вернула значение
		// Временный безымянный объект является константным
		// а константу изменить нельзя
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
	Fraction& operator += (Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator -= (Fraction& other)
	{
		return *this = *this - other;
	}
	//Type-cast operators:
	/*
	--------------------------------------------
	operator type()
	{
		.....;
		.....;
		return value;
	}
	--------------------------------------------
	*/
	explicit operator int()
	{
		return integer;
	}
	explicit operator double()
	{
		return integer + (double)numerator / denominator;
		/*double a;
		to_improper();
		a = (double)numerator / denominator;
		return a;*/
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
		//https://www.webmath.ru/poleznoe/formules_12_7.php
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else more = denominator, less = numerator;
		do
		{
			rest = more % less;//остаток
			more = less;//большее
			less = rest;//меньшее
		} while (rest);
		int GCD = more; //GCD - Greatest Common Divesor
		numerator /= GCD;
		denominator /= GCD;
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
//Stream - поток
//std - Standard namespace
//:: - SCOPE OPERATOR (Оператор разрешения видимости) позволяет зайти в пространство имён
//Сам по себе '::' вводит нас в GlobalScope (Глобальное пространство имён)
//namespace (пространство имён) как папка, а имя, расположенное в нём как файл
//ostream - output stream (поток вывода)
//cout - Console Out
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
	//istream - input sream (поток ввода)
	//cin - Console In
	const int SIZE = 32;
	char buffer[SIZE]{};
	//is >> buffer;
	is.getline(buffer, SIZE);// Если мы хотим вводить через пробел
	//то нужно написать функцию getline()
	int number[3];
	int n = 0;
	const char delimiters[] = "(/) +";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		//Функция strtok() разделяет строку на токены: Токен - это то что нужно достать из строки;
		//https://legacy.cplusplus.com/reference/cstring/strtok/
		// Функция strtok() ИЗМЕНЯЕТ ВХОДНУЮ СТРОКУ !!!
		number[n++] = atoi(pch);
	//pch - Pointer to Character (Указатель на символ)
	//Функция atoi() - "ASCII string to int" принимает строку,
	//https://legacy.cplusplus.com/reference/cstdlib/atoi/
	//и возвращает значение типа int найденное в этой строке;
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	switch (n)
	{
	case 1: obj = Fraction(number[0]); break;
	case 2: obj = Fraction(number[0], number[1]); break;
	case 3: obj = Fraction(number[0], number[1], number[2]); break;
	}
	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK;
//#define STREAM_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERTIONS_FROM_CLASS_TO_OTHER
//#define CONVERSIONS_TASK_1
#define CONVERSIONS_TASK_2

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
#ifdef ARITHMETICAL_OPERATORS_CHECK
	//double a = 2;
	//double b = 3;
	//double c = a * b;

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*Fraction C = A / B;
	C.print();
	(C++).print();
	C.print();

	A.print();
	B.print();*/

	A *= B;		//A = A*B;
	A.print();

	A /= B;
	A.print();

	//int a = 2;
	//int* pa = &a;
	////a = pa;
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++a;
	////a++++++++++++++++++++++++++++++++++++++++++++++++++++++++++;
	//cout << a << endl;  
#endif // ARITHMETICAL_OPERATORS_CHECK
#ifdef COMPARISON_OPERATORS_CHECK
	//cout << (2 == 3) << endl;
	cout << (Fraction(1, 2) >= Fraction(5, 10)) << endl;
#endif // COMPERISON_OPERATORS_CHECK
#ifdef STREAM_CHECK
	Fraction A(2, 3, 4);
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
#endif // STREAM_CHECK
#ifdef TYPE_CONVERSIONS_BASICS
	//(type)value;	C-like notation		(C-подобная форма записи)
	//type(value);	Functional notation	(Функицональная форма записи)
	//int a = 2.5;
	//C4244: Conversion from 'type_1' to 'type_2', possible loss of data;
	//		l-value = r-value;

	int a = 2;		//No conversions
	double b = 3;	//Conversion from less to more
	int c = b;		//Conversion from more to less without data loss
	int d = 2.5;	//Conversion from more to less with data loss
	cout << sizeof(int) << endl;
	cout << sizeof(double) << endl;
#endif // TYPE_CONVERSIONS_BASICS
#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	/*
----------------------------------
1. From other to Class:
	- Single-argument constructor;
	- CopyAssignment;
2. From Class to other;
----------------------------------
*/
	Fraction A = (Fraction)5;	//Convertion from 'int' to 'Fraction'
	//Single-Argument constructor
	cout << A << endl;
	cout << double_delimiter << endl;
	Fraction B;	//Default constructor
	cout << delimiter << endl;
	B = Fraction(8);		//Convertion from 'int' to Fraction
	//Single-Argument constructor
	//Copy assignment
	cout << delimiter << endl;
	cout << B << endl;
	cout << double_delimiter << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS
#ifdef CONVERSIONS_TASK_1
	Fraction A(2, 3, 4);
	cout << A << endl;
	//int a = (int)A;
	double a = double(A);
	cout << a << endl;
#endif // CONVERTIONS_TASK_1
#ifdef CONVERSIONS_TASK_2
	Fraction B = (Fraction)2.75;
	cout << B << endl;
#endif // CONVERSION_TASK_2
}