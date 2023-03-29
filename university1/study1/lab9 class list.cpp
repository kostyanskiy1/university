// lab9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//#include "stdafx.h"
#include <iostream>

#include <stdlib.h>
#include <string>
using namespace std;


struct Info {
    string FIO;
    int mat;
    int inf;
    int fiz;
    Info* next;
};

class list {
    int size;
    Info* h;//поле указатель на нач списка
public:
    list() { h = 0; size = 0; }//конструктор, пустой список
    ~list() { release(); }//удаление списка

    void pred();//добавление в нач списка
    void del();//удаление списка
    void print();
    void release();//уничтожение списка
    int get_size() {
        return size;
    }
    Info* elem(int i);
    void poisksredn(int n, double& srmat, double& srfiz, double& srinf);
    void vivodotlichnikov(double srmat, double srfiz, double srinf);

};

void list::pred() {
    Info* temp;
  
    temp = new Info;

    cout << "ФИО: " << endl;
    cin >> temp->FIO;

    cout << "Оценка по математике: " << endl;
    cin >> temp->mat;

    cout << "Оценка по информатике: " << endl;
    cin >> temp->inf;

    cout << "Оценка по физике: " << endl;
    cin >> temp->fiz;

    temp->next = h;
    h = temp;
    size++;

}

void list::del() {
    Info* temp;
    temp = h;
    h = h->next;
    delete temp;
}

void list::print() {
    Info* temp = h;
    while (temp != 0) {
        cout << temp->FIO << " --- математика : " << temp->mat << " --- информатика : " << temp->inf << " --- физика : " << temp->fiz << endl;
        temp = temp->next;
    }
    cout << "конец списка\n";
}

void list::release()
{
    while (h != 0)
        del();
}

void list::poisksredn(int n, double& srmat, double& srfiz, double& srinf) {
    double summat = 0; double sumfiz = 0; double suminf = 0;
    Info* temp = h;
    while (temp != 0) {
       summat = summat + temp->mat;
       sumfiz = sumfiz + temp->fiz;
       suminf = suminf + temp->inf;
       temp = temp->next;
    }

    srmat = (summat / n);
    srfiz = (sumfiz / n);
    srinf = (suminf / n);
    cout << "Среднее мат" << srmat << "\nСреднее физ" << srfiz << "\nСреднее инф" << srinf << endl;
}

void list::vivodotlichnikov(double srmat, double srfiz, double srinf) {
    Info* temp = h;
    while (temp != 0) {

        if ((temp->mat > srmat) && (temp->fiz > srfiz) && (temp->inf > srinf)) {
            cout<<"ОТЛИЧНИК\n" << temp->FIO << " --- математика : " << temp->mat << " --- информатика : " << temp->inf << " --- физика : " << temp->fiz << endl;
        }
        temp = temp->next;

    }

}

int main()
{
    setlocale(LC_ALL,"rus");
    Info inf;
    list list;
    double srmat = 0, srfiz = 0, srinf = 0;
    int i, n;
   
    cout << "Введите кол элементов: ";
    cin >> n;
    for (i = 0; i < n; i++) list.pred();
    cout << "Исходные данные: ";

    list.print();
    list.poisksredn(n, srmat, srfiz, srinf);
    list.vivodotlichnikov(srmat, srfiz, srinf);
    
    system("pause");
    return 0;
}

