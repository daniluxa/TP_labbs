#include <iostream>
#include <memory>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

using namespace::std;

//struct node
//{
//    int info;                           //Информационное поле
//    unique_ptr <node> l;                   //Левая часть дерева
//    unique_ptr <node> r;                   //Правая часть дерева
//};
//
//void add(int a, node** t)
//{
//    if ((*t) == NULL)                   //Если дерева не существует
//    {
//        (*t) = new node;                //Выделяем память
//
//        (*t)->info = a;                 //Кладем в выделенное место аргумент a
//        //(*t)->l = (*t)->r = NULL;       //Очищаем память для следующего роста
//        return;                         //Заложили семечко, выходим
//    }
//    //Дерево есть
//    if (a > (*t)->info) add(a, &(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
//    else add(a, &(*t)->l);                //Иначе кладем его влево
//}
//
//void print(node* t, int u)
//{
//    if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
//    else
//    {
//        print(t->l, ++u);                   //С помощью рекурсии посещаем левое поддерево
//        for (int i = 0; i < u; ++i) cout << "|";
//        cout << t->info << endl;            //И показываем элемент
//        u--;
//    }
//    print(t->r, ++u);                       //С помощью рекурсии посещаем правое поддерево
//}

//void task1()
//{
//    node* tree = NULL;
//    int n;                              //Количество элементов
//    int s;                              //Число, передаваемое в дерево
//    cout << "введите количество элементов  ";
//    cin >> n;                           //Вводим количество элементов
//
//    for (int i = 0; i < n; ++i)
//    {
//        cout << "ведите число  ";
//        cin >> s;                       //Считываем элемент за элементом
//
//        add(s, &tree);                 //И каждый кладем в дерево
//    }
//    cout << "ваше дерево\n";
//    print(tree, 0);
//    cin.ignore().get();
//}


class Rocket
{
public:
    string name = "";
    int power = 0;
    float length = 0;
    float weight = 0;
    Rocket() {};
    ~Rocket() {}

    void print()
    {
        cout << "Имя: " << name << endl;
        cout << "Мощность: " << power << endl;
        cout << "Длина: " << length << endl;
        cout << "Вес: " << weight << endl;
    }

    void Init(string name, int power, float length, float weight)
    {
        this->name = name;
        this->power = power;
        this->length = length;
        this->weight = weight;
    }
};


void task2()
{
    string name = "";
    int power = 0;
    float length = 0, weight = 0;

    cout << "Введите имя ракеты" << endl;
    cin >> name;
    cout << "Введите мощность ракеты" << endl;
    cin >> power;
    cout << "Введите длину ракеты" << endl;
    cin >> length;
    cout << "Введите вес ракеты" << endl;
    cin >> weight;

    unique_ptr<Rocket> rocket(new Rocket);
    rocket->Init(name, power, length, weight);
    rocket->print();



}

int main()
{
    setlocale(LC_ALL, "rus");
    //task1();
    task2();
    return 0;
}