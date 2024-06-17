#include"String.h"

#define CAT_CHECK
//#define CONSTRUCTORS_CHECK

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
