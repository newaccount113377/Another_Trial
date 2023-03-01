#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>
#include <ctime>
using namespace std;

void bisection(pair<double, double>& p, double e);
void Newton(pair<double, double>& p, double e);
void modNewton(pair<double, double>& p, double e);
void secant(pair<double, double>& p, double e);

double function(double x)
{
	return pow(2, -x) - sin(x);
}
double f_deriv(double x)
{
	return -pow(2, -x) * log(2) - cos(x);
}
double s_deriv(double x)
{
	return pow(2, -x) * log(2) * log(2) + sin(x);
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	cout << "��������� ������ ������� ���������� ���������" << endl;
	int  N = 0;
	double a = 0;
	double b = 0;
	double e = 0;
	double h = 0;
	cout << setprecision(18) << "������� �������� A" << endl;
	cin >> a;
	cout << "������ �������� B" << endl;
	cin >> b;
	cout << "������ �������� N" << endl;
	cin >> N;
	cout << "������ �������� e" << endl;
	cin >> e;
	cout << "�������� ���������: [A,B] = [" << a << "," << b << "], f(x) = pow(2,-x)-sin(x), e = " << e << "." << endl;
	h = (b - a) / N;
	double x1 = a;
	double x2 = x1 + h;
	double y2;
	double y1 = function(x1);
	vector < pair <double, double>> v;
	pair<double, double> p;
	while (x2 <= b)
	{
		y2 = function(x2);
		if (y1 * y2 < 0)
		{
			cout << "[a" << v.size() << ",b" << v.size() << "]=[" << x1 << "," << x2 << "]" << endl;
			p.first = x1;
			p.second = x2;
			v.push_back(p);
		}
		x1 += h;
		x2 += h;
		y1 = y2;
	}
	cout << "���������� �������� �������� ����� ����� " << v.size() << endl << endl;

	cout << "��������:" << endl;
	for (int i = 0; i < v.size(); ++i)
	{
		bisection(v[i], e);
	}
	cout << endl << "����� �������:" << endl;
	for (int i = 0; i < v.size(); ++i)
	{
		Newton(v[i], e);
	}
	cout << endl << "���������������� ����� �������:" << endl;
	for (int i = 0; i < v.size(); ++i)
	{
		modNewton(v[i], e);
	}
	cout << endl << "����� �������:" << endl;
	for (int i = 0; i < v.size(); ++i)
	{
		secant(v[i], e);
	}
	return 0;
}


void bisection(pair<double, double>& p, double e)
{
	cout << "��������� �����������: [" << p.first << "," << p.second << "]" << endl;
	double a = p.first;
	double b = p.second;
	double c = 0;
	int i = 0;
	while (b - a > 2 * e)
	{
		c = (a + b) / 2;
		cout << "c = " << c << endl;
		function(a)* function(c) <= 0 ? b = c : a = c;
		++i;
	}
	c = (a + b) / 2;
	cout << "c = " << c << endl;
	cout << "xm = " << c << ",  d = " << (b - a) / 2 << ",  |f(xm)-0| = " << abs(function(c)) << ". ���������� ��������: " << i << endl;
}


//void Newton(pair<double, double>& p, double e)
//{
//	cout << "��������� �����������: [" << p.first << "," << p.second << "]" << endl;
//	double x0 = (p.first + p.second) / 2;
//	if (function(x0) * s_deriv(x0) <= 0)
//	{
//		cout << "�� ��������� ������� 3 �� ������� � ����������." << endl;
//	}
//	else
//	{
//		int i = 1;
//		double x1 = x0 - function(x0) / f_deriv(x0);
//		while (abs(x1 - x0) > 2 * e)
//		{
//			x0 = x1;
//			x1 = x0 - function(x0) / f_deriv(x0);
//			++i;
//			if (i > 1000000)
//			{
//				cout << "���������� �������� ��������� 1000000, ���������� ������������." << endl;
//				break;
//			}
//		}
//		if (i <= 1000000)
//		{
//			double c = (x1 + x0) / 2;
//			cout << "xm = " << c << ",  d = " << abs(x0 - x1) / 2 << ",  |f(xm)-0| = " << abs(function(c)) << ". ���������� ��������: " << i << endl;
//		}
//	}
//}


//void modNewton(pair<double, double>& p, double e)
//{
//	cout << "��������� �����������: [" << p.first << "," << p.second << "]" << endl;
//	double x0 = (p.first + p.second) / 2;
//	if (function(x0) * s_deriv(x0) <= 0)
//	{
//		cout << "�� ��������� ������� 3 �� ������� � ����������." << endl;
//	}
//	else
//	{
//		int i = 1;
//		double a = 1 / f_deriv(x0);
//		double x1 = x0 - function(x0) * a;
//		while (abs(x1 - x0) > 2 * e)
//		{
//
//			x0 = x1;
//			x1 = x0 - function(x0) * a;
//			++i;
//			if (i > 1000000)
//			{
//				cout << "���������� �������� ��������� 1000000, ���������� ������������." << endl;
//				break;
//			}
//		}
//		if (i <= 1000000)
//		{
//			double c = (x1 + x0) / 2;
//			cout << "xm = " << c << ",  d = " << abs(x0 - x1) / 2 << ",  |f(xm)-0| = " << abs(function(c)) << ". ���������� ��������: " << i << endl;
//		}
//	}
//}


