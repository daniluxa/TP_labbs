#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace::std;

template <typename T>
void vectorPrint(vector<T> vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int sortVec(int a)
{
    int cnt = 0;
    while (1)
    {
        if (a % 3 != 0) break;
        cnt++;
        a /= 3;
    }
    return cnt;
}

void task1()
{
    vector<int> vec(23);
    iota(vec.begin(), vec.end(), 12);
    cout << "Создал вектор при помощи iota" << endl;
    vectorPrint(vec);

    random_device rd;
    mt19937 g(rd());
    shuffle(vec.begin(), vec.end(), g);
    cout << "Перемешал вектор" << endl;
    vectorPrint(vec);

    sort(vec.begin(), vec.end(), [](int a, int b) { return sortVec(a) < sortVec(b); });
    cout << "Отсортировал вектор по кратности 3" << endl;
    vectorPrint(vec);

}

void task2()
{

}

int main()
{
    setlocale(LC_ALL, "rus");
    task1();
    //task2();
    return 0;
}