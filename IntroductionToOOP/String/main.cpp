//String
#include<iostream>
using namespace std;

class String
{
	int	size;	//Размер строки в Байтах
	char* str;	//Адрес строки в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//			Constructors:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	~String();

	//				Operators:
	String& operator=(const String& other);

	//				Methods:
	void print()const;
};
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


//			Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//Deep copy
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//				Operators:
String& String::operator=(const String& other)
{
	/*int a = 2;
	int b = 3;
	a = b;*/
	if (this == &other)return *this;
	delete[] str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

//				Methods:
void String::print()const
{
	cout << "Obj:\t" << this << "\t";
	cout << "Size:\t" << size << "\t";
	cout << "Addr:\t" << &str << "\t";
	cout << "Str:\t" << str << "\n";
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String buffer(left.get_size() + right.get_size() - 1);	//From 'int' to 'String'
	for (int i = 0; i < left.get_size(); i++)
		buffer.get_str()[i] = left.get_str()[i]/* -= 32*/;
	for (int i = 0; i < right.get_size(); i++)
		buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	buffer.print();
	return buffer;
}

#define CONSTRUCTORS_CHECK
//#define CAT_CHECK

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