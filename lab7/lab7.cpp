#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace::std;

template <typename T>
void vectorPrint(vector<T> vec)
{
    for_each(vec.begin(), vec.end(), [](T& i) {cout << i << " "; });
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
    vector<float> accelarations(10);
    vector<float> speed;
    vector<float> distance_one_time;
    vector<float> distance;
    iota(accelarations.begin(), accelarations.end(), 0);
    cout << "Создал массив ускорений при помощи iota" << endl;
    vectorPrint(accelarations);

    random_device rd;
    mt19937 g(rd());
    shuffle(accelarations.begin(), accelarations.end(), g);
    cout << "Перемешал массив ускорений" << endl;
    vectorPrint(accelarations);

    partial_sum(accelarations.begin(), accelarations.end(), back_inserter(speed));
    cout << "Скорость на каждом участке" << endl;
    vectorPrint(speed);

    partial_sum(speed.begin(), speed.end(), back_inserter(distance_one_time));
    for_each(accelarations.begin(), accelarations.end(), [](float& i) {i /= 2; });
    transform(accelarations.begin(), accelarations.end(), speed.begin(), distance_one_time.begin(), plus<float>());
    cout << "Расстояния, пройденные за каждый промежуток времени" << endl;
    vectorPrint(distance_one_time);

    partial_sum(distance_one_time.begin(), distance_one_time.end(), back_inserter(distance));
    cout << "Суммарное расстояние на каждой отметке" << endl;
    vectorPrint(distance);
    

}

int main()
{
    setlocale(LC_ALL, "rus");
    //task1();
    task2();
    return 0;
}