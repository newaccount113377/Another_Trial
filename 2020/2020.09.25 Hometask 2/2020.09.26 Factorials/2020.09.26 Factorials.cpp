#include <iostream>

int factorial(int a) {											//�������, ����������� ��������� ����� a
	int b = a;													//����� ��� ���������� ���������� ����������� �������� � �������
	for (int i = 1; i < b; i++)									//�� ������������ �������, �.�. ��� �� ���� ����� ��������, ��������� ������� deltaFactorial
		a *= i;

	return a;
}

int deltaFactorial(int a, int b, int a1) {						//�������, ����������� ��������� ����� b, ���� �������� ��������� ����� a(a!=a1)
	int c = a1;													//���������������, ��� a <= b � ��� ���������� b! ���������� ��������� a! �� ����������� ���������
	if (a < b)													//����� �� ������������ ������� factorial, ���������� ��������� ��������� ����������� 
		for (int i = a + 1; i <= b; i++)						//�������� � �������, ��� a! = deltaFacrotial(1, a, 1) (��������� ���, ��� 1! = 1) 
			c = c * i;
	else if (a == b)
		c = a1;

	return c;
}

void sorting(int*& arr, int& cap) {								//bubbleSort, ����������� ��������� � ���, ��� � ������� deltaFactorial �������� ����� a < b
	int c = 0;
	for (int j = 0; j < cap; ++j) {
		for (int i = 0; i < cap - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				c = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = c;
			}
		}
	}
	std::cout << "��������������� ������:" << std::endl;
	for (int i = 0; i < cap; ++i)
		std::cout << "a[" << i << "] = " << arr[i] << std::endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	double s = 0;
	int cap = 0;
	std::cout << "������� ����� ��������� � ������������������ {Xn}" << std::endl;
	std::cin >> cap;

	int* a = new int[cap] {0};
	int* b = new int[cap] {0};
	std::cout << "������� " << cap << " ����� ������������������ {Xn}. Xi ������ ���� ������ 10" << std::endl;
	for (int i = 0; i < cap; ++i)
		std::cin >> a[i];

	sorting(a, cap);
	std::cout << std::endl << "������ �����������:" << std::endl;
	b[0] = factorial(a[0]);
	std::cout << "b[0] = " << b[0] << std::endl;
	for (int i = 1; i < cap; ++i) {
		b[i] = deltaFactorial(a[i - 1], a[i], b[i - 1]);
		s = s + b[i];
		std::cout << "b[" << i << "] = " << b[i] << std::endl;
	}
	std::cout << "������� �������������� ����������� = " << (s + b[0]) / cap << std::endl;

	return EXIT_SUCCESS;
}