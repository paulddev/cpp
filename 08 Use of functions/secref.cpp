#include <iostream>
int main()
{
	using namespace std;

	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;

	int bunnies = 50;
	rodents = bunnies;
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "bunnies address = " << &bunnies;
	cout << ", rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;

	int* pt = &rats;
	pt = &bunnies; // pt가 가리키는 방향이 바뀌여도 결과는 동일하다.

	cout << "bunnies address = " << &bunnies;
	cout << ", rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;

	return 0;
}