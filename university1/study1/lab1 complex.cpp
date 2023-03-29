
using namespace std;
#include <iostream>


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

};

int main()
{
    complex a(1, 2), b(1, 3);
    complex c = a + b;
    complex d = a - b;
    complex f = a * b;
    complex ad;
    cout << "ad: "; ad.print();
    cout << "c: "; c.print();
    cout << "d: "; d.print();
    cout << "f: "; f.print();
    c.addimage(5);
    cout << "c addi 5: "; c.print();
    f = a + 5;
    cout << "a +5: : "; f.print();
    return 0;
}

