
#include <iostream>

using namespace std;
#include <cmath>
#include <stdlib.h>




class matr {

    int** base; int x_size, y_size;

public:
    matr(int n, int m);
    ~matr();
    int& elem(int i, int j);
    int get_xsize() { return x_size; };
    int get_ysize() { return y_size; };
    void print();
    void input();
    friend void Findtochki(matr& matrix, int c);

};

matr::matr(int n, int m) {
    x_size = n; y_size = m;

    base = new int* [y_size];
    for (int i = 0; i < x_size; i++)
        base[i] = new int[x_size];

}

matr::~matr() {
    for (int i = 0; i < y_size; i++)
        delete[] base[i];
    delete[] base; x_size = 0; y_size = 0;
}


int& matr::elem(int i, int j) {
    return base[i][j];
}

void matr::print() {
    cout << "Вывод матрицы:" << endl;
    for (int j = 0; j< y_size; j++) {
        for (int i = 0; i < x_size; i++) 
            cout << base[i][j] << ' ';
        cout << endl;
                
    }
 }

void matr::input() {
    cout << "Ввод матрицы:" << endl;
    for (int j = 0; j < y_size; j++) {
        for (int i = 0; i < x_size; i++)
            cin >> base[i][j];
    }
}

void Findtochki(matr& matrix, int c) {
    cout << "Находим точки в радиусе:" << endl << endl;

    for (int i = 0; i < matrix.get_xsize(); i++) {

        double A = sqrt(pow(matrix.base[0][i], 2) + pow(matrix.base[1][i], 2));
        cout << "A=" << A << endl;
        if (A <= c)
            cout << "Точка с коорд:" << matrix.base[0][i] << " " << matrix.base[1][i] << " находится в радиусе" << endl;
    }
}



int main()
{
    setlocale(LC_ALL,"RUS");
    int c;
    matr x(5, 2);
    x.input();
    x.print();
    cout << "Введите радиус:";
    cin >> c;
    Findtochki(x,c);
    system("pause");
    return 0;
}

