#include <iostream>
void oil(int x);
int main()
{
	using namespace std;

	int texas = 31;
	int year = 2011;
	cout << "main()����, texas = " << texas << ", &texas = " << &texas << endl;
	cout << "main()���� year = " << year << ", &year = " << &year << endl;
	
	oil(texas);

	cout << "main()����, texas = " << texas << ", &texas = " << &texas << endl;
	cout << "main()���� year = " << year << ", &year = " << &year << endl;
	return 0;
}

void oil(int x)
{
	using namespace std;
	int texas = 5;


	cout << "oil()����, texas = " << texas << ", &texas = " << &texas << endl;
	cout << "oil()���� x = " << x << ", &x = " << &x << endl;
	{
		int texas = 113;
		cout << "��Ͽ���, texas = " << texas << ", &texas = " << &texas << endl;
		cout << "��Ͽ���, x = " << x << ", &x = " << &x << endl;
	}
	cout << "����� ����� ��, texas = " << texas << ", &texas = " << &texas << endl;
}