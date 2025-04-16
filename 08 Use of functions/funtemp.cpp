#include <iostream>

template <typename Any>
void Swap(Any& a, Any& b);

int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "(" << i << ", " << j << ")\n";
	Swap(i, j); // �����Ϸ��� int�� ������ Swap() �Լ��� �����Ѵ�.
	cout << "(" << i << ", " << j << ")\n";

	double x = 24.5;
	double y = 81.7;
	cout << "(" << x << ", " << y << ")\n";
	Swap(x, y); // �����Ϸ��� double�� ������ Swap() �Լ��� �����Ѵ�.
	cout << "(" << x << ", " << y << ")\n";

	return 0;
}

template <typename Any>
void Swap(Any& a, Any& b)
{
	Any temp;
	temp = a;
	a = b;
	b = temp;
}