#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int n = 0; //���������� �������
	int k = 0; //2^n-1
	cin >> n;
	if (n == 0)
	{
		cout << "k=" << 0 << endl;
	}
	else
	{
		k = ~1;
		k = (unsigned int)k >> (32 - n); //�������, (unsigned int) ����� ������������...
		cout << "k=" << k << endl;
	}
	return EXIT_SUCCESS;
}