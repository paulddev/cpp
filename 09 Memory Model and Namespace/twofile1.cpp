#include <iostream>
int tom = 3;            // ���� ����, �ܺ� ��ũ (�ܺ� ������ ����)
int dick = 30;          // ���� ����, �ܺ� ��ũ (�ܺ� ������ ����)
static int harry = 300; // ���� ����, ���� ��ũ

void remote_access();

int main()
{
	using namespace std;
	cout << "main()�� �����ϴ� �� ������ �ּ�:\n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
	remote_access();
	return 0;
}