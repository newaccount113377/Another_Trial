#include<iostream>
#include<cmath>
#include<iomanip>


double myFunction(double x, int n){										//�������, ����������� ������������ �������� �������� ����
	double s = 1;														//� ������� ���������� � ��� �������
	double d = -x * x / 2;
	for (int i = 2; abs(d) >= pow(10, -n); i += 2)
	{
		s += d;															//�������� ������ ������ ���� �������
		d = -d * x * x / (i + 1) / (i + 2);								//���������� ���������� ����� ����, ��������� ����������
	}
	return s;
}


int main(){
	setlocale(LC_ALL, "Russian");

	double x = 0;
	int n = 0;
	std::cout << "������� x - ������ ���� � ��������" << std::endl;
	std::cin >> x;

	x = x * acos(-1) / 180;												//�������� ���� � ��������, ������� ����������� ��� ���������� ��������

	std::cout << "������� n - ������� ��������" << std::endl;
	std::cin >> n;
	std::setprecision(n);

	std::cout << "cos(x) = " << cos(x) << std::endl;					//��������� �������� �������� ����, ����������� � ������� ���������� 
	std::cout << "cos(x) ~ " << myFunction(x, n) << std::endl;			//cmath � ������� myFunction

	return 0;
}