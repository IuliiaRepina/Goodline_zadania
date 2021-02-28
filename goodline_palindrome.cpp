// goodline_palindrome.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

bool palindrome(string line)
{
	int len = line.length();
	for (int i = 0; i < len / 2; ++i)
	{
		if (line[i] != line[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string str;
	cout << "Введите строку: ";
	cin >> str;
	if (palindrome(str))
	{
		cout << "Строка является палиндромом.";
	}
	else
	{
		cout << "Строка не является палиндромом.";
	}
	return 0;
}
