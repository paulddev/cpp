#include <iostream>
extern int tom;       // tom�� �ٸ� ���Ͽ� ���ǵǾ� �ִ�.
static int dick = 10; // �ܺ� dick�� ���� ������.
int harry = 200;      // ���� ����, �ܺ� ��ũ (�ܺ� ������ ����)

void remote_access()
{
	using namespace std;
	cout << "remote_access()�� �����ϴ� 3 ������ �ּ�:\n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
}