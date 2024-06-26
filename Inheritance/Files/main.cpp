//Files
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef WRITE_TO_FILE
	std::ofstream fout;		//1) Создаем поток.
	fout.open("File.txt", std::ios_base::app);	//2) Открываем поток.
												//std::ios_base::app - append (дописать в конец файла)
	//fout << "HelloWorld" << endl;	//3) Пишем в поток.
	//fout << "Сам привет!" << endl;

	time_t now = time(NULL);
	fout << ctime(&now) << endl;

	fout.close();			//4) Закрываем поток.
	//!!! Потоки, как холодильник, если они были открыты, их обязательно нужно закрыть!!!

	system("notepad File.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	//1) Создаем и открываем поток:
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		//Здесь будем читать файл:

		const int SIZE = 256;	//размер буфера
		char buffer[SIZE]{};	//буфер

		while (!fin.eof())	//NOT EndOfFile
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);	//Читает строку с пробелами
			cout << buffer << endl;
		}

		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
#endif // READ_FROM_FILE

}