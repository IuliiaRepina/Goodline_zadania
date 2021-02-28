// goodline_stepen.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	int x, y;
	int res = 1;

	cout << "Введите число: ";
	cin >> x;
	cout << "Укажите степень: ";
	cin >> y;

	for (int i = 0; i < y; i++)
	{
		res *= x;
	}

	cout << "Результат: " << res << endl;

}