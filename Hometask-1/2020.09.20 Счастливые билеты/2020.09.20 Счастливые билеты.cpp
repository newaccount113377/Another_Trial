#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int s = 0; //����� ���� � ������
	int n = 0; //������� ���������� �����
	int a = 0; //����� ���� � ������������ �����
	int c = 0;
	int a1 = 0;
	int a2 = 0;
	int a3 = 0; //���� �� ���, � ��� �����.
	int c1 = 0; //��� ������� ����� � ������� "���������� ������(������)".
	int c2 = 0; //��� ���� if'��, ������� ����� ������ ��� ����, ����� �������� ������ � ������ ����� ������.
	int c3 = 0; //��������, �� 8008, � 008008.
	cin >> s;
	for (int b = 0; b <= 999; b++)
	{
		a1 = b / 100;
		a2 = (b / 10) % 10;
		a3 = b % 10;
		a = a1 + a2 + a3;
		if (a == s)
		{
			n++;
			for (int d = 0; d <= 999; d++)
			{
				c1 = d / 100;
				c2 = (d / 10) % 10;
				c3 = d % 10;
				c = c1+c2+c3;
				if (c == s)
				{
					cout << a1 << a2 << a3 << c1 << c2 << c3 << endl;
				}
			}
		}
	}
	cout << "n=" << n * n << endl; //�.�. �� ������� ����������� �����, �� ���������� ���������� ������� ����� � n ��� ������.
	return EXIT_SUCCESS;
}