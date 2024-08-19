https://github.com/okovtun/PV_318.git
https://www.youtube.com/playlist?list=PLeqyOOqxeiIPt4Opfdrc50pI9PbPSjOaV
https://meet.google.com/mho-khdw-fhj

///////////////////////////////////////////////////////////////////////////////////
///////////							Data Containers						///////////
///////////////////////////////////////////////////////////////////////////////////

TOREAD:
https://legacy.cplusplus.com/doc/tutorial/control/#:~:text=equal%20to%2050.-,Range%2Dbased%20for%20loop,-The%20for%2Dloop

TODO:
������� ����� 'TemplatedList', � � ���� ����� ��������������� ���������� ������.

TODO:
1. �������������� ��������� ���������� ��������� �� ������ ���������,
   ��� �� ��� ������ � ����������� ������;
2. �������������� ��� ����������;
3. ������ �������� ��������� '+' - �� �� ������ �������� ����������� �������;

DONE:
1. � ���������� ������ �������� ��������� ������:
	??? reverse_print();	//������� ������ �� ����� �� ������ �� ������	DONE
	??? push_back(???);		DONE
	??? pop_front(???);		DONE
	??? pop_back(???);		DONE

	??? insert(???);		DONE
	??? erase(???);

2. ���������� ������ ������� ������;	DONE

3. ����������� ��� ������ ����������:	DONE
	List list = { 3, 5, 8, 13, 21 };
	for(int i:list)cout << i << tab; cout << endl;;

DONE:
����������� ��� � ������ RANGE_BASED_FOR_LIST ������ ����������.	DONE
	https://github.com/okovtun/PV_318/blob/771b842c5a3ac310be6209cfddea00f56f87ccbb/DataContainers/ForwardList/main.cpp#L385-L393

DONE:
� ����� ForwardList �������� ��������� ������:
1)	??? push_back(???);		//��������� �������� � ����� ������	DONE
	??? pop_front(???);		//������� ��������� ������� ������	DONE
	??? pop_back(???);		//������� ��������� ������� ������	DONE

2)  ??? insert(???);		//��������� �������� � ������ �� ��������� �������	DONE
	??? erase(???);			//������� �������� �� ������ �� ��������� �������

3) ������ ������� ������ ������, ��� ����� ���������;	DONE

4) �������� ����������� �� �������� ���������� ���������:		DONE
	ForwardList list(5);
	for(int i=0; i<list.size(); i++) cout << list[i] << tab; cout << endl;

5)  ForwardList list1 = { 3, 5, 8, 13, 21 };
	ForwardList list2 = { 34, 55, 89 };
	ForwardList list3 = list1 + list2;	//������������

6) CopyMethods, MoveMethods;	DONE

7) �������������� ������ ���������� ��������� � ������ �� ������ ��������� DONE
   ��� ����� size++;

///////////////////////////////////////////////////////////////////////////////////
///////////							Inheritance							///////////
///////////////////////////////////////////////////////////////////////////////////

TODO:
1. �������� ��� ������� ���������:
	https://github.com/okovtun/PV_318/blob/master/NumericSystems.pdf;
2. �������� ������, ����;		DONE
3. ����������� ����� Circle:	DONE
	https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-ellipse;
4. ����������� ����� �����������:
	-���������� �������������� �����������;		DONE
	-����������� �������������� ����������;
	-����������� ������������� ����������;
5. ������ �������� � ������� ����� �� ������� ������, � � �������� �����;	DONE
6. ������� commit, ������� ����� 'GeometrySplit' � � ���� ����� ������� ������ � ��������� �����;

TODO:
1. ������ �������� � �������;
2. ���������� ��������� ������, � ���������� �� ��� ������ WinGDI:
	https://learn.microsoft.com/en-us/windows/win32/gdi/about-filled-shapes

