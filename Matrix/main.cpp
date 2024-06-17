#include<iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

class Matrix;

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
	int get_arrij(int i, int j)
	{
		return arr[i][j];
	}
	void set_rows(int rows)
	{
		this->rows = rows;
	}
	void set_cols(int cols)
	{
		this->cols = cols;
	}
	void set_arrij(int i, int j, int value)
	{
		arr[i][j] = value;
	}
	Matrix()
	{
		rows = 0;
		cols = 0;
		arr = nullptr;
		cout << "DefaultConstructor\t" << this << endl;
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
		cout << "BinaryConstructor:\t" << this << endl;
	}
	Matrix(const Matrix& other)
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->arr = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			this->arr[i] = new int[cols];
			for (int j = 0; j < cols; j++)
			{
				this->arr[i][j] = other.arr[i][j];
			}
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	Matrix& operator = (const Matrix& other)
	{
		if (this == &other)return *this;
		for (int i = 0; i < rows; i++)
		{
			delete arr[i];
		}
		delete[] arr;
		this->rows = other.rows;
		this->cols = other.cols;
		this->arr = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			this->arr[i] = new int[cols];
			for (int j = 0; j < cols; j++)
			{
				this->arr[i][j] = other.arr[i][j];
			}
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete arr[i];
		}
		delete[] arr;
		cout << "Destructor:\t" << this << endl;
	}
	void FillRand()const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = rand() % 100;
			}
		}
	}
	void print()const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Matrix A(2, 3);
	A.FillRand();
	A.print();
	Matrix B(A);
	B.print();
	Matrix C;
	C = B;
	C.print();
}