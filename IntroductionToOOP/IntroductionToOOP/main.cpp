//IntroductionToOOP
#include<iostream>
using namespace std;

//Создавая структуру или класс мы создаем новый тип данных
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		//x = -2;	//must be a modieble l-value
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//				Constructors:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Methods:
	double distance(Point other)
	{
		//this - этот
		//other - другой
		///////////////////////
		//this - эта точка
		//other - та точка
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
	//Функция sqrt() возвращает квадратный корень принятого числа
}

//#define STRUCT_POINT
#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	cout << "Hello OOP" << endl;
	int a;	//Объявление переменной 'a' типа 'int'
	Point A;//Объявление переменной 'A' типа 'Point'
			//Создание объекта 'A' структуры 'Point'
			//Создание экземпляра 'A' структуры 'Point'

	cout << sizeof(A) << endl;
	cout << sizeof(Point) << endl;

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;	//Pointer to 'A'
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние от точки 'A' до точки 'B':" << A.distance(B) << endl;
	cout << "Расстояние от точки 'B' до точки 'A':" << B.distance(A) << endl;
	cout << "Расстояние между точками 'A' и 'B':  " << distance(A, B) << endl;
	cout << "Расстояние между точками 'B' и 'A':  " << distance(B, A) << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	/*for (int i = 0; i < 10; i++)
{
	cout << i << "\t";
}*/
//cout << i << "\t";

	Point A;	//Default constructor
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;	//Copy constructor
	D.print();
#endif // CONSTRUCTORS_CHECK

}

/*
------------------------------------------------
.  - Оператор прямого доступа (Point operator)
	 Используется для доступа к полям объекта по имени объекта.
-> - Оператор косвенного доступа (Arrow operator)
	 Используется для доступа к полям объекта по адресу объекта.
------------------------------------------------
*/

/*
------------------------------------------------
			OOP concepts
1. Инкапсуляция (Encapsulation) - это сокрытие определенной части класса от внешнего мира;
	Модификаторы доступа:
		private:	закрытые поля, к ним можно получить доступ только внутри класса;
		public:		открытые поля, к ним можно получить доступ откуда угодно;
		protected:	защищенные поля. Этот модификатор доступа используется только при наследовании.
					protected-поля доступны внутри нашего класса, и его дочерних классов.

		get/set-методы позволяеют получить доступ к закрытым переменным в классе.
		get (взять, получить) методы	- открывают доступ к закрытым переменным на чтение,
										  т.е., позволяют ВЗЯТЬ(ПОЛУЧИТЬ) значение закрытой переменной;
		set (задать, установить) методы - открывают доступ к закрытым переменным на запись,
										  т.е., позволяют задать значения закрытых переменных.
										  Кроме того, set-методы обеспечиваю фильтрацию данных,
										  т.е., предотвращают попадание некорректных значений
										  в переменные члены класса.

2. Наследование (Inheritance);
3. Полиморфизм  (Polymorphism);
------------------------------------------------
*/

/*
------------------------------------------------
1. Constructor - это метод, который создает объект, а именно,
   выделяет память под объект, и инициализирует его поля при создании;
	-с параметрами;
	-без параметров;
	-конструктор по умолчанию (Default constructor);
	-конструктор копирования;
		Побитовое копирование	(Deep copy);
		Повехностное копирование(Shallow copy); Debug assertion failed
	-конструктор переноса;
2. ~Destructor  - это метод, который уничтожает объект по завершении его времени жизни.
3. Assignment operator;
------------------------------------------------
*/