#pragma once
//String
#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
///////////		���������� ������ (Class declaration)		///////////

class String
{
	int	size;	//������ ������ � ������
	char* str;	//����� ������ � ������������ ������
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

///////////	����� ���������� ������ (Class declaration end)	///////////
///////////////////////////////////////////////////////////////////////