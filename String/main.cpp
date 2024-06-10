#include<iostream>
using namespace std;

class String;
//int strlength(const char* str);
std::ostream& operator << (std::ostream& os, const String& obj);

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
		int size = strlen(str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		this->str[size] = '\0';
		cout << "1ArgConstructor:\t\t" << this << endl;
	}
	~String()
	{
		delete[]this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//             Methods:
    char* get_str()const
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};
std::ostream& operator << (std::ostream& os, const String& obj)
{
	os << obj.get_str();
	return os;
}
void main()
{
	setlocale(LC_ALL, "");
	/*String str;
	str.print();*/
	String str1 = "Hello";
	String str2 = "World";
	cout << str1 << endl;
	cout << str2 << endl;
	//String str3 = str1 + str2;
	//cout << str3 << endl; //HelloWorld
}


//int strlength(const char* str)
//{
//	for (int i = 0; str[i] != '\0'; i++)return i;
//}