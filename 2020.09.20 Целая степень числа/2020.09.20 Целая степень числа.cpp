#include <iostream>
#include <clocale>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int n = 0; //��������� �������
	int p = 0; //���������� �������
	int a = 0; //"�����������" ��������� �������
	cout << "��������� �������-?" << endl;
	cin >> n;
	a = n;
	cout << "���������� �������-?" << endl;
	cin >> p;
	if ((n == 0) & (p == 0))
	{
		cout << "0^0, ���� ��� ��������" << endl;
	}
	else if (p == 0)
	{
		cout << "n^p=" << 1 << endl;
	}
	else
	{
		for (int i = 1; i < p; i++)
		{
			n = n * a;
		}
		cout << "n^p=" << n << endl;
	}
	return EXIT_SUCCESS;
}