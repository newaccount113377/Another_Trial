#include <iostream>
using namespace std;
int main(int argc,
	char* argv[])
{
	int a = 0; //�������
	int b = 0; //��������
	int c = 0; //�������� �������
	cin >> a >> b;
	while (a >= b) {
		a = a - b;
		c++;
	}
	cout << "c=" << c << endl;
	return EXIT_SUCCESS;
}