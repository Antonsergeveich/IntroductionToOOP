#pragma once
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

///////////////////////////////////////////////////////////
////// ���������� ������ (Class Declaration)
///////////////////////////////////////////////////////////


class String;
int strlength(const char* str);
std::ostream& operator << (std::ostream& os, const String& obj);
String operator + (const String& left, const String& right);

class String
{
	int size; //������ ������ � ������
	char* str;//����� ������ � ������������ ������
public:
	//             Methods:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	void print()const;

	//             Constructors:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	~String();
	//           Operators:
	String& operator = (const String& other);
};

///////////////////////////////////////////////////////////
////// ����� ���������� ������ (Class Declaration End)
///////////////////////////////////////////////////////////
