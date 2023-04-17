#include <iostream>
#include <iomanip>
#include <ctime>

float* float_array(long n);                 //�������� ������� � n ��������� ���� float
double* double_array(long n);               //�������� ������� � n ��������� ���� double 
template <class T>
void moving_average(T* a, long n, int k);   //���������� ����������� ��������  � ������������������ ��� ����������� �������

int main(int argc, char* argv[])
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int k = 0;                                             //����� ����
	long n = 0;                                            //����� ��������� ���������
	std::cout << std::setprecision(13) << "������� ���������� ��������� n" << std::endl;
	std::cin >> n;

	int windows[6]{ 4, 8, 16, 32, 64, 128 };               //����� ����, ��� ������� ����������� ������������ �������������
	float* a_f = float_array(n);                           
	double* a_d = double_array(n);

	std::cout << std::endl << "float:" << std::endl;       //���������� ������������������ ��� ������� 
	for (int i = 0; i < 6; ++i)                            //k = 4, 8, 16, 32, 64 � 128 � ���� float
		moving_average(a_f, n, windows[i]);

	std::cout << std::endl << "double:" << std::endl;      //���������� ������������������ ��� �������
	for (int i = 0; i < 6; ++i)                            //k = 4, 8, 16, 32, 64 � 128 � ���� double
		moving_average(a_d, n, windows[i]);

	std::cout << std::endl << "������� ����� ���� k, ����� ����������" << std::endl;
	std::cout << "������� 0, ����� ���������" << std::endl;
	std::cin >> k;

	while (k != 0)                                         //�������� �� ������������ ��������� ������ ���������
	{
		std::cout << "float:" << std::endl;
		moving_average(a_f, n, k);
		std::cout << std::endl << "double:" << std::endl;
		moving_average(a_d, n, k);

		std::cout << std::endl << "������� ����� ���� k, ����� ����������" << std::endl;
		std::cout << "������� 0, ����� ���������" << std::endl;
		std::cin >> k;
	}
	return 0;
}


float* float_array(long n)
{
	float* a = new float[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = (float)(rand()) / 32767;                    //���������� ������� ������� �� 0 �� 1 ���� float
	}
	return a;
}

double* double_array(long n)
{
	double* a = new double[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = (double)(rand()) / 32767;                   //���������� ������� ������� �� 0 �� 1 ���� double
	}
	return a;
}

template <class T>
void moving_average(T* a, long n, int k)
{
	unsigned int start_time = clock();                     //������ ������ ���������
	T average = 0;                                         //�������� ����������� ��������
	for (int i = 0; i < k; ++i)                            
	{
		average += a[i];                                   //���������� �������� ��� ������ k ���������
	}
	average /= k;

	for (int i = k; i < n; ++i)
	{
		average += (a[i] - a[i - k]) / k;                  //���������� ����������� �������� �� k+1-���� �� n-���� ��������
	}
	unsigned int t = clock() - start_time;                 //����� ������ ���������
	std::cout << "����� �������� ��� k = " << k << ": " << t << std::endl;
	std::cout << "������������������: " << (double)(n) / t << std::endl;
}