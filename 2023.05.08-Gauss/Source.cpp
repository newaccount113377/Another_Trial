#define _USE_MATH_DEFINES
#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<armadillo>

using namespace std;
using namespace arma;

vector<double> rand_coeff;
vector<vector<double>> coeff_Gauss;
vector<vector<double>> nodes_Legendre;
double e = 0.000000000001;
int m = 10000;


void coeff_shift(vector<vector<double>>& coeff, vector<vector<double>>& nodes, double a, double b);
vector<double> coefficients_Gauss(vector<double> nodes);
double Legendre(double x, vec coeff, int k);
vector<double> find_roots(double a, double b, double(*f)(double, vec, int), vec coeff, int k, int t);
double w_poly_integral(double a, double b, int k);
double secant(pair<double, double>& p, double(*f)(double, vec, int), vec coeff, int k);
double Simpson(double a, double b, double(*f)(double, int), int k);
double weight(double x)
{
	return sqrt(sqrt(x));
}
double moment(double x, int k)
{
	double result = weight(x);
	for (int i = 0; i < k; ++i)
		result *= x;
	return result;
}
double func(double x, int k)
{
	return sin(x);
	//return 1 / sqrt((1 + x * x) * (4 + 3 * x * x));
}
double func_M(double x, int k)
{
	return exp(2 * x);
}
double w_func(double x, int k)
{
	return weight(x) * func(x, k);
}
double interp(double(*f)(double, int), vec coeff, int k, vector<double> nodes)
{
	double result = 0;
	for (int i = 0; i < coeff.n_rows; ++i)
		result += coeff(i) * f(nodes[i], k);
	return result;
}
double polynomial(double x, int k);
double w_func_Mehler(double x, int k)
{
	return func_M(x, k) / sqrt(1 - x * x);
}
double w_polynomial(double x, int k)
{
	return weight(x) * polynomial(x, k);
}
double nast(double x, vec coeff, int k)
{
	double result = coeff(0);
	double c = x;
	for (int i = 1; i < coeff.n_rows; ++i)
	{
		result += coeff(i) * c;
		c *= x;
	}
	return result + c;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	cout << "������� 5.1:" << endl;
	cout << setprecision(13) << "����������� ���������� ���������� ��� ������ ������������ ������ ��������� �������������� ������� ��������(����)" << endl;
	double a, b;
	int N;
	cout << "������� ����� ����� ���������� �������������� a" << endl;
	cin >> a;
	cout << "������� ������ ����� ���������� �������������� b" << endl;
	cin >> b;
	double integral = Simpson(a, b, w_func, 0);
	cout << "������ �������� ���������: " << integral << endl;
	cout << "������� ���������� ����� N" << endl;
	cin >> N;

	vec moments(2 * N);
	cout << "������� ������� �������:" << endl;
	for (int i = 0; i < 2 * N; ++i)
	{
		moments(i) = Simpson(a, b, moment, i);
		cout << "mu" << i << " = " << moments(i) << endl;
	}

	cout << "���������������� ������������ �������(���):" << endl;
	double c;
	vector<double> nodes_IKF;
	for (int i = 0; i < N; ++i)
	{
		cout << "������� ���� ��� x" << i << endl;
		cin >> c;
		nodes_IKF.push_back(c);
	}

	mat A = ones(N, N);
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			A(i, j) = A(i - 1, j) * nodes_IKF[j];
	}
	vec B = moments.rows(0, N - 1);
	vec coeff = solve(A, B);
	cout << "������������ ���:" << endl;
	for (int i = 0; i < N; ++i)
		cout << "A" << i << " = " << coeff(i) << endl;

	double result1 = interp(func, coeff, 0, nodes_IKF);
	cout << "������������ �������� ���������: " << result1 << ", ���������� ����������� ��������: " << abs(integral - result1) << endl;

	for (int i = 0; i <= 2 * N; ++i)
	{
		while (c == 0)
			c = (rand() % 1000) / 100;
		rand_coeff.push_back(c);
	}
	double result2 = interp(polynomial, coeff, N - 1, nodes_IKF);
	cout << "�������� �� ������� �������� ������� N-1:" << endl;
	cout << "������������ �������� ���������: " << result2 << ", ���������� ����������� ��������: " << abs(Simpson(a, b, w_polynomial, N - 1) - result2) << endl;

	cout << endl << "������������ ������� ����:" << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			A(i, j) = moments(j + i);
	}
	B = -moments.rows(N, 2 * N - 1);
	coeff = solve(A, B);
	cout << "������������ �������������� ����������:" << endl;
	for (int i = 0; i < N; ++i)
		cout << "a" << i << " = " << coeff(i) << endl;

	vector<double> nodes_nast = find_roots(a, b, nast, coeff, 0, 1);
	A = ones(N, N);
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			A(i, j) = A(i - 1, j) * nodes_nast[j];
	}
	B = moments.rows(0, N - 1);
	coeff = solve(A, B);
	cout << "������������ �� ����:" << endl;
	for (int i = 0; i < N; ++i)
		cout << "A" << i << " = " << coeff(i) << endl;

	double result3 = interp(func, coeff, 0, nodes_nast);
	cout << "������������ �������� ���������: " << result3 << ", ���������� ����������� ��������: " << abs(integral - result3) << endl;
	double result4 = interp(polynomial, coeff, 2 * N - 1, nodes_nast);
	cout << "�������� �� ������� �������� ������� 2N-1:" << endl;
	cout << "������������ �������� ���������: " << result4 << ", ���������� ����������� ��������: " << abs(Simpson(a, b, w_polynomial, 2 * N - 1) - result4) << endl;

	//-----------------------------------------------------------------------------------------------------
	//������� 5.2
	cout << endl << endl << "������� 5.2:" << endl;
	cout << "�� ������, �� ���� � ������������. ���������� ���������� ��� ������ �� ������" << endl;
	cout << "������� ������������ �������� N, �� �������� ������������ ������������ ������� ������" << endl;
	cin >> N;

	vector<vector<double>> nodes_Legendre2;
	vector<vector<double>> coeff_Gauss2;
	cout << "���� � ������������ �� ������:" << endl;
	for (int i = 0; i < N; ++i)
	{
		nodes_Legendre.push_back(find_roots(-1, 1, Legendre, coeff, i + 1, 0));
		coeff_Gauss.push_back(coefficients_Gauss(nodes_Legendre[i]));
		cout << "N = " << i + 1 << endl;
		for (int j = 0; j < nodes_Legendre[i].size(); ++j)
			cout << j << "	����: " << nodes_Legendre[i][j] << ". �����������: " << coeff_Gauss[i][j] << endl;
	}

	int N1;
	cout << endl << "������� N, ��� �������� ����������� �������� �������� �� ������ �� ����������� ������� 0..2N-1" << endl;
	cin >> N1;
	rand_coeff.clear();
	for (int i = 0; i < 2 * N; ++i)
	{
		while (c == 0)
			c = (rand() % 1000) / 100;
		rand_coeff.push_back(c);
	}
	double result_i;
	coeff = vec(coeff_Gauss[N1 - 1]);
	for (int i = 0; i <= 2 * N1 - 1; ++i)
	{
		result_i = interp(polynomial, coeff, i, nodes_Legendre[N1 - 1]);
		cout << i << " �������:		������������ �������� ���������: " << result_i;
		cout << ", ���������� ����������� ��������: " << abs(Simpson(-1, 1, polynomial, i) - result_i) << " " << endl;
	}

	cout << endl << "���������� ��������� ������� f(x) �� a �� b:" << endl;
	for (int i = 0; i < N; ++i)
	{
		nodes_Legendre2.push_back(nodes_Legendre[i]);
		coeff_Gauss2.push_back(coeff_Gauss[i]);
	}
	coeff_shift(coeff_Gauss2, nodes_Legendre2, a, b);
	for (int i = 0; i < N; ++i)
	{
		result_i = interp(w_func, vec(coeff_Gauss2[i]), 0, nodes_Legendre2[i]);
		cout << "N = " << i + 1 << ":	������������ �������� ���������: " << result_i << ", ���������� ����������� ��������: " << abs(integral - result_i) << " " << endl;
	}

	double t;
	cout << endl << "���� ������ ���������� ������ ���������� ��������������, ������� 1" << endl;
	cout << "� ��������� ������, ������� 0" << endl;
	cin >> t;
	double integral2;
	while (t == 1)
	{
		cout << "������� ����� ����� ���������� �������������� a" << endl;
		cin >> a;
		cout << "������� ������ ����� ���������� �������������� b" << endl;
		cin >> b;
		coeff_shift(coeff_Gauss2, nodes_Legendre2, a, b);
		integral2 = Simpson(a, b, w_func, 0);
		for (int i = 0; i < N; ++i)
		{
			result_i = interp(w_func, vec(coeff_Gauss2[i]), 0, nodes_Legendre2[i]);
			cout << i << " �������:	������������ �������� ���������: " << result_i << ", ���������� ����������� ��������: " << abs(integral2 - result_i) << " " << endl;
		}
		cout << endl << "���� ������ ���������� ������ ���������� ��������������, ������� 1" << endl;
		cout << "� ��������� ������, ������� 0" << endl;
		cin >> t;
	}

	cout << "�� ������, �� ���� � ������������. ���������� ���������� ��� ������ �� ������" << endl;
	//double integral_M = Simpson(-1 + e / 10000, 1 - e / 10000, w_func_Mehler, 0);
	double integral_M = 7.1615284390503;
	cout << "������ �������� ���������: " << integral_M << endl;
	vector<double> nodes_Mehler1;
	vector<double> nodes_Mehler2;
	vector<double> nodes_Mehler3;
	vector<double> coeff_Mehler1;
	vector<double> coeff_Mehler2;
	vector<double> coeff_Mehler3;

	t = 1;
	while (t == 1)
	{
		cout << "������� ���������� ����� N1" << endl;
		cin >> N1;
		cout << "������� ���������� ����� N2" << endl;
		int N2;
		cin >> N2;
		cout << "������� ���������� ����� N3" << endl;
		int N3;
		cin >> N3;

		for (int i = 0; i < N1; ++i)
		{
			nodes_Mehler1.push_back(cos((2 * i - 1) * M_PI / (2 * N1)));
			coeff_Mehler1.push_back(M_PI / N1);
		}
		for (int i = 0; i < N2; ++i)
		{
			nodes_Mehler2.push_back(cos((2 * i - 1) * M_PI / (2 * N2)));
			coeff_Mehler2.push_back(M_PI / N2);
		}
		for (int i = 0; i < N3; ++i)
		{
			nodes_Mehler3.push_back(cos((2 * i - 1) * M_PI / (2 * N3)));
			coeff_Mehler3.push_back(M_PI / N3);
		}

		cout << endl << "���� � ������������ �� ������ ��� N1:" << endl;
		for (int j = 0; j < N1; ++j)
			cout << j << "	����: " << nodes_Mehler1[j] << ". �����������: " << coeff_Mehler1[j] << endl;
		double result_M1 = interp(func_M, vec(coeff_Mehler1), 0, nodes_Mehler1);
		double c1 = abs(result_M1 - integral_M);
		cout << "������������ �������� ���������: " << result_M1 << ", ���������� ����������� ��������: " << c1 << endl;

		cout << endl << endl << "���� � ������������ �� ������ ��� N2:" << endl;
		for (int j = 0; j < N2; ++j)
			cout << j << "	����: " << nodes_Mehler2[j] << ". �����������: " << coeff_Mehler2[j] << endl;
		double result_M2 = interp(func_M, vec(coeff_Mehler2), 0, nodes_Mehler2);
		double c2 = abs(result_M2 - integral_M);
		cout << "������������ �������� ���������: " << result_M2 << ", ���������� ����������� ��������: " << c2 << endl;

		cout << endl << endl << "���� � ������������ �� ������ ��� N3:" << endl;
		for (int j = 0; j < N3; ++j)
			cout << j << "	����: " << nodes_Mehler3[j] << ". �����������: " << coeff_Mehler3[j] << endl;
		double result_M3 = interp(func_M, vec(coeff_Mehler3), 0, nodes_Mehler3);
		double c3 = abs(result_M3 - integral_M);
		cout << "������������ �������� ���������: " << result_M3 << ", ���������� ����������� ��������: " << c3 << endl;

		cout << endl;
		if (c1 <= c2 && c2 <= c3)
			cout << "�������� ��� N1 ������, ��� ��� N2, ������� ������ �������� ��� N3" << endl;
		if (c1 <= c3 && c3 <= c2)
			cout << "�������� ��� N1 ������, ��� ��� N3, ������� ������ �������� ��� N2" << endl;
		if (c2 <= c1 && c1 <= c3)
			cout << "�������� ��� N2 ������, ��� ��� N1, ������� ������ �������� ��� N3" << endl;
		if (c2 <= c3 && c3 <= c1)
			cout << "�������� ��� N2 ������, ��� ��� N3, ������� ������ �������� ��� N1" << endl;
		if (c3 <= c2 && c2 <= c1)
			cout << "�������� ��� N3 ������, ��� ��� N2, ������� ������ �������� ��� N1" << endl;
		if (c3 <= c1 && c1 <= c2)
			cout << "�������� ��� N3 ������, ��� ��� N1, ������� ������ �������� ��� N2" << endl;

		cout << endl << "���� ������ ���������� ������ �������� N1, N2 � N3, ������� 1" << endl;
		cout << "� ��������� ������, ������� 0" << endl;
		cin >> t;
		nodes_Mehler1.clear();
		nodes_Mehler2.clear();
		nodes_Mehler3.clear();
		coeff_Mehler1.clear();
		coeff_Mehler2.clear();
		coeff_Mehler3.clear();
	}
	//-----------------------------------------------------------------------------------------------------
	//������� 5.3
	cout << "������� 5.3" << endl;
	cout << "����������� ���������� ��������� ��� ������ ��������� �� ������" << endl;
	t = 1;
	double m1, h;
	vector<double> nodes_Legendre3, coeff_Gauss3;
	double result_G;
	while (t == 1)
	{
		cout << "������� ����� ����� ���������� �������������� a" << endl;
		cin >> a;
		cout << "������� ������ ����� ���������� �������������� b" << endl;
		cin >> b;
		cout << "������� ���������� ����� N �� 1 �� " << N << endl;
		cin >> N1;
		for (int j = 0; j < nodes_Legendre[N1 - 1].size(); ++j)
			cout << j << "	����: " << nodes_Legendre[N1 - 1][j] << ". �����������: " << coeff_Gauss[N1 - 1][j] << endl;
		cout << "������� ���������� ����������� ������� m" << endl;
		cin >> m1;
		h = (b - a) / m1;
		integral2 = Simpson(a, b, func, 0);

		result_G = 0;
		c = 0;
		for (int i = 0; i < N1; ++i)
		{
			for (int j = 0; j < m1; ++j)
				c += func(a + h * (nodes_Legendre[N1 - 1][i] + 2 * j + 1) / 2, 0);
			result_G += c * coeff_Gauss[N1 - 1][i];
			c = 0;
		}
		result_G *= h / 2;
		cout << "������������ �������� ���������: " << result_G << ", ���������� ����������� ��������: " << abs(result_G - integral2) << endl;

		cout << "����� �������� ��������� ������, ������� 1" << endl;
		cout << "� ��������� ������, ������� 0" << endl;
		cin >> t;
	}
	return 0;
}


