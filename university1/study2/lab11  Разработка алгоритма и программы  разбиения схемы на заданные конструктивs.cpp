// lab12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

#define gen 0
#define cut 1

#if gen
int main() {
	ofstream out;
	out.open("circuit.txt");
	srand(time(0));
	for (int i = 0; i < 12; i++)out << "1";
	out << "\n";
	for (int i = 0; i < 19; i++) { 
		int n = (rand() % 10) + 2;
		vector<int>a;
		a.resize(n);
		for (int j = 0; j < n; j++)a[j] = rand() % 12;
		for (int j = 0; j < 12; j++) {
			bool f = 0;
			for (int k = 0; (k < n) && (f == 0); k++)if (a[k] == j)f = 1;
			out << f;
		}
		out << "\n";
	}
	out.close();
}
#endif

#if cut
int main() {
	setlocale(LC_ALL, "rus");
	srand(1);
	vector<vector<bool>> circuit;
	circuit.resize(20);
	ifstream in;
	in.open("circuit.txt");
	for (int i = 0; i < 20; i++) {
		circuit[i].resize(12);
		char t;
		for (int j = 0; j < 12; j++) {
			in >> t;
			circuit[i][j] = (t == '1' ? 1 : 0);
		}
	}
	in.close();
	vector<bool>a1, a2;
	a1.resize(12);
	a2.resize(12);
	for (int i = 0; i < 12; i++) {
		a1[i] = rand() % 2;
		a2[i] = !a1[i];
	}
	cout << "Элементы лежащие в первой части: ";
	for (int i = 0; i < 12; i++) {
		if (a1[i] == 1)cout << i + 1 << " ";
	}
	cout << "\nЭлементы лежащие во второй части: ";
	for (int i = 0; i < 12; i++) {
		if (a2[i] == 1)cout << i + 1 << " ";
	}
	cout << "\n\n\n";
	for (int i = 0; i < 20; i++) {
		
		bool f = 0;
		for (int j = 0; (j < 12) && (f == 0); j++) {
			if ((circuit[i][j] == 1) && (a2[j] == 1))f = 1;
		}
		if (f == 0) {
			cout << "Цепь номер: " << i + 1 << " целиком лежит во второй части\n";
		}
		else {
			f = 0;
			for (int j = 0; (j < 12) && (f == 0); j++) {
				if ((circuit[i][j] == 1) && (a1[j] == 1))f = 1;
			}
			if (f == 0) {
				cout << "Цепь номер: " << i + 1 << " целиком лежит первой части\n";
			}
		}
	}
	system("pause");

}
#endif
