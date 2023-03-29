// lab15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

struct student {
	int group;
	char surname[20];
	int age;
	char gender[20];
	int phys;
	int math;
	int inf;
	int stip;
};

int main() {
	setlocale(LC_ALL, "RUS");
	char buffChar[50];
	int buffInt;
	int amount = 0;
	ifstream fin("C:\\mem\\file.txt");
	if (!fin.is_open())
		cout << "Ошибка при открытии файла." << endl;
	else {
		fin >> buffInt;
		 amount = buffInt;
	}
	cout << amount<<endl;
	student* a;
	a = new student[amount];
	
	for (int i = 0; i < amount; i++) {
		fin >> buffInt;
		a[i].group = buffInt;
		fin >> buffChar;
		strcpy_s(a[i].surname, buffChar);
		fin >> buffInt;
		a[i].age = buffInt;
		fin >> buffChar;
		strcpy_s(a[i].gender, buffChar);
		fin >> buffInt;
		a[i].phys = buffInt;
		fin >> buffInt;
		a[i].math = buffInt;
		fin >> buffInt;
		a[i].inf = buffInt;
		fin >> buffInt;
		a[i].stip = buffInt;
	}


	//cout << "имя 1=" << a[0].surname << "имя2=" << a[1].surname << endl;
	cout << "Введите номер группы, студенты которой нужны:" << endl;
	int n;
	cin >> n;
	
	cout << "Данные о нужных студентах:" << endl;
	for (int i = 0; i < amount; i++) {
		if ( (a[i].group == n) &&(a[i].math==2)|| (a[i].inf == 2)|| (a[i].phys == 2)) {
			a[i].stip = 0;
			cout << endl << a[i].group << endl << a[i].surname << ", " <<
				a[i].age << ", " << a[i].gender << endl << a[i].phys << " " <<
				a[i].math << " " << a[i].inf << endl << a[i].stip << endl;
		}
	}
	
	system("pause");
	return 0;
}
