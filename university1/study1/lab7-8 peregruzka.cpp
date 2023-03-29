// lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>

using namespace std;

class complex {
    int re, im;
public:
    complex(int a, int b) { re = a; im = b; };
    complex() { re = 0; im = 0; };
    int get_image() { return im; };
    friend ostream& operator<<(ostream& out, complex a);
    friend istream& operator>>(istream& in, complex& a);
    friend bool operator==(complex a, complex b);
};

class vect {
    complex* p;
    int size;
public:
    vect() { size = 5; p = new complex[size]; };
    vect(int n);
    //~vect() { delete[] p; };
    complex& element(int i);
    int get_size() { return size; };
    void print();
    void input();
    friend int part1(vect x, vect y);
};

vect::vect(int n) {
    size = n;
    p = new complex[size];
}

complex& vect::element(int i) {
    if (i < 0 || i >= size) {
        cout << "\nневерные границы\n" << i << endl;
        exit(1);
    }
    return(p[i]);
}

void vect::print() {
    for (int i = 0; i < size; i++)
        cout << " " << p[i];
}

void vect::input() {
    for (int i = 0; i < size; i++) {
        cout << "Число " << i + 1 << endl;
        cin >> p[i];
    }
}

ostream& operator<<(ostream& out, complex a) {
    out << a.re << " + " << a.im << "i";
    return (out);
}

istream& operator>>(istream& in, complex& a) {
    cout << "real?" << endl;
    in >> a.re;
    cout << "image?" << endl;
    in >> a.im;
    return(in);
}

bool operator==(complex a, complex b) {
    if ((a.re == b.re) && (a.im == b.im))
        return true;
    else return false;
}

int part1(vect x, vect y) {
    int kol = 0;
    for (int i = 0; i < x.get_size(); i++) {
        if (x.p[i] == y.p[i])
            kol++;
    }
    return kol;
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "\n--------------PART 1---------------\n" << endl;
    int n;
    cout << "Введите размер массивов:\n";
    cin >> n;
    vect x(n), y(n);
    cout << "\nВведите массив X:\n";
    x.input();
    cout << "\nВведите массив Y:\n";
    y.input();
    cout << "\nМассив X:\n";
    x.print();
    cout << "\nМассив Y:\n";
    y.print();
    int kol = part1(x, y);
    cout << "\nКоличество одинаковых элементов в векторах = " << kol << endl;
    cout << "\n--------------PART 2---------------\n" << endl;
    complex mas[6];
    cout << "\nВведите массив MAS:\n";
    for (int i = 0; i < 6; i++) {
        cout << "Число " << i + 1 << endl;
        cin >> mas[i];
    }
    cout << "\nМассив MAS:\n";
    for (int i = 0; i < 6; i++) {
        cout << mas[i] << "   |   ";
    }
    cout << endl;
    int max = mas[0].get_image();
    int num_max = 1;
    for (int i = 1; i < 6; i++) {
        if (mas[i].get_image() > max) {
            max = mas[i].get_image();
            num_max = i + 1;
        }
    }
    cout << "Номер числа с максимальной мнимой частью : " << num_max << "\nЧисло с максимальной мнимой частью : " << mas[num_max - 1] << endl;
    system("pause");
    return 0;
}
