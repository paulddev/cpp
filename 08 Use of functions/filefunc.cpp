#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream& os, double fo, const double fe[], int n);
const int LIMIT = 5;
int main()
{
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << fn << "파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}

	double objective;
	cout << "대물렌즈 초점거리를 mm 단위로 입력: ";
	cin >> objective;
	double eps[LIMIT];
	cout << LIMIT << "가지 대안렌즈의 초점거리를 mm 단위로 입력:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "대안렌즈 #" << i + 1 << ": ";
		cin >> eps[i];
	}

	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
	cout << "종료\n";
	return 0;
}

void file_it(ostream& os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;
	// setf() 호출을 하기 전에 유효한 모든 포맷팅 설정들의 복사본을 리턴한다.
	initial = os.setf(ios_base::fixed); // 초기 포맷팅 상태 저장

	os.precision(0);
	os << "대물렌즈의 초점거리: " << fo << " mm\n";
	os.setf(ios::showpoint); // 뒤따르는 숫자들이 0인 경우에도 뒤에 붙은 소수점을 표시하는 모드에 객체를 놓는다.
	os.precision(1); // (객체가 고정 소수점 표기 모드에 놓였을 때, 소수점의 오른쪽에 표시할 숫자들의 개수를 지정한다.
	os.widen(17);
	os << "대안렌즈 초점거리";
	os.widen(15); // 다음 출력 동작에 사용할 필드 폭을 설정한다.
	os << "확대배율" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(17);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial); // 초기 포맷팅 상태 복원
}