#include <iostream>
#include "namesp.h"

namespace pers
{
	using std::cout;
	using std::cin;
	void getPerson(Person& rp)
	{
		cout << "�̸��� �Է��ϼ���: ";
		cin >> rp.fname;
		cout << "������ �Է��ϼ���: ";
		cin >> rp.lname;
	}

	void showPerson(const Person& rp)
	{
		cout << rp.lname << ", " << rp.fname;
	}
}

namespace debts
{
	void getDebt(Debt& rd)
	{
		getPerson(rd.name);
		cout << "��ä�� �Է��ϼ���: ";
		cin >> rd.amount;
	}

	void showDebt(const Debt& rd)
	{
		pers::showPerson(rd.name);
		cout << ": $" << rd.amount << std::endl;
	}

	double sumDebts(const Debt ar[], int n)
	{
		double total = 0;
		for (int i = 0; i < n; i++)
			total += ar[i].amount;
		return total;
	}
}