#include<iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

class String;
int strlength(const char* str);
std::ostream& operator << (std::ostream& os, const String& obj);

class String
{
	int size; //Размер строки в байтах
	char* str;//Адрес строки в динамической памяти
public:
	//             Constructors:
	explicit String(int size = 80) //size - параметр по умолчанию
	{
		this->size = size; // c помощью size можно создать строку нужного размера
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1; //размер строки в байтах с учётом терменирующего нуля, поэтому + 1;
		//strlen() - функция которая считает размер строки в символах без терменирующего нуля '\0'
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		//Deep copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:\t\t" << this << endl;
	}
	~String()
	{
		delete[]this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	//           Operators:
	String& operator = (const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	//             Methods:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	int get_size()const
	{
		return size;
	}
	void print()const
	{
		cout << "Obj:\t" << this << endl;
		cout << "Size:\t" << size << endl;
		cout << "Addr:\t" << &str << endl;
		cout << "Str:\t" << str << endl;
	}
};

//#define CAT_CHECK
#define CONSTRUCTORS_CHECK

String operator + (const String& left, const String& right)
{
	String buffer(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		buffer.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return buffer;
}
std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef CAT_CHECK
	//String str; str.print(); //Default Constructor
	String str1 = "Hello"; //Single-argument Constructor
	String str2 = "World";
	/*cout << "strlengh = " << strlength("Helloooooooo");
	cout << endl;*/
	cout << str1 << endl;
	cout << str2 << endl;
	str1 = str1;
	String str3 = str1 + " " + str2; // С пробелом;
	str3.print();//CopyConstructor
	str3 = str1 + str2;  //CopyAssigment
	str3.print();
#endif // CAT_CHECK

#ifdef CONSTRUCTORS_CHECK
	String str1;           //Default constructor
	str1.print();

	String str2(8);        //Single-Argument Constructor
	str2.print();

	String str3 = "Hello"; //Single-Argument Constructor
	str3.print();

	//String str4();       Здеесь НЕ вызывается конструктор и не создаётся объект, в этом выражении объявляется функция str4(),
    //которая ничего не принимает, и возвращает объект класса 'String'.

	String str5{};        //Явный вызов конструктора по умолчанию
	str5.print();

	String str6{ str3 };   //Copy Constructor
	str6.print();
#endif // CONSTRUCTORS_CHECK

}

int strlength(const char* str)
{
	int i = 0;// объявили глобальной для того чтобы могли вернуть значение i после for;
	for (; str[i]; i++); //точка с запятой нужна чтобы
	//return i возвращал значение i после того как выполниться цикл for;
	//если return i будет в теле цикла, то i возвратит 0;
	// str[i] - значение элемента массива по индексу;
	// если в элементе массива есть символ (не '\0') то возвращается true => идём дальше 'i' увеличиваем на 1;
	// если str[i] = '\0' возвращается false => return i;
	return i;
}