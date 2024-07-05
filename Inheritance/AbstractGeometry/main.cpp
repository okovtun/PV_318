//AbstractGeometry
#include<iostream>
using namespace std;

enum Color	//enum (Enumeration) - это перечисление. Перечисление - это набор целочисленных констант
{
	CONSOLE_BLUE	= 0x09,
	CONSOLE_GREEN	= 0xAA,
	CONSOLE_RED		= 0xCC,
	CONSOLE_DEFAULT = 0x07
};

class Shape
{
	Color color;
public:
	Shape(Color color) :color(color){}
	virtual ~Shape() {}
	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
	Color get_color()const
	{
		return color;
	}
	void set_color(Color color)
	{
		this->color = color;
	}
};

class Square :public Shape
{
	double side;	//длина стороны
public:
	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
	}
	virtual ~Square() {}
	double get_area()const override
	{
		return side * side;
	}
	double get_perimeter()const override
	{
		return side * 4;
	}
	void draw()const override
	{
		for (int i = 0; i < side; i++)
		{
			for (int i = 0; i < side; i++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		this->side = side;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::CONSOLE_BLUE);
	Square square(5, Color::CONSOLE_RED);
	cout << "Длина стороны клвадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата:  " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();
}