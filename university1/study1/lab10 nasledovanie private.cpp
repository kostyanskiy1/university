
#include <iostream>
#include <math.h>
using namespace std;


class matrix {
protected:
    int** base;
    int x, y;
public:
    matrix(int n, int m);
    ~matrix();
    int& elem(int i, int j);
    void input();
    void output();
};


matrix::matrix(int n, int m) {
    x = n;
    y = m;
    base = new int* [y];
    for (int i = 0; i < y; i++) 
        base[i] = new int[x];

}


matrix::~matrix() {
    for (int i = 0; i < y; i++)
       delete[] base[i];
    delete[] base;
    x = 0; y = 0;   

}


int& matrix::elem(int i, int j) {
    return base[i][j];

}

void matrix::input() {
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++)
            cin >> base[i][j];
    }
}

void matrix::output() {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            cout<< base[i][j]<<" ";
        cout << endl;
    }
    
}

class MATRIX :public matrix {
public: 
    MATRIX(int x, int y) :matrix(x, y) {};

    void decision();
};

void MATRIX::decision() {
    int c;

    for (int i = 0; i < y / 2; i++) {
        c = base[i][i];
        base[i][i] = base[y - 1 - i][y - 1 - i];
        base[y - 1 - i][y - 1 - i] = c;
    }
}


int main()
{
    setlocale(LC_ALL, "rus");

    int n, m;

    cout << "Введите размеры матрицы:";
    cin >> n;
    cin >> m;
    MATRIX a(n, m);

    cout << "Введите матрицу:" << endl;
    a.input();
    cout << "Матрица:" << endl;
    a.output();
    cout << "Меняем элементы главной диагонали::" << endl;
    a.decision ();
    a.output();

    system("pause");
    return 0;

}



