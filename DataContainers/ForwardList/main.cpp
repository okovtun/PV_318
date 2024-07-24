#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n-----------------------------------\n"

class Element
{
	int Data;			//Значение элемента
	Element* pNext;		//Pointer to Next - указатель на следующий элемент
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;	//Голова списка, указывает на начальный элемент списка
public:
	ForwardList()
	{
		//Конструктор по умолчанию, который создает пустой список
		Head = nullptr;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//					Adding elements:
	void push_front(int Data)
	{
		//1) Создаем новый элемент:
		Element* New = new Element(Data);

		//2) Пристыковываем новый элемент к началу списка:
		New->pNext = Head;

		//3) Голову перенаправляем на новый элемент:
		Head = New;
	}
	void push_back(int Data)
	{
		/*int a = 2;
		int* pa = &a;
		int* pb = new int(3);*/

		//Поскольку push_back() НЕ умеет работать с пустым списком, мы проверяем,
		//если список пуст, вызываем метод push_front(), который УМЕЕТ работать с пустым списком.
		if (Head == nullptr)return push_front(Data);

		//1) Создаем новый элемент:
		Element* New = new Element(Data);

		//2) Доходим до конца списка:
		Element* Temp = Head;
		//while((*Temp).pNext)
		while (Temp->pNext)
			Temp = Temp->pNext;
		
		//3) После того как мы оказались в конце списка, можно добавлять новый элемент в конец:
		Temp->pNext = New;
	}

	//					Methods:
	void print()const
	{
		Element* Temp = Head;	//Temp - это итератор.
								//Итератор - это указатель, при помощи которого 
								//можно получить доступ к элементам структуры данных.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент.
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите воличество элементов списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	list.push_back(123);
	list.print();
}