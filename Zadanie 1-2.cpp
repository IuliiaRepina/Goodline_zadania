// Goodline.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/////Программа создает файл numbers.csv в папке проекта, заполняет файл случайными целыми числами от 1 до 100
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

void CreateFile(unsigned int N) {
	ofstream output("numbers.csv", ios::trunc | ios::out);
	for (int i = 0; i < N; i++) {
		output << rand() % 100 << (i < (N - 1) ? "," : "");
	}
	output.close();
}

vector<int>  ReadFile() {
	vector<int> res(0);
	ifstream input("numbers.csv", ios::in);

	if (input.is_open()) {
		string tmp = "";
		char ch;
		while (input >> ch)
		{
			if (!isdigit(ch)) {
				res.push_back(stoi(tmp));
				tmp.clear();
			}
			else {
				tmp += ch;
			}
		}
		if (tmp.length() > 0) {
			res.push_back(stoi(tmp));
		}
		input.close();
	}
	return res;
}

void BubbleSort(vector<int>& input) {
	for (int i = 0; i < input.size() - 1; i++) {
		for (int j = 0; j < input.size() - 1 - i; j++) {
			if (input[j] > input[j + 1]) {
				swap(input[j], input[j + 1]);
			}
		}
	}
}

void OutputFile(vector<int> &vec) {
	ofstream output("numbers.csv", ios::trunc | ios::out);
	for (int i = 0; i < vec.size(); i++) {
		output << vec[i] << (i < (vec.size() - 1) ? "," : "");
	}
	output.close();

}

int main()
{
	srand(time(0));
	CreateFile(100);
	auto numbers = ReadFile();
	BubbleSort(numbers);
	OutputFile(numbers);
}