DONE:
����������� �������� �������������� �����: �������, �������������, ����, �����������.......
������������� ������ � ��������� �������, � ��� ������ ������ ������� �� ��������� ��������: ����� �������, ������ .....
� ��������� ��������, ����� ���: ������� � ��������. ������ ������ ��� �� ����� ����������.

DONE in 'Introduction\String':
	https://stackoverflow.com/questions/72927820/c20-visual-studio-2022-complier-optimization-setting-to-implement-move-constru
	https://learn.microsoft.com/en-us/cpp/build/reference/zc-nrvo?view=msvc-170
	-------------------------------------------------------------------------------
	https://en.wikipedia.org/wiki/Copy_elision
	https://en.cppreference.com/w/cpp/language/copy_elision

DONE:
1. � ������� 'Academy' ����������� ����� 'Graduate', ������� ��������� ����������; DONE
2. ������� ����������� ��� ��������;	DONE
3. ����������� ��� ������ ����������:	DONE
	https://github.com/okovtun/PV_318/blob/89549f58489c34e57828513e3f5606ba5a4cabd9/Inheritance/Academy/main.cpp#L208
4. �������� ������� ??? save(???), ������� ��������� ������ � ����;	DONE
5. �������� ������� ??? load(???), ������� ��������� ������ �� ����;DONE
6. ������ ������ � 'Weapons distribution';

TOREAD:
https://legacy.cplusplus.com/doc/tutorial/classes2/

DONE:
���� ������ �� ������������!!!

DONE:
1. ������� 'Fraction' � ��������� ����� �� ��������� �����;
2. ��������� ������������� ������������� � ������ 'Matrix',
   ��� ��, ������� ������ ���������� �� ����� ��� ������� ��������� ������;

DONE:
� Solution 'IntroductionToOOP' �������� ������ 'Matrix', � � ��� ����������� ����� 'Matrix',
����������� �������. ����� ������ ������������ ��� ����������� �������� � ���������.

DONE:
1. ����������� ��� � ������ 'CONVERSIONS_TASK_1' ������ ����������:		DONE
	https://github.com/okovtun/PV_318/blob/8a1c5fac36642fe024a1fef36975907bea2a87fc/IntroductionToOOP/Fraction/main.cpp#L414

2. ����������� ��� � ������ 'CONVERSIONS_TASK_2' ������ ����������:		DONE
	https://github.com/okovtun/PV_318/blob/8a1c5fac36642fe024a1fef36975907bea2a87fc/IntroductionToOOP/Fraction/main.cpp#L424

3. ����������� ��� � ������� 'String' ������ ����������:
	https://github.com/okovtun/PV_318/blob/ea3af04dbe373cfc98d99635976d16a553765323/IntroductionToOOP/String/main.cpp#L37

DONE:
������� ������ �� ��������������� �����.

DONE:
����������� ��� � ������ STREAMS_CHECK ������ ����������:
	https://github.com/okovtun/PV_318/blob/94ebc6ebe761aa022dd79fc037f3bedfaee45d18/IntroductionToOOP/Fraction/main.cpp#L294


DONE:
� ������ 'Fraction' ����������� ��������� ���������:
1. Increment/Decrement;
2. ��������� ������������: +=, -=, *=, /=;
3. ��������� ���������: ==, !=, >, <, >=, <=;

DONE:
0. ������� ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. https://learn.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-170
2. https://learn.microsoft.com/en-us/cpp/cpp/general-rules-for-operator-overloading?view=msvc-170
3. � Solution 'IntroductionToOOP' �������� ������ 'Fraction',
   � � ��� ����������� ����� 'Fraction', ����������� ������� �����;

DONE:
1. ������ ��� ������ ������ distance() � ������� distance() ���������� �������;

DONE:
0. ������� ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. � ������� 'IntroductionToOOP' �������� ����� ??? distance(???),	DONE
   ������� ���������� ���������� �� ��������� �����;
2. � ������� 'IntroductionToOOP' �������� ������� ??? distance(???),DONE
   ������� ���������� ���������� ����� ����� �������;