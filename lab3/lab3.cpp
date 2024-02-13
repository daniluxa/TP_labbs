#include <iostream>
#include <typeinfo>
#include <string>
#include "math.h"

using namespace::std;

#define pi 3.14159265358979

class geometry_figure
{
protected:
    string name = "figure";
    int amount_of_angels = 0;
    int h;
    double v;

public:
    void print()
    {
        cout << "Объём фигуры " << name << " = " << v << endl;
    }
    geometry_figure(string name, int h)
    {
        this->name = name;
        this->h = h;
    }
};

class ball_layer : public geometry_figure
{
public:
    int r;
    void calc_volume()
    {
        v = 2 * pi * r * r * h / 3;
    }
    using geometry_figure :: geometry_figure;
};

class pyramid : public geometry_figure
{
public:
    int s1, s2;
    void calc_volume()
    {
        v = h * (s1 + sqrt(s1*s2) + s2) / 3;
    }
    using geometry_figure::geometry_figure;
};

class prisma : public geometry_figure
{
public:
    int a;
    void calc_volume()
    {
        v = a * a * h;
    }
    using geometry_figure::geometry_figure;
};


int main()
{
    setlocale(LC_ALL, "rus");
    int r,  h, s1, s2, a;
    cout << "Введите радиус шарового слоя" << endl;
    cin >> r;
    cout << "Введите высоту шарового слоя" << endl;
    cin >> h;

    ball_layer ball_layer1{"'Шаровый слой'", h};
    ball_layer1.r = r;

	cout << "Введите площадь нижнего основания усеченной пирамиды с ромбическим основанием" << endl;
    cin >> s1;
    cout << "Введите площадь верхнего основания усеченной пирамиды с ромбическим основанием" << endl;
    cin >> s2;
    cout << "Введите высоту усеченной пирамиды с ромбическим основанием" << endl;
    cin >> h;

    pyramid pyramid1{"'Усеченная пирамида с ромбическим основанием'", h};
    pyramid1.s1 = s1;
    pyramid1.s2 = s2;

    cout << "Введите сторону основания прямой призмы с квадратным основанием" << endl;
    cin >> a;
    cout << "Введите высоту прямой призмы с квадратным основанием" << endl;
    cin >> h;

    prisma prisma1{ "'Прямая призма с квадратным основанием'", h };
    prisma1.a = a;

    ball_layer1.calc_volume();
    ball_layer1.print();
    pyramid1.calc_volume();
    pyramid1.print();
    prisma1.calc_volume();
    prisma1.print();

    const type_info& ti1 = typeid(ball_layer1);
    const type_info& ti2 = typeid(pyramid1);
    const type_info& ti3 = typeid(prisma1);

    cout << ti1.name() << endl;
    cout << ti2.name() << endl;
    cout << ti3.name() << endl;
}
