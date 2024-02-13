#include <iostream>
#include <list>
#include <algorithm>

using namespace::std;

template <typename T=char>
class ChangeRegister
{
public:
	T operator()(T i) const
	{
		auto to_up  = [&i]() {i = toupper(i); };
		auto to_low = [&i]() {i = tolower(i); };

		if (isupper(i)) to_low();
		else to_up();
		return i;
	}
};


void task()
{
	list<char> lst;
	int n; char a = 0;

	cout << "Введите размер списка" << endl;
	cin >> n;

	char* output = new char[n];

	cout << "Введите спискок" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		lst.push_back(a);
	}

	std::transform(lst.begin(), lst.end(), output, ChangeRegister<char>{});

	for (int i = 0; i < n; i++) {
		cout << output[i] << " ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	task();
}
