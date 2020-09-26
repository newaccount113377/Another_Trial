#include <iostream>
using namespace std;
#include <clocale>
#include < ctime >
#include < cstdlib >
#include<conio.h>
#define _CRT_SECURE_NO_WARNINGS


void printMenu()    //������ ����� ������� ����� ������
{
	setlocale(LC_ALL, "Russian");
	cout << "�������� ��������:" << endl << endl << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - �������� � ������ n ��������� ����� � ���������� �� a �� b " << endl;
	cout << "2 - ���������� ������" << endl;
	cout << "3 - �������� �������� ������� ������� � �����." << endl;
	cout << "4 - ����������� ����� ������ �� 1" << endl;
	cout << "5 - ���������� ��� ��������� �������. n - ������ ��������, ������������ ���������." << endl;
	cout << "6 - ������� ������ �� �����" << endl;
}


void addArray(int*& arr, int& cap, int n, int a, int b)
{
	int newCap = cap + n;
	int* temp = new int[newCap] {0};
	for (int i = 0; i < cap; ++i)        //������������� �������� ��� ������������ ��������� �������
	{
		temp[i] = arr[i];
	}
	for (int i = cap; i < newCap; ++i)
	{
		temp[i] = a + rand() % (b - a + 1);
		cout << "a[" << i << "]=" << temp[i] << endl;
	}
	cap = newCap;
	delete[] arr;
	arr = temp;
}


void expandArray(int*& arr, int& cap, int n)    //�������� ������ ������� � ������, ���� ��� �����������
{
	int newCap = n + 1;
	int* temp = new int[newCap] {0};
	for (int i = 0; i < cap; ++i)        //������������� �������� ��� ������������ ��������� �������
	{
		temp[i] = arr[i];
	}
	cap = newCap;
	delete[] arr;
	arr = temp;
}


void printArray(int*& arr, int& cap)
{
	for (int i = 0; i < cap; ++i)
	{
		cout << "a[" << i << "]=" << arr[i] << endl;
	}
}


void reverseArray(int*& arr, int& cap)
{
	int a = 0;
	for (int i = 0; i < cap / 2; ++i)
	{
		a = arr[i];
		arr[i] = arr[cap - 1 - i];
		arr[cap - 1 - i] = a;
	}
	printArray(arr, cap);
}


void switchArray(int*& arr, int& cap)
{
	int a = 0;
	if (cap % 2 == 0)
	{
		for (int i = 0; i < cap; i += 2)
		{
			a = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = a;
		}
	}
	else
	{
		for (int i = 0; i < cap - 1; i += 2)
		{
			a = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = a;
		}
		cout << "cap-��������, ������� a[cap-1] �������� �� ����� �����." << endl;
	}
	printArray(arr, cap);
}


void moveArray(int*& arr, int& cap)
{
	int a = arr[0];
	int b = 0;
	int c = arr[cap-1];
	for (int i = 1; i < cap; ++i)
	{
		arr[0] = arr[cap - 1];
		b = arr[i];
		arr[i] = a;
		a = b;
	}
	printArray(arr, cap);
}


void separateArray(int*& arr, int& cap, int n)
{
	int a = 0;
	if ((n == 0)or(n==cap-1))
	{
		reverseArray(arr, cap);
	}
	else if (n < cap-1)
	{
		reverseArray(arr, n);
		for (int i = n; i < (cap + n) / 2; ++i)
		{
			a = arr[i];
			arr[i] = arr[cap + n - 1 - i];
			arr[cap + n - 1 - i] = a;
			cout << "a[" << i << "]=" << arr[i] << endl;
		}
		for (int i = (cap + n) / 2; i < cap; ++i)
		{
			cout << "a[" << i << "]=" << arr[i] << endl;
		}
	}
	else
	{
		--n;
		expandArray(arr, cap, n);
		++n;
		reverseArray(arr, n);
	}
}


void swit(int choice, int*& a, int& cap)
{
	int n = 0;
	int c = 0;
	int b = 0;
	switch (choice)
	{
	case 1:
		cout << "������� n" << endl;
		cin >> n;
		cout << "������� a" << endl;
		cin >> c;
		cout << "������� b" << endl;
		cin >> b;
		addArray(a, cap, n, c, b);
		break;
	case 2:
		reverseArray(a, cap);
		break;
	case 3:
		switchArray(a, cap);
		break;
	case 4:
		moveArray(a, cap);
		break;
	case 5:
		cout << "������� n" << endl;
		cin >> n;
		separateArray(a, cap, n);
		break;
	case 6:
		printArray(a, cap);
		break;
	}                                     
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int cap = 8;
	int* a = new int[cap];
	for (int i = 0; i < cap; ++i)   //���������� ���� ��������� ������� ��������� �������� �� 0 �� 100, ����� ��� ��� ������������� ���������� �����
	{                               //������-�� ��������� ����� 842150451.
		a[i] = rand() % 101;
	}
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cin >> choice;
		swit(choice, a, cap);
		cout << "��� ����������� ������� ����� �������";  //�������, ����� ����� �� �������� ����� ����� ���������� ������������� ������
		_getch();                                         //� ���� ����������� ��������� ���, ��� ������ ���������.
	}
	delete[] a;
	return EXIT_SUCCESS;
}