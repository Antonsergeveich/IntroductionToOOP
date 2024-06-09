#include<iostream>
using namespace std;

int strlength(const char* str);

class String
{
	int size; //Размер строки в байтах
	char* str;//Адрес строки в динамической памяти
public:
	//             Constructors:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		int size = strlength(str);
		this->str = new char[size+1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		this->str[size] = '\0';
	}
	~String()
	{
		delete[]this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//             Methods:
	char get_str()const
	{
		return *str;
	}
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*String str;
	str.print();*/
	String str1 = "Hello";
	String str2 = "World";
	cout << str1 << endl;
	cout << str2 << endl;
	String str3 = str1 + str2;
	cout << str3 << endl; //HelloWorld
}

String operator + ( const String& left,  String& right)
{
	int l = left.get_str();
	int r = right.get_str();
	String str_new = new char[l+r+1];
	for (int i = 0; i < l; i++)
	{
		str_new[i] = left[i];

	}
}
int strlength(const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)return i;
}