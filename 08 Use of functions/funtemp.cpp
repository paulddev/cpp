#include <iostream>

template <typename Any>
void Swap(Any& a, Any& b);

int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "(" << i << ", " << j << ")\n";
	Swap(i, j); // 컴파일러는 int형 버전의 Swap() 함수를 생성한다.
	cout << "(" << i << ", " << j << ")\n";

	double x = 24.5;
	double y = 81.7;
	cout << "(" << x << ", " << y << ")\n";
	Swap(x, y); // 컴파일러는 double형 버전의 Swap() 함수를 생성한다.
	cout << "(" << x << ", " << y << ")\n";

	return 0;
}

template <typename Any>
void Swap(Any& a, Any& b)
{
	Any temp;
	temp = a;
	a = b;
	b = temp;
}