// lab12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
using namespace std;
#include <math.h>

class geom
{
protected:
	double x;
public:
	geom(double a) { x = a; }
	virtual double Square() = 0;
	virtual double Volume() = 0;
};

class circle : public geom
{
public:
	circle(double z) :geom(z) {};
	double Square() override
	{
		return(3.14 * x * x);
	}
	double Volume() override
	{
		return 0;
	}
};

class rectangle : public geom
{
	double r;
public:
	rectangle(double z1, double z2) : geom(z1) { r = z2; };
	double Square() override
	{
		return(r * x);
	}
	double Volume() override
	{
		return 0;
	}
};

class triangle : public geom
{
	double b,c;
public:
	triangle(double z1, double z2, double z3) :geom(z1) { b = z2; c = z3; };
	double p = (x + b + c) / 2;
	double Square() override
	{
		return(sqrt(p*(p-x)*(p-b)*(p-c)));
	}
	double Volume() override
	{
		return 0;
	}
};

class Quadrate : public geom
{
public:
	Quadrate(double z1) :geom(z1) {};
	double Square() override { return (x * x); }
	double Volume() override
	{
		return 0;
	}
};


class Prism :public geom
{
private:
	double H;//высота призмы
	double h;//высота треугольника
	double a;//сторона треугольника
public:
	Prism(double z1, double z2, double z3, double z4) :geom(z1) { H = z2; h = z3; a = z4; }
	double Volume() override { return(0.5 * a * h * H); }//0.5*a*h = площадь основания. *H = объём призмы треугольной

	double Square() override
	{
		return 0;
	}
};


class Tor :public geom
{
private:
	double R;//радиус от центра до оси
	double r;//радиус окружности

public:
	Tor(double z1, double z2, double z3) :geom(z1) { R = z2; r = z3; }
	double Volume() override { return(2*3.14*3.14*R*r*r); }//объем
	double Square() override
	{
		return 0;
	}
};



int main()
{
	setlocale(LC_ALL, "RUS");
	geom* p[3];
	//the remainder of the rectangle = TRofR(остаток от прямоугольника)
	double TRofR = 0;
	circle Circle(2);
	rectangle Pir(12, 5);
	triangle Treugol(3, 5,6);
	p[0] = &Circle;
	p[1] = &Pir;
	p[2] = &Treugol;
	TRofR = p[1]->Square() - p[0]->Square() - p[2]->Square();
	cout <<"После вычитания фигур из прямоугольника P получим площадь = " << TRofR <<endl;
	
	Prism PriTri(1, 3, 5, 6);
	double VolumeOfPrism = PriTri.Volume();
	cout << "Объём заданной треугольной призмы = " << VolumeOfPrism << endl;

	Tor tor(1, 4, 4);
	double VolumeofTor = tor.Volume();
	cout << "Объём заданного тора = " << VolumeofTor << endl;


	system("pause");
	return(0);
}
