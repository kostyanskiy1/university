using namespace std;
#include <iostream>

#include <windows.h>



class complex {
private:
    double real;
    double image;

public:
    complex(double real = 1, double image = 2) {
        this->real = real;
        this->image = image;
    }


    void print()
    {
        cout << real << " " << image << " i " << endl;
    }


    complex operator+(const complex& obj)
    {
        return complex(real + obj.real, image + obj.image);
    }

    complex operator+(int x)
    {
        return complex(real + x, image);
    }


    complex operator-(const complex& obj)
    {
        return complex(real - obj.real, image - obj.image);
    }

    complex operator-(int x)
    {
        return complex(real - x, image);
    }

    complex operator*(const complex& obj)
    {
        return complex(real * obj.real - image * obj.image, real * obj.image + image * obj.image);
    }

    void addimage(int x)
    {
        image += x;
    }
    void addimage(double x)
    {
        image += x;
    }
    void assign(double a, double b)
    {
        this->real = a;
        this->image = b;
     }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введите кол-во эл массива А" << endl;
    cin >> n;
    complex *a = new complex[n];
    complex *b = new complex[n];

    double x, y;

    cout << "Вводим эл массива А\n" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Введите эл массива\n" << endl;
        cin >> x >> y;
        a[i].assign(x, y);

    }

    cout << "Массив:\n" << endl;
    for (int i = 0; i < n; i++) {
        a[i].print();
    }

    int i = n - 1;
    for (int j = 0; j < n; j++) {
        b[j] = a[i];
        i--;
   
    }


    cout << "Обратный Массив:\n" << endl;
    for (int j = 0; j < n; j++) {
        b[j].print();
    }


    system("pause");
    return 0;

}

