#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#define delimiter			"\n-----------------------------------\n"
#define double_delimiter	"\n===================================\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors:
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		//explicit - явный
		//implicit - неявный
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstrcutor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	//				Type-cast operators:
	/*
	--------------------------------------------
	operator type()
	{
		.....;
		.....;
		return value;
	}
	--------------------------------------------
	*/
	explicit operator int()
	{
		return integer;
	}
	operator double()
	{
		return integer + (double)numerator / denominator;
	}

	//				Methods:
	Fraction& reduce()
	{
		//https://www.webmath.ru/poleznoe/formules_12_7.php
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else more = denominator, less = numerator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	//GCD - Greatest Common Divesor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
//					Comparison operators:
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator()*right.get_denominator() ==
		right.get_numerator()*left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	return
		left.get_numerator()*right.get_denominator() >
		right.get_numerator()*left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	return
		left.get_numerator()*right.get_denominator() <
		right.get_numerator()*left.get_denominator();
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
	//return left < right || left == right;
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
	return left > right || left == right;
}
//Stream - поток
//std - Standard namespace
//:: - Scope operator (Оператор разрешения видимости - позволяет "зайти" в пространство имен)
//Сам по себе '::' выводит нас в GlobalScope (Глобальное пространство имен)
//namespace (Пространство имен) как папка, а имя, расположенное в нем - как файл.
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
//ostream - output stream (поток вывода)
//cout - Console Out
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
//istream - input stream (поток ввода)
//cin - Console In
{
	/*
	----------------------------
	5
	1/2
	2 3/4
	2(3/4)
	2+3/4
	----------------------------
	*/
	const int SIZE = 64;
	char buffer[SIZE]{};
	//is >> buffer;
	is.getline(buffer, SIZE);
	int number[3];
	int n = 0;
	const char delimiters[] = "(/) +";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		//Функция strtok() разделяет строку на токены:
		//https://legacy.cplusplus.com/reference/cstring/strtok/
			//	!!! ФУНКЦИЯ strtok() ИЗМЕНЯЕТ ВХОДНУЮ СТРОКУ !!!
		number[n++] = atoi(pch);
	//pch - Pointer to Character (Указатель на символ)
	//Функция atoi() - "ASCII string to int" принимает строку, и взвращает значение типа 'int' найденное в этой строке
	//https://legacy.cplusplus.com/reference/cstdlib/atoi/
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;

	switch (n)
	{
	case 1:	obj = Fraction(number[0]); break;
	case 2: obj = Fraction(number[0], number[1]); break;
	case 3: obj = Fraction(number[0], number[1], number[2]); break;
	}

	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define STREAMS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
#define CONVERSIONS_FROM_CLASS_TO_OTHER
//#define CONVERSIONS_TASK_1
#define CONVERSIONS_TASK_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();

	Fraction B = 5;	//Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	//double a = 2;
//double b = 3;
//double c = a * b;

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*Fraction C = A / B;
	C.print();
	(C++).print();
	C.print();

	A.print();
	B.print();*/

	A *= B;		//A = A*B;
	A.print();

	A /= B;
	A.print();

	//int a = 2;
	//int* pa = &a;
	////a = pa;
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++a;
	////a++++++++++++++++++++++++++++++++++++++++++++++++++++++++++;
	//cout << a << endl;  
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	//cout << (2 == 3) << endl;
	cout << (Fraction(1, 3) >= Fraction(5, 11)) << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef STREAMS_CHECK
	Fraction A(2, 3, 4);
	cout << "Введите простую дробь: "; cin >> A;

	cout << A << endl;
#endif // STREAMS_CHECK

#ifdef TYPE_CONVERSIONS_BASICS
	//(type)value;	C-like notation		(C-подобная форма записи)
//type(value);	Functional notation	(Функицональная форма записи)
//int a = 2.5;
//C4244: Conversion from 'type_1' to 'type_2', possible loss of data;
//		l-value = r-value;

	int a = 2;		//No conversions
	double b = 3;	//Conversion from less to more
	int c = b;		//Conversion from more to less without data loss
	int d = 2.5;	//Conversion from more to less with data loss
	cout << sizeof(int) << endl;
	cout << sizeof(double) << endl;
#endif // TYPE_CONVERSIONS_BASICS

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	/*
----------------------------------
1. From other to Class:
	- Single-argument constructor;
	- CopyAssignment;
2. From Class to other;
----------------------------------
*/
	Fraction A = (Fraction)5;	//Convertion from 'int' to 'Fraction'
								//Single-Argument constructor
	cout << A << endl;

	cout << double_delimiter << endl;

	Fraction B;	//Default constructor
	cout << delimiter << endl;
	B = Fraction(8);		//Convertion from 'int' to Fraction
							//Single-Argument constructor
							//Copy assignment
	cout << delimiter << endl;
	cout << B << endl;

	cout << double_delimiter << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERSIONS_TASK_1
	Fraction A(2, 3, 4);
	cout << A << endl;

	//int a = (int)A;
	double a = A;
	cout << a << endl;

#endif // CONVERSIONS_TASK_1

#ifdef CONVERSIONS_TASK_2
	Fraction B = M_PI;
	cout << B << endl;

	/*for (unsigned int i = 0; i < UINT_MAX; i++)
	{
		cout << i << endl;
	}*/
#endif // CONVERSIONS_TASK_2


}