void Newton(pair<double, double>& p, double e)
{
	cout << "��������� �����������: [" << p.first << "," << p.second << "]" << endl;
	double x0 = (p.first + p.second) / 2;
	int i = 1;
	double x1 = x0 - function(x0) / f_deriv(x0);
	while (abs(x1 - x0) > 2 * e)
	{
		x0 = x1;
		x1 = x0 - function(x0) / f_deriv(x0);
		++i;
		if (i > 1000000)
		{
			cout << "���������� �������� ��������� 1000000, ���������� ������������." << endl;
			break;
		}
	}
	if (i <= 1000000)
	{
		double c = (x1 + x0) / 2;
		cout << "xm = " << c << ",  d = " << abs(x0 - x1) / 2 << ",  |f(xm)-0| = " << abs(function(c)) << ". ���������� ��������: " << i << endl;
	}
}


void modNewton(pair<double, double>& p, double e)
{
	cout << "��������� �����������: [" << p.first << "," << p.second << "]" << endl;
	double x0 = (p.first + p.second) / 2;
	int i = 1;
	double a = 1 / f_deriv(x0);
	double x1 = x0 - function(x0) * a;
	while (abs(x1 - x0) > 2 * e)
	{

		x0 = x1;
		x1 = x0 - function(x0) * a;
		++i;
		if (i > 1000000)
		{
			cout << "���������� �������� ��������� 1000000, ���������� ������������." << endl;
			break;
		}
	}
	if (i <= 1000000)
	{
		double c = (x1 + x0) / 2;
		cout << "xm = " << c << ",  d = " << abs(x0 - x1) / 2 << ",  |f(xm)-0| = " << abs(function(c)) << ". ���������� ��������: " << i << endl;
	}
}


void secant(pair<double, double>& p, double e)
{
	cout << "��������� �����������: [" << p.first << "," << p.second << "]" << endl;
	double x0 = p.first;
	double x1 = p.second;
	double x2 = x1 - (x1 - x0) * function(x1) / (function(x1) - function(x0));
	int i = 2;
	while (abs(x2 - x1) > e)
	{
		x0 = x1;
		x1 = x2;
		x2 = x1 - (x1 - x0) * function(x1) / (function(x1) - function(x0));
		++i;
	}
	double c = (x2 + x1) / 2;
	cout << "xm = " << c << ",  d = " << abs(x2 - x1) / 2 << ",  |f(xm)-0| = " << abs(function(c)) << ". ���������� ��������: " << i << endl;
}


//void Newton(pair<double, double>& p, double e)
//{
//	cout << "��������� �����������: [" << p.first << "," << p.second << "]" << endl;
//	double x0 = (p.first + p.second) / 2;
//	int k = 0;
//	if (function(x0) * s_deriv(x0) <= 0)
//	{
//		while (function(x0) * s_deriv(x0) <= 0)
//		{
//			x0 = p.first + (rand() % 100) / 100 * (p.second - p.first);
//			++k;
//			if (k > 1000000)
//			{
//				cout << "�� ��������� ������� 3 �� ������� � ���������� ��� ����� ��� �������� �����, ���������� ������������." << endl;
//				break;
//			}
//		}
//	}
//	if (k > 1000000)
//		return;
//	if (k > 0)
//		cout << "����� ��� ������� x0: " << k << endl;
//	int i = 1;
//	double x1 = x0 - function(x0) / f_deriv(x0);
//	while (abs(x1 - x0) > 2 * e)
//	{
//		x0 = x1;
//		x1 = x0 - function(x0) / f_deriv(x0);
//		++i;
//		if (i > 1000000)
//		{
//			cout << "���������� �������� ��������� 1000000, ���������� ������������." << endl;
//			break;
//		}
//	}
//	if (i <= 1000000)
//	{
//		double c = (x1 + x0) / 2;
//		cout << "xm = " << c << ",  d = " << abs(x0 - x1) / 2 << ",  |f(xm)-0| = " << abs(function(c)) << ". ���������� ��������: " << i << endl;
//	}
//}
//
//
//void modNewton(pair<double, double>& p, double e)
//{
//	cout << "��������� �����������: [" << p.first << "," << p.second << "]" << endl;
//	double x0 = (p.first + p.second) / 2;
//	int k = 0;
//	if (function(x0) * s_deriv(x0) <= 0)
//	{
//		while (function(x0) * s_deriv(x0) <= 0)
//		{
//			x0 = p.first + (rand() % 100) / 100 * (p.second - p.first);
//			++k;
//			if (k > 1000000)
//			{
//				cout << "�� ��������� ������� 3 �� ������� � ���������� ��� ����� ��� �������� �����, ���������� ������������." << endl;
//				break;
//			}
//		}
//	}
//	if (k > 1000000)
//		return;
//	if (k > 0)
//		cout << "����� ��� ������� x0: " << k << endl;
//	int i = 1;
//	double a = 1 / f_deriv(x0);
//	double x1 = x0 - function(x0) * a;
//	while (abs(x1 - x0) > 2 * e)
//	{
//		x0 = x1;
//		x1 = x0 - function(x0) * a;
//		++i;
//		if (i > 1000000)
//		{
//			cout << "���������� �������� ��������� 1000000, ���������� ������������." << endl;
//			break;
//		}
//	}
//	if (i <= 1000000)
//	{
//		double c = (x1 + x0) / 2;
//		cout << "xm = " << c << ",  d = " << abs(x0 - x1) / 2 << ",  |f(xm)-0| = " << abs(function(c)) << ". ���������� ��������: " << i << endl;
//	}
//}