double Simpson(double a, double b, double(*f)(double, int), int k)
{
	double W = 0;
	double h = (b - a) / m;
	double c = a;
	for (int j = 1; j < m; ++j)
	{
		c += h;
		W += f(c, k);
	}

	double Q = 0;
	c = a + h / 2;
	for (int j = 0; j < m; ++j)
	{
		Q += f(c, k);
		c += h;
	}
	return (b - a) * (f(a, k) + f(b, k) + 2 * W + 4 * Q) / 6 / m;
}

double w_poly_integral(double a, double b, int k)
{
	double result = 0;
	double a1 = a * 2 * sqrt(a) / 3;
	double b1 = b * 2 * sqrt(b) / 3;
	for (int i = 0; i <= k; ++i)
	{
		result += rand_coeff[i] * (b1 - a1);
		b1 = b * b1 * (2 * i + 3) / (2 * i + 5);
		a1 = a * a1 * (2 * i + 3) / (2 * i + 5);
	}
	return result;
}

double secant(pair<double, double>& p, double(*f)(double, vec, int), vec coeff, int k)
{
	double x0 = p.first;
	double x1 = p.second;
	double g = f(x1, coeff, k);
	double x2 = x1 - (x1 - x0) * g / (g - f(x0, coeff, k));
	int i = 2;
	while (abs(x2 - x1) > e)
	{
		x0 = x1;
		x1 = x2;
		g = f(x1, coeff, k);
		x2 = x1 - (x1 - x0) * g / (g - f(x0, coeff, k));
		++i;
	}
	return (x2 + x1) / 2;
}

