#include <iostream>
int tom = 3;            // 정적 변수, 외부 링크 (외부 변수를 정의)
int dick = 30;          // 정적 변수, 외부 링크 (외부 변수를 정의)
static int harry = 300; // 정적 변수, 내부 링크

void remote_access();

int main()
{
	using namespace std;
	cout << "main()이 보고하는 세 변수의 주소:\n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
	remote_access();
	return 0;
}