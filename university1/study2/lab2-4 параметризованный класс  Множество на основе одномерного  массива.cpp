// Lab1-4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
using namespace std;

class Complex {
private:
    int re, im;
public:
    Complex(int x = 0, int y = 0)
    {
        re = x;
        im = y;
    }
    bool operator ==(Complex x) {

        return ((re == x.re) && (im == x.im));
    }
    bool operator !=(Complex x) {

        return sqrt(pow(re, 2) + pow(im, 2)) != sqrt(pow(x.re, 2) + pow(x.im, 2));
    }
    Complex& operator = (Complex& x) {
        re = x.re;
        im = x.im;
        return *this;
    }
    bool operator < (Complex& x) {

        return sqrt(pow(re, 2) + pow(im, 2)) < sqrt(pow(x.re, 2) + pow(x.im, 2));
    }
    friend ostream& operator <<(ostream& out, Complex x);
    friend istream& operator >>(istream& in, Complex& x);

};
ostream& operator <<(ostream& out, Complex x) {

    out << x.re << " " << x.im << "i\t";
    return out;

}
istream& operator >>(istream& in, Complex& x) {

    in >> x.re;
    in >> x.im;
    return in;

}

template<class T>
class set {
private:
    int size;
    T* array;
public:
    set() {
        size = 0;
        array = new T[size];
    }

    set(int s) {
        size = s;
        array = new T[size];
        for (int i = 0; i < size; i++) array[i] = 0;
    }

    set(const set& obj) {
        size = obj.size;
        array = new T[size];
        for (int i = 0; i < size; i++) array[i] = obj.array[i];
    }

    ~set() { delete[] array; }
    void input();
    void output();
    void uni(set, set);
    void cross(set, set);
    void add(set);
    void del(set);
    bool check(T);
    bool amount(set, set, set);//kod dlya ind zad

    int get(T);
    void operator = (set);
};
template<class T>

void set<T>::input() {
    cout << "Введите размер: ";
    cin >> size;
    array = new T[size];
    for (int i = 0; i < size; i++) {
        cout << "Введите элемент [" << i + 1 << "]: ";
        cin >> array[i];
    }
}
template<class T>

void set<T>::output() {
    cout << "Множество:" << endl;
    for (int i = 0; i < size; i++) cout << array[i] << " ";
    cout << endl;
}
template<class T>

void set<T>::uni(set a, set b) {
    this->size = a.size + b.size;
    this->array = new T[size];
    int count = 0;
    int n = a.size;

    for (int i = 0; i < a.size; i++) array[i] = a.array[i];
    for (int i = 0; i < b.size; i++) {
        for (int j = 0; j < a.size; j++)
            if (b.array[i] == a.array[j]) continue;
            else count++;
        if (count == a.size) array[n++] = b.array[i];
        count = 0;
    }
    size = n;
}
template<class T>

void set<T>::cross(set a, set b) {
    size = a.size + b.size;
    array = new T[size];
    int n = 0;
    for (int i = 0; i < a.size; i++)
        for (int j = 0; j < b.size; j++) {
            if (a.array[i] == b.array[j]) {
                array[n++] = a.array[i];
                continue;
            }
        }
    size = n;
}
template<class T>

void set<T>::add(set r) {
    T a[100], element;
    int i;
        
    cout << "Введите новый элемент: ";
    cin >> element;

    if (!(r.check(element))) {

        for (i = 0; i < size; i++) a[i] = array[i];
        delete[] array;
        size = size + 1;
        a[i] = element;
        array = new T[size];
        for (i = 0; i < size; i++) array[i] = a[i];
    }

    else cout << "Элемент " << element << " состоит в множестве и не будет добавлен" << endl;

}
template<class T>

void set<T>::del(set r) {

    T element;
    cout << "Введите элемент, который надо удалить: ";
    cin >> element;

    if (r.check(element)) {

        T a[10];
        for (int i = 0; i < size; i++)
            if (array[i] == element) {
                for (int j = 0; j < i; j++) a[j] = array[j];
                for (int z = i + 1; z < size + 1; z++) a[z - 1] = array[z];
            }
        size--;
        array = new T[size];
        for (int i = 0; i < size; i++) array[i] = a[i];
    }
    else cout << "Такого элемента нет в множестве" << endl;
}
template<class T>

bool set<T>::check(T elem) {

    bool k = false;

    for (int i = 0; i < size; i++)
        if (array[i] == elem) k = 1;

    return k;
}


template<class T>
int set<T>::get(T n) {
    return this->array[n];
}
template<class T>

void set<T>::operator = (set a) {
    int i;
    delete[] this->array;
    this->size = a.size;
    this->array = new T[size];
    for (i = 0; i < size; i++) array[i] = a.array[i];
}


template <class T>
bool set<T>::amount(set r1, set r2, set r3) {  //kod dlya ind zad
    return  ((r1.size == r3.size) && (r2.size == r3.size))  ;
   
}

int main()
{
    setlocale(0, "rus");

    int kol;
    cout << "Введите кол-во автобаз: " << endl;
    cin >> kol;
    set<string>* ABC = new set<string>[kol];

    for (int i = 0; i < kol; i++){
        cout << "Ввод и вывод " << i + 1 << " автобазы " << endl;
    ABC[i].input();
    ABC[i].output();
}


    cout << "Проверка наличия хотя бы двух одинаковых автобаз " << endl;


    int m1 = -1;
    int m2 = -1;
    set <string> C;

    for (int i = 0; i < kol-1; i++) {
        for (int j = i+1; j < kol; j++) {

            C.uni(ABC[i], ABC[j]);
           
            if (C.amount(ABC[i], ABC[j], C)) {
                m1 = i;
                m2 = j;

            }
         }
      
        if (m1 != -1){
            cout << "Номера одинаковых автобаз: " << m1 + 1 << " и " << m2 + 1 << endl;
            cout << "Марки машин на автобазах: ";
            ABC[m1].output();
           
        }
    }

    if (m1 == -1) cout << "Одинаковых автобаз нет" << endl;

    


   /* set<int> a;
    cout << "Ввод и вывод 1 множества " << endl;
    a.input();
    a.output();
    set<int> b = a;
    cout << "Инициализация множества 2 " << endl;
    b.output();
    std::cout << "Ввод множества 2 " << endl;
    b.input();
    set<int> c;
    cout << "Объединение множеств " << endl;
    c.uni(a, b);
    c.output();
    set<int> d;
    d.cross(a, b);
    cout << "Пересечение множеств" << endl;
    d.output();
    cout << "Добавка элемента " << endl;
    c.add(c);
    c.output();


    cout << "Проверка элемента множества" << endl;
    cout << "Введите  элемент, который хотите проверить: ";
    int prv;
    cin >> prv;
    if (c.check(prv) == 1) cout << "Элемент состоит в множестве" << endl;
    if (c.check(prv) == 0) cout << "Элемент ne состоит в множестве" << endl;

    cout << "Удаление элемента множества" << endl;
    c.del(c);
    c.output();*/

    system("pause");
    return 0;
}
