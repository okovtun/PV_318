https://github.com/okovtun/PV_318.git
https://www.youtube.com/playlist?list=PLeqyOOqxeiIPt4Opfdrc50pI9PbPSjOaV
https://meet.google.com/mho-khdw-fhj

///////////////////////////////////////////////////////////////////////////////////
///////////							Data Containers						///////////
///////////////////////////////////////////////////////////////////////////////////

TOREAD:
https://legacy.cplusplus.com/doc/tutorial/control/#:~:text=equal%20to%2050.-,Range%2Dbased%20for%20loop,-The%20for%2Dloop

TODO:
Создвть ветку 'TemplatedList', и в этой ветке шаблонизировать двусвязный список.

TODO:
1. Оптимизировать алгоритмы добавления элементов до одного выражения,
   как мы это делали в односвязном списке;
2. Оптимизировать код итераторов;
3. Решить проблему оператора '+' - он НЕ должен изменять константные объекты;

DONE:
1. В двусвязный список добавить следующие методы:
	??? reverse_print();	//выводит список на экран от Хвоста до Головы	DONE
	??? push_back(???);		DONE
	??? pop_front(???);		DONE
	??? pop_back(???);		DONE

	??? insert(???);		DONE
	??? erase(???);

2. Деструктор должен очищать список;	DONE

3. Проверочный код должен заработать:	DONE
	List list = { 3, 5, 8, 13, 21 };
	for(int i:list)cout << i << tab; cout << endl;;

DONE:
Проверочный код в секции RANGE_BASED_FOR_LIST должен заработать.	DONE
	https://github.com/okovtun/PV_318/blob/771b842c5a3ac310be6209cfddea00f56f87ccbb/DataContainers/ForwardList/main.cpp#L385-L393

DONE:
В класс ForwardList добавить следуюшие методы:
1)	??? push_back(???);		//добавляет значение в конец списка	DONE
	??? pop_front(???);		//удаляет начальный элемент списка	DONE
	??? pop_back(???);		//удаляет последний элемент списка	DONE

2)  ??? insert(???);		//вставляет значение в список по заданному индексу	DONE
	??? erase(???);			//удаляет значение из списка по заданному индексу

3) Список создает утечку памяти, это нужно исправить;	DONE

4) Написать конструктор на заданное количество элементов:		DONE
	ForwardList list(5);
	for(int i=0; i<list.size(); i++) cout << list[i] << tab; cout << endl;

5)  ForwardList list1 = { 3, 5, 8, 13, 21 };
	ForwardList list2 = { 34, 55, 89 };
	ForwardList list3 = list1 + list2;	//Конкатенация

6) CopyMethods, MoveMethods;	DONE

7) Оптимизировать методы добавления элементов в список до одного выражения DONE
   без учета size++;

///////////////////////////////////////////////////////////////////////////////////
///////////							Inheritance							///////////
///////////////////////////////////////////////////////////////////////////////////

TODO:
1. Почитать про системы счисления:
	https://github.com/okovtun/PV_318/blob/master/NumericSystems.pdf;
2. Добавить желтый, цвет;		DONE
3. Реализовать класс Circle:	DONE
	https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-ellipse;
4. Реализовать класс треугольник:
	-Нарисовать равносторонний треугольник;		DONE
	-Реализовать равноберренный треуголник;
	-Реализовать прямоугольный треуголник;
5. Решить проблему с выходом фигур за пределы экрана, и с размером линий;	DONE
6. Создать commit, создать ветку 'GeometrySplit' и в этой ветке вынести классы в отдельные файлы;

TODO:
1. Решить проблему с цветами;
2. Реализвать остальные фигуры, и нарисовать их при помощи WinGDI:
	https://learn.microsoft.com/en-us/windows/win32/gdi/about-filled-shapes

