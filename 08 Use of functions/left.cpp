#include <iostream>
const int ArSize = 80;
char* left(const char* str, int n = 1);
int main()
{
	using namespace std;
	char sample[ArSize];
	cout << "문자열을 입력: \n";
	cin.get(sample, ArSize);

	char* ps = left(sample, 4);
	cout << ps << endl;
	delete[] ps; // 구 문자열을 메모리에서 삭제

	ps = left(sample);
	cout << ps << endl;
	delete[] ps;
	return 0;
}

// str 문자열의 앞에서부터 n개의 문자를 취하여
// 새로운 문자열을 구성하고, 그것을 지시하는 포인터를 리턴한다.
char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;

	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; i++)
	{
		p[i] = str[i]; // 문자들을 복사한다.
	}

	while (i <= n)
		p[i++] = '\0'; // 문자열의 나머지를 '\0'으로 설정한다. (문자열의 끝을 의미)

	return p;
}