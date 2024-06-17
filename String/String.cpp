#include"String.h"

///////////////////////////////////////////////////////////////////////
/////////////////  Определеение класса (Class definition)  ////////////
///////////////////////////////////////////////////////////////////////

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
void String::print()const
{
	cout << "Obj:\t" << this << endl;
	cout << "Size:\t" << size << endl;
	cout << "Addr:\t" << &str << endl;
	cout << "Str:\t" << str << endl;
}
String::String(int size) : size(size), str(new char[size] {}) //size - параметр по умолчанию
{
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char str[]) : String(strlen(str) + 1)
{
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstructor:\t\t" << this << endl;
}
String :: ~String()
{
	delete[]this->str;
	cout << "Destructor:\t\t" << this << endl;
}
String& String :: operator = (const String& other)
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

////////////////////////////////////////////////////////////////////////////////////
////////////// Конец определения класса (Class Definishion END) ////////////////////
////////////////////////////////////////////////////////////////////////////////////