﻿#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class List
{
	class Element
	{
		int Data;		//значение элемента
		Element* pNext;	//указатель на следующий элемент
		Element* pPrev;	//указатель на предыдущий элемент
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr)
			:Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	}*Head, *Tail;	//объекты класса можно объявлять непосредственно после его описания.
	//Element* Head;
	//Element* Tail;
	size_t size;	//size_t - это typedef на 'unsigned int'.
	//Директива 'typedef' создает псевдоним для существующего типа данных.
	//typedef имеет следующий синтаксис:
	//				typedef существующий_тип_данных псевдоним
public:
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~List()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//						Adding elements:
	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
		}
		else
		{
			//1) Создаем новый элемент:
			Element* New = new Element(Data);

			//2) Привязываем новый элемент к началу списка:
			New->pNext = Head;

			//3) Привязываем головной элемент списка к новому элементу:
			Head->pPrev = New;

			//4) Смещаем Голову на новый элемент:
			Head = New;
		}

		size++;
	}

	//					Methods:
	void print()const
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Количество элементов в списке: " << size << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
}