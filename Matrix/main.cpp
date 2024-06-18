#include<iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

#define delimeter "\n-------------------------------\n"

class Matrix;

Matrix operator + (Matrix& left, Matrix& right);
Matrix operator - (Matrix& left, Matrix& right);
Matrix operator * (Matrix& left, Matrix& right);
std::ostream& operator <<(std::ostream& os, const Matrix& obj);

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
	int** get_arr()const
	{
		return arr;
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
	void set_arrij(int i, int j, double value)
	{
		arr[i][j] = value;
	}
	void set_arr()
	{
		arr = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int [cols] {};
		}
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
			this->~Matrix();
		/*{
			delete arr[i];
		}
		delete[] arr;*/
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
	Matrix A(3, 4);
	A.FillRand();
	A.print();
	cout << delimeter << endl;
	//cout << A.get_arrij(2, 3) << endl;
	cout << A ;
	/*cout << delimeter << endl;
	Matrix B(A);
	B.print();
	cout << delimeter << endl;
	Matrix C;
	C = B;
	C.print();
	cout << delimeter << endl;
	Matrix D;
	D = A + B;
	D.print();
	cout << delimeter << endl;
	Matrix E;
	E = D - A;
	E.print();
	cout << delimeter << endl;
	Matrix F;
	F = A * B;
	F.print();
	cout << delimeter << endl;*/
}

Matrix operator + (Matrix& left, Matrix& right)
{
	Matrix buffer;
	if (left.get_rows() == right.get_rows() && left.get_cols() == right.get_cols())
	{
		buffer.set_rows(left.get_rows());
		buffer.set_cols(left.get_cols());
		buffer.set_arr();

		for (int i = 0; i < buffer.get_rows(); i++)
		{
			for (int j = 0; j < buffer.get_cols(); j++)
			{
				buffer.set_arrij(i, j, left.get_arrij(i, j) + right.get_arrij(i, j));
			}
		}
	}
	return buffer;
}
Matrix operator - (Matrix& left, Matrix& right)
{
	Matrix buffer;
	if (left.get_rows() == right.get_rows() && left.get_cols() == right.get_cols())
	{
		buffer.set_rows(left.get_rows());
		buffer.set_cols(left.get_cols());
		buffer.set_arr();

		for (int i = 0; i < buffer.get_rows(); i++)
		{
			for (int j = 0; j < buffer.get_cols(); j++)
			{
				buffer.set_arrij(i, j, left.get_arrij(i, j) - right.get_arrij(i, j));
			}
		}
	}
	return buffer;
}
Matrix operator * (Matrix& left, Matrix& right)
{
	Matrix buffer;
	if (left.get_rows() == right.get_rows() && left.get_cols() == right.get_cols())
	{
		buffer.set_rows(left.get_rows());
		buffer.set_cols(left.get_cols());
		buffer.set_arr();

		for (int i = 0; i < buffer.get_rows(); i++)
		{
			for (int j = 0; j < buffer.get_cols(); j++)
			{
				buffer.set_arrij(i, j, left.get_arrij(i, j) * right.get_arrij(i, j));
			}
		}
	}
	return buffer;
}
std::ostream& operator <<(std::ostream& os, const Matrix& obj)
{
	for (int i = 0; i < obj.get_rows(); i++)
	{
		for (int j = 0; j < obj.get_cols(); j++)
		{
			cout << obj.get_arr()[i][j] << "\t";
		}
		cout << endl;
	}
	return os;
}