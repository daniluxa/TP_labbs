#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"

using namespace::std;
int coef;

template <typename T>
class Mult_template
{
public:
    T operator()(T i) const
    {
        if (round(sqrt(i)) == sqrt(i) && i != 1)
        {
            i *= coef;
        }
        return i;
    }
};


class Mult
{
public:
    int operator()(int i) const
    {
        if (round(sqrt(i)) == sqrt(i) && i != 1)
        {
            i *= coef;
        }
        return i;
    }
};

void task1()
{
    int n = 0, a = 0;
    vector<int> vec;

    Mult_template<int> mult;

    cout << "Введите размер вектора" << endl;
    cin >> n;

    int* output = new int[n];

    cout << "Введите элементы вектора" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        vec.push_back(a);
    }
    cout << "Введите масштабирующий коэффициент" << endl;
    cin >> coef;

    transform(vec.begin(), vec.end(), output, mult);

    for (int i = 0; i < n; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    task1();
}
