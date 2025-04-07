// external1.cpp와 같이 컴파일하자.
#include <iostream>

extern double warming; // 다른 파일로부터 warming 사용

void update(double dt);
void local();

using std::cout;

void update(double dt)
{
	extern double warming; // 선택적 재선언
	warming += dt; // 전역 warming 사용
	cout << "전역 warming = " << warming;
	cout << "도로 갱신되었습니다.\n";
}

void local()
{
	double warming = 0.8; // 새 변수로 외부 변수 warming 을 가린다.
	                      // 지역 변수가 전역 변수보다 앞선다는 것을 보여준다.

	cout << "지역 warmming = " << warming << "도입니다.\n";
	cout << "그러나, 전역 warming = " << ::warming;
	cout << "도입니다.\n";
}