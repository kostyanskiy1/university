
using namespace std;
#include <iostream>
#include <stdlib.h>


class vect {

    int *base;
    int size;

public:
    vect() {
        size = 5; base = new int[size];
    }

    vect(int n);

    ~vect() { delete[] base; }
    void input();

    void print();

    int get_size() { return size; }
    int& element(int i);

    int maxelem();
    int maxelemi();
    void resh(int i);
};


vect::vect(int n) {

    if (n < 1) {

        cerr << "Неверные границы\n" << n << endl; exit(1);
    } size = n; base = new int[size];
}

int& vect::element(int i) {
    if (i < 1 || i >= size) { cout << "Неверные границы" << i << endl; exit(1); }
    return (base[i]);
}

void vect::print()
{
    cout << "vivod vector = " << endl;
    for (int i = 0; i < size; i++)
        cout << base[i] << " ";
            cout << endl;
}


void vect::input()
{
    cout << "vvod vector = " << endl;
    for (int i = 0; i < size; i++)
        cin >> base[i] ;
}



int vect::maxelem() {
    int maksi = base[0];
    for (int i = 0; i < size; i++)
        if (base[i] > maksi) maksi = base[i];
    return maksi;

}

int vect::maxelemi() {
    int maksii,maksi = base[0];
    for (int i = 0; i < size; i++)
        if (base[i] > maksi) {
            maksi = base[i];
            maksii = i;
        }
        else maksii = 0;
    return maksii;

}

void vect::resh(int n)
{
    for (int i = n; i < size; i++)
        base[i] = base[i + 1];
    base[size - 1] = 0;
}



int  main(void)
{
	int n, nomer;
    cout << "vvedite kol-vo elementov=";
    cin >> n;
	vect x(n); int maksimalniy; x.input(); x.print();
	maksimalniy = x.maxelem();
	cout << "maximim=\n" << maksimalniy << endl;
	nomer = x.maxelemi();
	cout << "maximimi=\n" << nomer+1 << endl;
	x.resh(nomer);
	cout << "polych massiv" << endl;
	x.print();
	system("pause");
	return 0;
}

