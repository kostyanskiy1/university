/*
Для двумерного массива B из m строк и n столбцов вычислить выражение Y = (C1–1)m + (C2–1)(m–1) + … + (Cn–1), где Ci – среднее арифметическое элементов в i–й строке массива B, значения 
которых превышают значение первого элемента i–й строки. Для вычисления среднего 
арифметического значения указанных элементов в произвольной строке двумерного массива 
использовать подпрограмму. 
*/

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
class Complex {
public:
	int re, im;
public:
	bool operator != (Complex x) {

		return sqrt(pow(re, 2) + pow(im, 2)) != sqrt(pow(x.re, 2) + pow(x.im, 2));
	}
	int operator = (Complex& x) {

		return sqrt(pow(x.re, 2) + pow(x.im, 2));
	}
	bool operator < (Complex& x) {

		return sqrt(pow(re, 2) + pow(im, 2)) < sqrt(pow(x.re, 2) + pow(x.im, 2));
	}
	bool operator > (Complex& x) {

		return sqrt(pow(re, 2) + pow(im, 2)) > sqrt(pow(x.re, 2) + pow(x.im, 2));
	}
	friend ostream& operator <<(ostream& out, Complex x);
	friend istream& operator >>(istream& in, Complex& x);

};

ostream& operator <<(ostream& out, Complex x) {

	out << x.re << " " << x.im << "i\t";
	return out;

}
istream& operator >>(istream& in, Complex& x) {

	in >> x.re;
	in >> x.im;
	return in;

}
double& operator *(int x, Complex z) {
	double mult = sqrt(pow(z.re, 2) + pow(z.im, 2)) * x;
	return mult;
}
double& operator +(double x, Complex z) {
	double sum = sqrt(pow(z.re, 2) + pow(z.im, 2)) ;
	return sum;
}
template <typename T>
double func(T* mas, int n)
{
	bool flg = false;
		double sum =0;
		int kol = 0;
		for (int i = 0; i < n; i++) {
			if (mas[i] > mas[0]) {
				sum = sum + mas[i];
				kol = kol + 1;
			}
		}
		if (kol == 0) {
			return 0;
		}
		else {
			double sr = sum / kol;
			return sr;
		}
		
}
template <typename T>
T** matrix(int m, int n) {
	T** matr = new T * [m];
	for (int i = 0; i < m; i++)
	{
		matr[i] = new T[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matr[i][j];
		}
	} return matr;
}
template <typename T>
double poisk_Y(T** matr, int m, int n) {
	double Y = 0;
	for (int i = 0; i < m; i++)
	{
		Y = Y + (m - i) * (func(matr[i], n)-1);
	}
	return Y;
}
int main()
{
	SetConsoleOutputCP(1251);
	int n, m;
	cout << "Введите размеры массива " << endl;
	cin >> n;
	cin >> m;
	 Complex** matr;
	cout << "Введите элементы массива " << endl;
	matr = matrix<Complex>(m, n);
	cout << "Ваш матрица : " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matr[i][j] << " ";

		}
		cout << endl;
	}
	cout << (poisk_Y(matr, m, n)) << endl;
	int** mass;
	mass = matrix<int>(m, n);
	cout << "Вашa матрица : " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mass[i][j] << " ";

		}
		cout << endl;
	}
	cout <<(poisk_Y(mass, m, n)) << endl;
	system("pause");

}
