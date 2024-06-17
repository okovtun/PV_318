#pragma once
//String
#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
///////////		Объявление класса (Class declaration)		///////////

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

std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);

///////////	Конец объявления класса (Class declaration end)	///////////
///////////////////////////////////////////////////////////////////////