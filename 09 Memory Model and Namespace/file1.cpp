#include <iostream>
#include "coordin.h" // ����ü ���ø�, �Լ� ����
using namespace std;

int main()
{
	rect rplace;
	polar pplace;

	cout << "x, y ���� �Է�: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "x, y ���� �Է�(�������� q�� �Է�): ";
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}