DONE:
Реализовать иерархию геометрических фигур: квадрат, прямоугольник, круг, треугольник.......
Сгенерировать фигуры в случайном порядке, и для каждой фигуры вывести ее первичные своиства: длина стороны, радиус .....
и вторичные свойства, такие как: площадь и периметр. Каждую фигуру так же нужно нарисовать.

DONE in 'Introduction\String':
	https://stackoverflow.com/questions/72927820/c20-visual-studio-2022-complier-optimization-setting-to-implement-move-constru
	https://learn.microsoft.com/en-us/cpp/build/reference/zc-nrvo?view=msvc-170
	-------------------------------------------------------------------------------
	https://en.wikipedia.org/wiki/Copy_elision
	https://en.cppreference.com/w/cpp/language/copy_elision

DONE:
1. В проекте 'Academy' реализовать класс 'Graduate', который описывает дипломника; DONE
2. Вызвать леструкторы для объектов;	DONE
3. Проверочный код должен заработать:	DONE
	https://github.com/okovtun/PV_318/blob/89549f58489c34e57828513e3f5606ba5a4cabd9/Inheritance/Academy/main.cpp#L208
4. Написать функцию ??? save(???), которая сохраняет группу в файл;	DONE
5. Написать функцию ??? load(???), которая загружает группу из файл;DONE
6. Решить вопрос с 'Weapons distribution';

TOREAD:
https://legacy.cplusplus.com/doc/tutorial/classes2/

DONE:
Учим теорию по наследованию!!!

DONE:
1. Вынести 'Fraction' в отдельные файлы на отдельной ветке;
2. Применить делегирование конструкторов в классе 'Matrix',
   так же, матрица должны выводиться на экран как обычный двумерный массив;

DONE:
В Solution 'IntroductionToOOP' добавить проект 'Matrix', и в нем реализовать класс 'Matrix',
описывающий матрицу. Класс должен обеспечивать все необходимые операции с Матрицами.

DONE:
1. Проверочный код в секции 'CONVERSIONS_TASK_1' должен заработать:		DONE
	https://github.com/okovtun/PV_318/blob/8a1c5fac36642fe024a1fef36975907bea2a87fc/IntroductionToOOP/Fraction/main.cpp#L414

2. Проверочный код в секции 'CONVERSIONS_TASK_2' должен заработать:		DONE
	https://github.com/okovtun/PV_318/blob/8a1c5fac36642fe024a1fef36975907bea2a87fc/IntroductionToOOP/Fraction/main.cpp#L424

3. Проверочный код в проекте 'String' должен заработать:
	https://github.com/okovtun/PV_318/blob/ea3af04dbe373cfc98d99635976d16a553765323/IntroductionToOOP/String/main.cpp#L37

DONE:
Выучить теорию по преобразованиям типов.

DONE:
Проверочный код в секции STREAMS_CHECK должен заработать:
	https://github.com/okovtun/PV_318/blob/94ebc6ebe761aa022dd79fc037f3bedfaee45d18/IntroductionToOOP/Fraction/main.cpp#L294


DONE:
В классе 'Fraction' перегрузить следующие операторы:
1. Increment/Decrement;
2. Составные присваивания: +=, -=, *=, /=;
3. Операторы сравнения: ==, !=, >, <, >=, <=;

DONE:
0. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. https://learn.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-170
2. https://learn.microsoft.com/en-us/cpp/cpp/general-rules-for-operator-overloading?view=msvc-170
3. В Solution 'IntroductionToOOP' добавить проект 'Fraction',
   и в нем реализовать класс 'Fraction', описывающий простую дробь;

DONE:
1. Почему при вызове метода distance() и функции distance() копируются объекты;

DONE:
0. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. В проекте 'IntroductionToOOP' написать метод ??? distance(???),	DONE
   который возвращает расстояние до указанной точки;
2. В проекте 'IntroductionToOOP' написать функцию ??? distance(???),DONE
   которая возвращает расстояние между двумя точками;