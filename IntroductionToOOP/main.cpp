#include<iostream>
using namespace std;

using std::endl;
using std::cin;
using std::cout;

#define DELIMETER  "\n-----------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	// Constructors:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl; //Конструктор по умолчанию
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl; //
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//Operators:
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& operator++()//Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)//Postfix increment
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	//Methods:
	double distance(const Point& other)const
	{
		//this - этот; эта точка;
		//other - другой; та точка;
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << this << ":X = " << x << "\tY = " << y << endl;
	}
};

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

Point operator-(const Point& left, const Point& right)
{
	Point result
	{
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	};
	return result;
}

Point operator*(const Point& left, const Point& right)
{
	return Point
	{
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	};
}

Point operator/(const Point& left, const Point& right)
{
	Point result
	{
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()
	};
	return result;
}

bool operator==(const Point& left, const Point& right)
{
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else return false;*/
}

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
	//Функция sqrt возвращает квадратный корень принятого числа
}

//#define STRUCT_POINT
//#define DISTANCE_CHEK
//#define CONSTRUCTORS_CHEK
//#define ASSIGNMENT_CHECK
//#define ARIFMETICAL_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << "Hello OOP" << endl;
	//Point A{};//Объявление переменной 'A' типа 'Point'
	//Создание объекта 'A' структуры 'Point'
	//Создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A; //Pointer to 'A'
	cout << pA << endl;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT
#ifdef DISTANCE_CHEK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << DELIMETER << endl;
	cout << "Расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	cout << DELIMETER << endl;
	cout << "Расстояние от точки 'B' до точки 'A': " << B.distance(A) << endl;
	cout << DELIMETER << endl;
	cout << "Расстояние между точками 'A' и 'B': " << distance(B, A) << endl;
	cout << DELIMETER << endl;
	cout << "Расстояние между точками 'B' и 'A': " << distance(A, B) << endl;
	cout << DELIMETER << endl;
#endif // DISTANCE_CHEK
#ifdef CONSTRUCTORS_CHEK
	Point A; //Default constructor
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);//Constructor
	C.print();

	Point D = C; // Copy constructor
	D.print();
#endif // CONSTRUCTORS_CHEK
#ifdef ASSIGNMENT_CHECK
	//Point A(2, 3); //Constructor
	//Point B;       //Default constructor
	//B = A;         //Copy assignment
	//B.print();
		/*int a, b, c;
		a = b = c = 0;
		cout << a << "\t" << b << "\t" << c << endl;*/
	Point A, B, C;
	cout << DELIMETER << endl;
	A = B = C = Point(2, 3);
	cout << DELIMETER << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK
#ifdef ARIFMETICAL_OPERATORS_CHECK
	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();

	Point C = B * A;
	C.print();

	C++;
	C.print();
#endif // ARIFMETICAL_OPERATORS_CHECK

	//cout << (2 == 3) << endl;
	cout << (Point(2, 3) == Point(2, 3)) << endl;
}
/*
------------------------------------------------
.  - Оператор прямого доступа (Point operator)
	 Используется для доступа к полям объекта по имени объекта.
-> - Оператор косвенного доступа (Arrow operator)
	 Используется для доступа к полям объекта по адресу объекта.
------------------------------------------------
*/

/*
------------------------------------------------
			OOP concepts
1. Инкапсуляция (Encapsulation) - это сокрытие определенной части класса от внешнего мира;
	Модификаторы доступа:
		private:	закрытые поля, к ним можно получить доступ только внутри класса;
		public:		открытые поля, к ним можно получить доступ откуда угодно;
		protected:	защищенные поля. Этот модификатор доступа используется только при наследовании.
					protected-поля доступны внутри нашего класса, и его дочерних классов.

		get/set-методы позволяеют получить доступ к закрытым переменным в классе.
		get (взять, получить) методы	- открывают доступ к закрытым переменным на чтение,
										  т.е., позволяют ВЗЯТЬ(ПОЛУЧИТЬ) значение закрытой переменной;
		set (задать, установить) методы - открывают доступ к закрытым переменным на запись,
										  т.е., позволяют задать значения закрытых переменных.
										  Кроме того, set-методы обеспечиваю фильтрацию данных,
										  т.е., предотвращают попадание некорректных значений
										  в переменные члены класса.

2. Наследование (Inheritance);
3. Полиморфизм  (Polymorphism);
------------------------------------------------
*/

/*
------------------------------------------------
1. Constructor - это метод, который создает объект, а именно,
   выделяет память под объект, и инициализирует его поля при создании;
	-с параметрами;
	-без параметров;
	-конструктор по умолчанию (Default constructor);
	-конструктор копирования; (CopyConstructor);
		Побитовое копирование	(Deep copy);
		Повехностное копирование(Shallow copy); Debug assertion failed
	-конструктор переноса;
2. ~Destructor  - это метод, который уничтожает объект по завершении его времени жизни.
3. Assignment operator; Оператор присваивания - побитово копирует обЪект после его создания;
Конструктор копирования может быть вызван только при создании объекта.
Его невозможно вы звать после создания объекта.
И для того чтобы скопировать объект после его создания используетсяоператор присваивания
Оператор присваивания делает тоже самое что и конструктор копирования, но уже после создан ия объекта
А именно существующий объект делает точной копией другого существующего объекта
При  возврате значения по значению оно копируется на место вызова. И если возвращаемое значение объект
то для этого вызывается конструктор копирования.
Для того чтобы возвращаемое значение не копировалось на место вызова его можно вернуть по указателю либо по ссылке.
Тогда на место вызова скопируется не само возвращаемое значение, а его адрес,
т.е. в случае с объектом конструктор копирования вызываться не будет
------------------------------------------------
*/