#include"String.h"

///////////////////////////////////////////////////////////////////////
/////////////////  ������������ ������ (Class definition)  ////////////
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
String::String(int size) : size(size), str(new char[size] {}) //size - �������� �� ���������
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
	int i = 0;// �������� ���������� ��� ���� ����� ����� ������� �������� i ����� for;
	for (; str[i]; i++); //����� � ������� ����� �����
	//return i ��������� �������� i ����� ���� ��� ����������� ���� for;
	//���� return i ����� � ���� �����, �� i ��������� 0;
	// str[i] - �������� �������� ������� �� �������;
	// ���� � �������� ������� ���� ������ (�� '\0') �� ������������ true => ��� ������ 'i' ����������� �� 1;
	// ���� str[i] = '\0' ������������ false => return i;
	return i;
}

////////////////////////////////////////////////////////////////////////////////////
////////////// ����� ����������� ������ (Class Definishion END) ////////////////////
////////////////////////////////////////////////////////////////////////////////////