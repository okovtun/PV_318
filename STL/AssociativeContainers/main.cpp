#include<iostream>
#include<string>
#include<map>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------------\n"

//#define STL_MAP

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_MAP
	/*map - это контейнер, каждый элемент которого хранит пару<ключ, значение>
			pair<key, value>
	*/

#ifdef STL_MAP
	std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(1, "Monday"),
		std::pair<int, std::string>(2, "Tuesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(3, "—реда"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		{4, "Thursday"},
		{5, "Friday"},
		{5, "Friday"},
		{5, "ѕ€тница"},
		{5, "Friday"},
		{5, "Friday"},
		{5, "Friday"},
		{5, "Friday"},
		{6, "Saturday"},
		{6, "Saturday"},
		{6, "Saturday"},
		{6, "Saturday"},
		{6, "Saturday"},
		{6, "Saturday"},
		{7, "Sunday"},
	};

	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
	cout << endl;
#endif // STL_MAP


#endif // STL_MAP

	std::map<std::string, std::vector<std::string>> dictionary = 
	{
		std::pair<std::string, std::vector<std::string>>("map", {"карта", "план", "таблица"}),
		std::pair<std::string, std::vector<std::string>>("window", {"окно", "витрина"}),
		{"statement", {"утверждение", "за€вление", "высказывание"}},
		{"journey", {"путешествие", "поездка", "рейс", "прогулка"}}
	};
	for (std::map<std::string, std::vector<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout.width(16);
		cout << std::left;
		cout << (*it).first+":";
		for (std::vector<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt;
			cout << (*jt != it->second.back()?", ":";");
		}
		cout << endl;
	}
}