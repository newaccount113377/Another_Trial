#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int s = 0; //����� ���� � ������
	int n = 0; //������� ���������� �����
	int a = 0; //����� ���� � ������������ �����
	cin >> s;
	for (int b = 0; b <= 999; b++)
	{
		a = b % 10 + (b % 100 - b % 10) / 10 + (b - b % 100) / 100;
		if (a == s)
		{
			n++;
		}
	}
	cout << "n=" << n * n << endl; //�.�. �� ������� ����������� �����, �� ���������� ���������� ������� ����� � n ��� ������.
	return EXIT_SUCCESS;
}