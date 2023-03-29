
#include <iostream>

using namespace std;

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
    double resh();
    void change();
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
    for (int j = 0; j < y_size; j++) {
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

double matr::resh() {

    double sum = 0, k = 0;
    double sredn = 0;
    for (int i = 0; i < y_size; i++) {
        if (base[i][i] < 0) {
            sum = sum + base[i][i];
            
            k = k + 1;
        }
        if (k > 0) sredn = sum / k;

        return sredn;
    }
}

    void matr::change() {
        int c;
        for (int i = 0; i < y_size; i++) {
            c = base[i][y_size - 1];
            base[i][y_size - 1] = base[i][0];
            base[i][0] = c;
        }
    }

int main()
{
    setlocale(LC_ALL, "RUS");
    int c; 
    int m;
    cout << "Введите размер матрицы:" << endl;
    cin >> m;
    matr x(m, m);
    x.input();
    x.print();
    cout << "Найдем средн арефм эл на главной диагонали=:" << x.resh() << endl;
    x.change();
    x.print();
    
    system("pause");
    return 0;


}

