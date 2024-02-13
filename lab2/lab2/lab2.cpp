#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace :: std;

void task1()
{
    list<int> list1;
    list<int> list2;
    int n, a;
    
    cout << "Введите размер 1-го массива" << endl;
    cin >> n;
    cout << "Введите первый массив" << endl;

    
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        list1.push_back(a);
    }
    list1.sort();

    cout << "Введите размер 2-го массива" << endl;
    cin >> n;
    cout << "Введите второй массив" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        list2.push_back(a);
    }
    list2.sort();

    list2.merge(list1);
    list2.reverse();
    for (int n : list2)
        std::cout << n << " ";

}

void task2()
{
    vector<int> vec;
    printf("Введите строку: ");
    string str;
    cin >> str;
    int result = 0;
    int iter = 0;

    string a;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '\n')
        {
            a = str.substr(iter, i);
            iter = i+1;
            int c{ std::stoi(a) };
            vec.push_back(c);
        }
    }

    a = str.substr(iter, str.size() + 1);
    int c{ std::stoi(a) };
    vec.push_back(c);


    for (int i = 0; i < str.size(); i++)
    {

        switch (str[i])
        {
            case '+': 
                result = vec[0] + vec[1]; 
                vec.push_back(result);
                vec.erase(vec.begin() + 0);
                vec.erase(vec.begin() + 0);
                break;
            case '-': 
                result = vec[0] - vec[1];
                vec.push_back(result);
                vec.erase(vec.begin() + 0);
                vec.erase(vec.begin() + 0);
                break;
                break;
            case '*': 
                result = vec[0] * vec[1];
                vec.push_back(result);
                vec.erase(vec.begin() + 0);
                vec.erase(vec.begin() + 0);
                break;
                break;
            case '/': 
                result = vec[0] / vec[1];
                vec.push_back(result);
                vec.erase(vec.begin() + 0);
                vec.erase(vec.begin() + 0);
                break;
                break;

            default: break;
        }
    }
    
    cout << str << " = " << result << endl;

}

int main()
{
    setlocale(LC_ALL, "rus");
    //task1();
    task2();
    return 0;
}
