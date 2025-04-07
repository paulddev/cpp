#include <iostream>
extern int tom;       // tom은 다른 파일에 정의되어 있다.
static int dick = 10; // 외부 dick의 앞을 가린다.
int harry = 200;      // 정적 변수, 외부 링크 (외부 변수를 정의)

void remote_access()
{
	using namespace std;
	cout << "remote_access()가 보고하는 3 변수의 주소:\n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
}