#include"Fraction.h"

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
	Fraction B = (Fraction)3.14;
	cout << B << endl;
#endif // CONVERSION_TASK_2
}