#include <iostream>
#include "coordin.h" // 구조체 템플릿, 함수 원형
using namespace std;

int main()
{
	rect rplace;
	polar pplace;

	cout << "x, y 값을 입력: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "x, y 값을 입력(끝내려면 q를 입력): ";
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}