double Legendre(double x, vec coeff, int k)
{
	if (k == 0)
		return 1;
	else if (k == 1)
		return x;
	return ((2 * k - 1) * x * Legendre(x, coeff, k - 1) - (k - 1) * Legendre(x, coeff, k - 2)) / k;
}

vector<double> find_roots(double a, double b, double(*f)(double, vec, int), vec coeff, int k, int t)
{
	vector<double> nodes;
	double h = (b - a) / m;
	double x1 = a;
	double x2 = x1 + h;
	double y2;
	double y1 = f(x1, coeff, k);

	vector < pair <double, double>> v;
	pair<double, double> p;
	while (x2 <= b)
	{
		y2 = f(x2, coeff, k);
		if (y1 * y2 < 0)
		{
			p.first = x1;
			p.second = x2;
			v.push_back(p);
		}
		x1 += h;
		x2 += h;
		y1 = y2;
	}
	if (t == 1)
		cout << "���� ����������(������� " << v.size() << " �������������� �����):" << endl;
	for (int i = 0; i < v.size(); ++i)
	{
		nodes.push_back(secant(v[i], f, coeff, k));
		if (t == 1)
			cout << "a" << i << " = " << nodes[i] << endl;
	}
	return nodes;
}

vector<double> coefficients_Gauss(vector<double> nodes)
{
	vector<double> result;
	int N = nodes.size();
	vec coeff;
	double P;
	for (int i = 0; i < N; ++i)
	{
		P = Legendre(nodes[i], coeff, N - 1);
		result.push_back(2 * (1 - nodes[i] * nodes[i]) / (N * N * P * P));
	}
	return result;
}

void coeff_shift(vector<vector<double>>& coeff, vector<vector<double>>& nodes, double a, double b)
{
	for (int i = 0; i < coeff.size(); ++i)
	{
		for (int j = 0; j < coeff[i].size(); ++j)
		{
			coeff[i][j] = coeff_Gauss[i][j] * (b - a) / 2;
			nodes[i][j] = nodes_Legendre[i][j] * (b - a) / 2 + (b + a) / 2;
		}
	}
}

double polynomial(double x, int k)
{
	double result = rand_coeff[0];
	double c = x;
	for (int i = 1; i <= k; ++i)
	{
		result += rand_coeff[i] * c;
		c *= x;
	}
	return result;
}

