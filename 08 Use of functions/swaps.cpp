#include <iostream>
void swapr(int& a, int& b);
void swapp(int* p, int* q);
void swapv(int a, int b);
int main()
{
	using namespace std;
	int wallet1 = 3000;
	int wallet2 = 3500;

	cout << "wallet1: " << wallet1 << ", wallet2: " << wallet2 << endl;

	cout << "use reference\n";
	swapr(wallet1, wallet2); // ������ ����
	cout << "wallet1: " << wallet1 << ", wallet2: " << wallet2 << endl;

	cout << "use pointer\n";
	swapp(&wallet1, &wallet2); // ������ �ּҸ� ����
	cout << "wallet1: " << wallet1 << ", wallet2: " << wallet2 << endl;

	cout << "use value\n";
	swapv(wallet1, wallet2); // ������ ���� ����
	cout << "wallet1: " << wallet1 << ", wallet2: " << wallet2 << endl;
	return 0;
}

void swapr(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swapp(int* p, int* q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void swapv(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}