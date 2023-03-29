// lab16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

using namespace std;

double zzz1(int x);
double zzz2(int x);

double zzz1(int x) {
	return (   ((sqrt(x)-sqrt(2))/(x+2))*((2/(x-sqrt(2*x)))+((x+2)/sqrt(2*x))-(x/(sqrt(2*x)+2)))	);
}

double zzz2(int x) {
	return (1/(sqrt(x)+sqrt(2)))  ;
}

int main() {

	setlocale(LC_ALL, "rus");
	double a;
	cout << "Введите a : \n";
	cin >> a;
	
	double z1, z2;

	try {
		if (a == 0|| a==2)
			throw("Ошибка , на 0 делить нельзя");
		if (a < 0)
			throw("Корень не может быть меньше 0");
		
		z1 = zzz1(a);
		cout << "Z1 = " << z1 << endl;

	
	}
	catch (const char* A) {
		cout << A;
	}
	try {
		if (a <= 0)
			throw("\nКорень не может быть меньше или = 0");
		z2 = zzz2(a);
		cout << "Z2 = " << z2 << endl;
	}
	catch (const char* A) {
		cout <<A<<"!!!";
	}

	system("pause");

	return 0;
}
