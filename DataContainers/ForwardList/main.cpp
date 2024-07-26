#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-----------------------------------\n"

class Element
{
	int Data;			//Значение элемента
	Element* pNext;		//Pointer to Next - указатель на следующий элемент
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
int Element::count = 0;

class ForwardList
{
	Element* Head;	//Голова списка, указывает на начальный элемент списка
	int size;
public:
	int get_size()const
	{
		return size;
	}
	ForwardList()
	{
		//Конструктор по умолчанию, который создает пустой список
		Head = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	explicit ForwardList(int size) :ForwardList()
	{
		while (size--)push_front(0);
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		*this = other;	//Повторно используем код CopyAssignment
		cout << "CopyConstructor:" << this << endl;
	}
	ForwardList(ForwardList&& other):ForwardList()
	{
		*this = std::move(other);	//Функция std::move() принудительно вызывает MoveAssignment для класса.
		cout << "MoveConstructor:" << this << endl;
	}
	~ForwardList()
	{
		while (Head)pop_back();
		cout << "LDestructor:\t" << this << endl;
	}

	//                       Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		this->~ForwardList();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	ForwardList& operator=(ForwardList&& other)
	{
		if (this == &other)return *this;
		this->~ForwardList();
		this->Head = other.Head;
		this->size = other.size;
		other.Head = nullptr;
		other.size = 0;
		cout << "MoveAssignment:\t" << this << endl;
	}

	int& operator[](int index)
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
		return Temp->Data;
	}
	const int& operator[](int index)const
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
		return Temp->Data;
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

		size++;
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
		size++;
	}

	void insert(int Index, int Data)
	{
		if (Index > size)
		{
			cout << "Error: out of range" << endl;
			return;
		}
		if (Index == 0)return push_front(Data);
		//1) Создаем новый элемент:
		Element* New = new Element(Data);

		//2) Доходим до гужного элемента:
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			//if (Temp->pNext == nullptr)break;
			Temp = Temp->pNext;
		}

		//3) Вставляем элемент в список:
		New->pNext = Temp->pNext;
		Temp->pNext = New;

		size++;
	}

	//					Removing elements:
	void pop_front()
	{
		if (Head == nullptr)return;
		//1) Запоминаем вдрес удаляемого элемента:
		Element* Erased = Head;

		//2) Исключаем удаляемый элемент из списка:
		Head = Head->pNext;

		//3)  Удаляем эоемент из памяти:
		delete Erased;

		size--;
		/*
		-----------
		new   - создает объект в динамической памяти
		new[] - создает массив объектов в динамической памяти

		delete   - удаляет 1 объект из динамической памяти
		delete[] - удаляет массив объектов из динамической памяти

		delete new ....;
		delete[] new ...[...];
		-----------
		delete new ...[...];	//behaviour is undefined (поведение неопределено)
		delete[] new ...;		//behaviour is undefined (поведение неопределено)
		-----------
		*/
	}
	void pop_back()
	{
		if (Head->pNext == nullptr)return pop_front();
		//1) Доходим до предпоследнего элемента списка:
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;

		//2) Удаляем послений элемент из памяти:
		delete Temp->pNext;

		//3) Обнеляем указатель на последний элемент:
		Temp->pNext = nullptr;

		size--;
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
		cout << "Колтчество элементов списка: " << size << endl;
		cout << "Общее колтчество элементов: " << Element::count << endl;
	}
};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList buffer;
	for (int i = 0; i < left.get_size(); i++)buffer.push_back(left[i]);
	for (int i = 0; i < right.get_size(); i++)buffer.push_back(right[i]);
	return buffer;
}

//#define BASE_CHECK
//#define COUNT_CHECK
//#define SIZE_CONSTRUCTOR_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	int n;
	cout << "Введите воличество элементов списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	/*list.push_back(123);
	list.print();
	list.pop_front();
	list.print();*/
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();
#endif // BASE_CHECK

#ifdef COUNT_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1.print();

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();
#endif // COUNT_CHECK

#ifdef SIZE_CONSTRUCTOR_CHECK
	ForwardList list(5);
	for (int i = 0; i < list.get_size(); i++)
	{
		list[i] = rand() % 100;
	}
	for (int i = 0; i < list.get_size(); i++)
	{
		cout << list[i] << tab;
}
	cout << endl;
#endif // SIZE_CONSTRUCTOR_CHECK

	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1.print();

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.print();

	cout << delimiter << endl;
	//ForwardList list3 = list1 + list2;	//CopyConstructor
	cout << delimiter << endl;
	ForwardList list3;
	cout << delimiter << endl;
	list3 = list1 + list2;	//CopyAssignment
	cout << delimiter << endl;
	list3.print();
}