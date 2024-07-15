#include<Windows.h>
#include<iostream>
#include<math.h>
using namespace std;


namespace Geometry
{
	enum Color  // enum (Enumeration) - ��� ������������. ������������ - ��� ����� ������������� ��������
	{
		CONSOLE_BLUE = 0x09,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_RED = 0xCC,
		CONSOLE_DEFAULT = 0x07,
		RGB_RED = (0xFF0000), //��������� RGB �����
		RGB_GREEN = (0x00FF00),
		RGB_BLUE = (0xFFFF00),
		RGB_WHITE = (0xFFFFFF)
	};

	class Shape
	{
		Color color;
	public:
		Shape(Color color) :color(color) {}  //����������� � ����.����������
		virtual ~Shape() {}   // {}������ ����������, ���� ������� ; �� ����� ��� �� �������������
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		Color get_color()const { return color; }  //Geters
		void set_color(Color color) { this->color = color; }  //Seters
		virtual void info()const
		{
			cout << "������� ������: " << get_area() << endl;
			cout << "�������� ������: " << get_perimeter() << endl;
			draw();
		}
	};

	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, Color color) :Shape(color)
		{
			set_width(width);
			set_height(height);
		}
		virtual ~Rectangle() {};
		double get_area()const override
		{
			return width * height;
		}
		double get_perimeter()const override
		{
			return(width + height) * 2;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow(); //1)�������� ���������� ���� �������. ���������� � ������� �������� �������� ����-��.
			//description 
			//HWND - Handler to Window(���������� ��� ���������� ����)
			HDC hdc = GetDC(hwnd); //2) �������� �������� ���������� (Device context) ���� �������
			//DC - ��� �� �� ��� �� ����� ��������
			HPEN hPen = CreatePen(PS_SOLID, 5, get_color());
			//3) ������� ��������, Pen ������ ������ ������
			//PS_SOLID - �������� �����
			//5-������� ����� � ��������
			// 4) c������ ��������
			HBRUSH hBrush = CreateSolidBrush(Geometry::Color::RGB_BLUE);
			//5) �������� ��� � �� ��� ��������
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//6) ������ �������������:
			::Rectangle(hdc, 250, 50, 400, 150);
			//����� �������� ��� ��� ���������� ������� ���� ��������� ������� ��������� ��� �������� �����.
			//7) ����������� �������:
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
			/*for (int i = 0; i < height; i++)
			{
				for (int i = 0; i < width; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}*/
		}
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		void set_width(double width)
		{
			this->width = width;
		}
		void set_height(double height)
		{
			this->height = height;
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "������: " << get_width() << endl;
			cout << "������: " << get_height() << endl;
			Shape::info();
		}
	};

}

void main()
{
	setlocale(LC_ALL, "Rus");

	//Geometry::Square square(5, Geometry::Color::CONSOLE_RED);
	//square.info();

	Geometry::Rectangle rect(10, 6, Geometry::Color::CONSOLE_DEFAULT);
	rect.info();
	//Geometry::Square rect(10, 6, Geometry::Color::CONSOLE_DEFAULT);
	//rect.info();


}