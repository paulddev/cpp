#include <iostream>
#include <string>
using namespace std;

string version1(const string& s1, const string& s2);
const string& version2(string& s1, const string& s2); // 부수 효과(프로그래밍에서 함수가 반환하는 결과 외에 프로그램 외부에서 관찰할 수 있는 변화
const string& version3(string& s1, const string& s2); // 나쁜 설계

int main()
{
	string input;
	string copy;
	string result;

	cout << "문자열을 입력: ";
	getline(cin, input);
	copy = input;
	cout << "입력한 문자열: " << input << endl;
	result = version1(input, "***");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;

	result = version2(input, "###");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;

	cout << "원래 문자열 재생성\n";
	input = copy;
	result = version3(input, "@@@");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;

	return 0;
}

string version1(const string& s1, const string& s2)
{
	string temp;

	temp = s2 + s1 + s2;
	// 새로운 문자열을 만들고 리턴한다.
	// string version4(string s1, string s2)와 동일하게 동작한다.
	// 다만 이경우에는 s1과 s2는 새로 만들어지는 string 객체가 되므로
	// 참조를 사용하는 것이 함수가 새로운 객체를 만들 필요가 없고, 옛 객체에서 새로운 객체로 데이터를 복사할 필요가 없기 때문에 더 효율적이다!
	// temp 객체는 version1()에서 지역적인 새로운 객체다.
	// 다만 temp를 참조로 리턴하게 되면, 그 참조가 동작하지 않는다.
	// temp의 내용이 임시 리턴 위치로 복사되고 나서, main()에서 그 리턴 위치의 내용이 result라는 이름의 string으로 복사된다는 것을 의미한다.
	// version1() 함수가 종료될 때 자신의 존재는 끝난다.
	return temp;
}

const string& version2(string& s1, const string& s2)
{
	s1 = s2 + s1 + s2;
	// 함수에 전달된 참조를 리턴하므로 안전하다.
	// version2()는 임시 문자열을 만들지 않는다.
	// 그 대신에 원래 문자열을 직접 변경한다.
	return s1;
}

const string& version3(string& s1, const string& s2)
{
	string temp;

	temp = s2 + s1 + s2;
	// 지역 변수에 대한 참조를 리턴하므로 안전하지 않다.
	// 지역적으로 선언된 변수에 대한 참조를 리턴하는 치명적인 결함을 가진 메서드
	return temp;
}