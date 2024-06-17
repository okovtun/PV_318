#include"String.h"

/// --------------------------------------------------------------- ///

//#define CONSTRUCTORS_CHECK
#define CAT_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str1;			//Default constructor
	str1.print();

	String str2(8);
	str2.print();			//Single-Argument constructor

	String str3 = "Hello";	//Single-Argument constructor
	str3.print();

	String str4();			//Здесь НЕ вызывается конструктор и НЕ создается объект, 
							//в этом выражении объявляется функция str4(),
							//которая ничего не принимает, и возвращает объект класса 'String'.
	//str4.print();

	String str5{};			//Явный вызов конструктора по умолчанию
	str5.print();

	String str6{ str3 };	//Copy constructor
	str6.print();
#endif // CONSTRUCTORS_CHECK


#ifdef CAT_CHECK
	//String str;
//str.print();

	String str1 = "Hello";
	String str2 = "World";
	str1 = str1;

	cout << str1 << endl;
	cout << str2 << endl;

	//String str3 = str1 + str2;	//CopyConstructor
	String str3;
	str3 = str1 + " " + str2;		//CopyAssignment
	//str3.print();
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;	//HelloWorld  
#endif // CAT_CHECK

}