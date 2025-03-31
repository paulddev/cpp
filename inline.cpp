#include <iostream>

inline double square(double x)
{
	return x * x;
}

int main()
{
	using namespace std;

	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5); // 인라인은 수식도 전달 가능하다.
	cout << "a = " << a << ", b = " << b << endl;
	cout << "c = " << c;
	cout << ", c의 제곱 = " << square(c++) << endl;
	cout << "현재 c = " << c << endl;
	return 0;
}