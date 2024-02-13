#include <iostream>

using namespace::std;

template <typename A, typename I, typename C>

void change(A *arr, I index, C chr, I n)
{
    arr[index] = chr;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}

double divide(float a, float b)
{
    if (b)
        return a / b;
    throw "Делить на ноль нельзя!";
}

void task1()
{
    char chr; int index, n;
    cout << "Введите длинну массива" << endl;
    cin >> n;
    char* arr = new char[n];
    cout << "Введите массив" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Введите индекс заменяемого элемента массива" << endl;
    cin >> index;

    cout << "Введите элемент, на который хотите заменить" << endl;
    cin >> chr;

    change(arr, index, chr, n);

    delete[] arr;
}

void task2()
{
    float a, b;
    cout << "Введите делимое" << endl;
    cin >> a;
    cout << "Введите делитель" << endl;
    cin >> b;

    try
    {
        double ans = divide(a, b);
        cout << "Частное = " << ans << endl;
    }
    catch (const char* error_message)
    {
        cout << error_message << endl;
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    //task1();
    task2();
    return 0;
}
