
// 3. Проверить, что в массиве есть хотя бы один чётный элемент. Если такой элемент есть, найти его номер.

#include <iostream>
#include <vector>
using namespace std;

bool reshenie(vector <int> A)
{
    bool flg = false;
    for (int i = 0; i < A.size(); i++)
    {
        if (A.at(i) % 2 == 0)
        {
            cout << "Элемент под номером " << i + 1 << " четный " << endl;
            flg = true;
        }
    }
    return flg;
}

int main()
{
    setlocale(0, "");
    int n, a;
    cout << "Размер массива: "; cin >> n;
    vector <int> A;
    cout << "Введите эл-ты массива: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        A.push_back(a);
    }
    cout << "Получился массив: " << endl;
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << "" << endl;
    if (reshenie(A) == false)
        cout << "Нет четных элементов" << endl;

}

