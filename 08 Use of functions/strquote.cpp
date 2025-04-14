#include <iostream>
#include <string>
using namespace std;

string version1(const string& s1, const string& s2);
const string& version2(string& s1, const string& s2); // �μ� ȿ��(���α׷��ֿ��� �Լ��� ��ȯ�ϴ� ��� �ܿ� ���α׷� �ܺο��� ������ �� �ִ� ��ȭ
const string& version3(string& s1, const string& s2); // ���� ����

int main()
{
	string input;
	string copy;
	string result;

	cout << "���ڿ��� �Է�: ";
	getline(cin, input);
	copy = input;
	cout << "�Է��� ���ڿ�: " << input << endl;
	result = version1(input, "***");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;

	result = version2(input, "###");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;

	cout << "���� ���ڿ� �����\n";
	input = copy;
	result = version3(input, "@@@");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;

	return 0;
}

string version1(const string& s1, const string& s2)
{
	string temp;

	temp = s2 + s1 + s2;
	// ���ο� ���ڿ��� ����� �����Ѵ�.
	// string version4(string s1, string s2)�� �����ϰ� �����Ѵ�.
	// �ٸ� �̰�쿡�� s1�� s2�� ���� ��������� string ��ü�� �ǹǷ�
	// ������ ����ϴ� ���� �Լ��� ���ο� ��ü�� ���� �ʿ䰡 ����, �� ��ü���� ���ο� ��ü�� �����͸� ������ �ʿ䰡 ���� ������ �� ȿ�����̴�!
	// temp ��ü�� version1()���� �������� ���ο� ��ü��.
	// �ٸ� temp�� ������ �����ϰ� �Ǹ�, �� ������ �������� �ʴ´�.
	// temp�� ������ �ӽ� ���� ��ġ�� ����ǰ� ����, main()���� �� ���� ��ġ�� ������ result��� �̸��� string���� ����ȴٴ� ���� �ǹ��Ѵ�.
	// version1() �Լ��� ����� �� �ڽ��� ����� ������.
	return temp;
}

const string& version2(string& s1, const string& s2)
{
	s1 = s2 + s1 + s2;
	// �Լ��� ���޵� ������ �����ϹǷ� �����ϴ�.
	// version2()�� �ӽ� ���ڿ��� ������ �ʴ´�.
	// �� ��ſ� ���� ���ڿ��� ���� �����Ѵ�.
	return s1;
}

const string& version3(string& s1, const string& s2)
{
	string temp;

	temp = s2 + s1 + s2;
	// ���� ������ ���� ������ �����ϹǷ� �������� �ʴ�.
	// ���������� ����� ������ ���� ������ �����ϴ� ġ������ ������ ���� �޼���
	return temp;
}