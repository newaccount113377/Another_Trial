#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int n = -1; //�������� �����
	int k = 0; //���������� ��������� ��������� �����
	int c = 0;
	cin >> n;
	if (n == 0)
	{
		cout << "k=" << 0 << endl;
	}
	else
	{
		for (int i = 1; i*i <= n; i++)
		{
			if (n % i == 0)
			{
				k++;
			}
			if (i * i == n)
			{
				k--;
				c = i * i;
			}
		}
		cout << endl;
		if (c == n)
		{
			cout << "k=" << 2 * k + 1 << endl;
		}
		else
		{
			cout << "k=" << 2 * k << endl;
		}
	}
	return EXIT_SUCCESS;
}