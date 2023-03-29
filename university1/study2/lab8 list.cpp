    
// Проверить, что в массиве есть хотя бы один чётный элемент. Если такой элемент есть, найти его номер.

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

bool reshenie(list <int> A)
{
    int i = 0;
    bool flg = false;
    list <int> ::iterator it = A.begin();
    while (it != A.end())
    {
        if (*it % 2 == 0)
        {
            cout << "Элемент под номером " << i + 1 << " четный " << endl;
            flg = true;
        }
        it++;
        i++;

    }
    return flg;
}

int main()
{
    setlocale(0, "");
    int n, a;
    cout << "Размер списка: "; cin >> n;
    list <int> A;
    list <int> ::iterator it;
    cout << "Введите эл-ты списка: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        A.push_back(a);
    }
    cout << "Получился список: " << endl;
    it = A.begin();
    while (it != A.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << "" << endl;
    if (reshenie(A) == false)
        cout << "Нет четных элементов" << endl;

}
