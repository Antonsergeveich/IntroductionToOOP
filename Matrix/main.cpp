#include<iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

class Matrix
{
	int rows;
	int cols;
	int** arr;
public:
	int get_rows()const
	{
		return rows;
	}
	int get_cols()const
	{
		return cols;
	}
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		this->arr = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int[cols] {};
		}
		cout << "Constructor:\t" << this << endl;
	}
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete arr[i];
		}
		delete[] arr;
		rows = 0;
		cols = 0;
		arr = nullptr;
		cout << "Destructor:\t" << this << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

}