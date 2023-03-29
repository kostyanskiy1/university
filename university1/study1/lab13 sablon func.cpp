// Lab13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

template <typename T>
void Novaya(T* array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i] = new T[size];
	}
	cout << "Введите элементы матрицы" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> array[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
};


template<typename T>
int Stroka(T* array, int size, double k) {
	int index = -1;
	bool fl = true;
	double c;
	
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				c = fmod( array[i][j] , k);//не работает, не ищет остаток от типа double
			//	cout <<"\n" <<c;
				if (c != 0) {
					
					fl = false;
					
				}
			}
		
		if (fl == false) {
			index = i;
			break;
		}
	}
	
	cout << "\nindex11=" << index;
	return index;
};


int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	int k,str;
	cout << "Введите размер " << endl;
	cin >> n;
	double** A = new double* [n];
	Novaya(A, n);
	cout << "Введите число для проверки на сравнение " << endl;
	cin >> k;
	str = Stroka(A, n, k);
	if (str == -1) {
		cout << "Строки с элементом, отличным от заданного числа нет" << endl;
	}
	else {
		cout << "Строка с иным числом № " << (str + 1) << endl;

	};
}



