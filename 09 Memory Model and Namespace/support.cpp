// external1.cpp�� ���� ����������.
#include <iostream>

extern double warming; // �ٸ� ���Ϸκ��� warming ���

void update(double dt);
void local();

using std::cout;

void update(double dt)
{
	extern double warming; // ������ �缱��
	warming += dt; // ���� warming ���
	cout << "���� warming = " << warming;
	cout << "���� ���ŵǾ����ϴ�.\n";
}

void local()
{
	double warming = 0.8; // �� ������ �ܺ� ���� warming �� ������.
	                      // ���� ������ ���� �������� �ռ��ٴ� ���� �����ش�.

	cout << "���� warmming = " << warming << "���Դϴ�.\n";
	cout << "�׷���, ���� warming = " << ::warming;
	cout << "���Դϴ�.\n";
}