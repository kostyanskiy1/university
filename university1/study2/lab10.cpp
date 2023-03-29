
/*
ЛР10
Картотека видеотеки организована  в виде массива  структур с полями :название фильма,
стоимость ,режиссер . Ввести информацию по видеотеки и вывести информацию о
фильмах одного режиссера.
*/
using namespace std;
#include <iostream>
#include <windows.h>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>

class videoteka
{
    string nazvanie;
    int price;
    string producer;
public:
    videoteka() { price = 0; }
    void enter()
    {
        cout << "Название: "; cin >> nazvanie; cout << "Стоимость: "; cin >> price; cout << "Режиссер: "; cin >> producer;
    }
    string get_nazvanie() { return nazvanie; }
    int get_price() { return price; }
    string get_producer() { return producer; }

    friend ostream& operator <<(ostream& out, const videoteka& s)
    {
        out << "Название: " << s.nazvanie << endl << "Стоимость: " << s.price << endl << "Режиссер: " << s.producer << endl;;
        return out;
    }

};

class proverka
{
public :
    void operator () (list<videoteka>A,string m)
    {
        list <videoteka> ::iterator it = A.begin();
        while (it != A.end())
        {
        
            if ((*it).get_producer() == m) {
                cout << "Фимьм: " << (*it).get_nazvanie() << "Стоимость: " << (*it).get_price() << endl;
            }
            it++;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    videoteka a;
    cout << "Размер списка: "; cin >> n;
    list <videoteka> A;
    list <videoteka> ::iterator it;
    cout << "Введите эл-ты списка: " << endl;
    for (int i = 0; i < n; i++)
    {
        a.enter();
        A.push_back(a);
    }
    cout << "\nПолучился список: " << endl;
    it = A.begin();
    while (it != A.end()) {
        cout << *it << " ";
        ++it;
    }
    string m;
    cout << "Имя режиссера: "; cin >> m;
    proverka f;
    f(A,m);
}
