#include "Enter.h"


using namespace std;


bool isNumber(const string & str)
{
	for (char const& c : str) {
		if (std::isdigit(c) == 0) return false;
}
return true;
}


int numEnter(istream & Enter) {
	string str;
	while (1) {
		Enter >> str;
		if (isNumber(str)) {
			return(atoi(str.c_str()));
		}
		cout << "Неправильный тип данных! Нужно вводить цифры.\n";
	}
}


