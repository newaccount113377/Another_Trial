#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include <clocale>
#include < ctime >
#include < cstdlib >


void printMenu()    //������ ����� ������� ����� ������
{
		setlocale(LC_ALL, "Russian");
		cout << "�������� ��������:" << endl << endl << endl;
		cout << "0 - ����� �� ���������" << endl;
		cout << "1 - �������� ����� � ������" << endl;
		cout << "2 - ������� ������ �� �����" << endl;
		cout << "3 - ����� ����� ������������� �������� �������" << endl;
		cout << "4 - ����� ����������� ������� �������" << endl;
		cout << "5 - ��������� ����� ��������� �������" << endl;
		cout << "6 - ������� ������ � �������� �������" << endl;
}


void expandArray(int* &arr, int &cap)    //�������� ������ ������� � ������, ���� ��� �����������
{
	int newCap = cap * 2;
	int* temp = new int[newCap];
	for (int i = 0; i < cap; ++i)        //������������� �������� ��� ������������ ��������� �������
	{
		temp[i] = arr[i];
	}
	for (int i = cap; i < newCap; ++i)   //���������� ����� ��������� ������� �������� 0, ����� ����� ��������� ������� �� ����������
	{
		temp[i] = 0;
	}
	cap = newCap;
	delete[] arr;
	arr = temp;
}


void maxArray(int*& arr, int& cap)  //���������� ������ ������������ �������� �������(�� ����� ����, ���� ����� ��������� ���������,
{                                   //�� �������� ����� ���������� �� ���. ����� ���� ���������� � �������� ������ ���� ����� ���������,
	int c = 0;                      //��...........
	for (int i = 0; i < cap; ++i)
	{
		for (int j = 0; j < cap-1; ++j)
		{
			if ((j != i)&(arr[i]<arr[j]))
			{
				break;
			}
			else
			{
				c=i;
			}
		}
	}
	cout<<"����� ������������� ��������="<<c<<endl;
}


void minArray(int*& arr, int& cap)  //��� �� �� �����, ������ ����� ������������ �����.
{
	int c = 0;
	for (int i = 0; i < cap; ++i)
	{
		for (int j = 0; j < cap - 1; ++j)
		{
			if ((j != i) & (arr[i] > arr[j]))
			{
				break;
			}
			else
			{
				c = i;
			}
		}
	}
	cout << "����� ������������ ��������=" << c << endl;
}


int main(int argc, char* argv[])
{
	int n = 0;     //����� �������� �������, ������� ����� ��������
	int m = 0;     //�����, �� ������� �������� ������� �������
	char g = 'g';  //���������� ��� ���������� ����� � ����������
	int s = 0;     //����� ��������� �������
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int cap = 20;
	int* a = new int[cap];
	for (int i = 0; i < cap; ++i)   //���������� ���� ��������� ������� ��������� �������� �� 0 �� 100, ����� ��� ��� ������������� ���������� �����
	{                               //������-�� ��������� ����� 842150451.
		a[i] = rand() % 101;        //��� ������ ������� ���������� ���������� "���������" �����, � �� ����, ��� ��� ���������.......
	}        
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			while (g == 'g')  //��������, ���������� �� �������� ������ �������� ��������� �������
			{
				cout << "������� ����� �������� �������, ������� ������ ��������" << endl;
				cin >> n;
				while (n >= cap)
				{
					expandArray(a, cap);
				}
				cout << "������� �����" << endl;
				cin >> m;
				a[n] = m;
				cout << "a[" << n << "]=" << a[n] << endl;
				cout << "���� ������ ����������, ������� \"g\"" << endl;
				cout << "���� ������ ��������� � ������� ����, ������� \"e\"" << endl;
				g = _getch();
			}
			break;
		case 2:
			for (int i = 0; i < cap; ++i)  //����� ��������� �������
			{
				cout << "a[" << i << "]=" << a[i] << " ";
			}
			cout << endl;
			break;
		case 3:
			maxArray(a, cap);
			break;
		case 4:
			minArray(a, cap);
			break;
		case 5:
			for (int i = 0; i < cap; ++i)  //������� ����� ��������� �������
			{
				s = a[i] + s;
			}
			cout << "����� ��������� �������=" << s << endl;
			s = 0;
			break;
		case 6:
			for (int i = cap - 1; i >= 0; --i)  //����� � �������� �������
			{
				cout << "a[" << i << "]=" << a[i] << " ";
			}
			cout << endl;
			break;
		}
		cout << "��� ����������� ������� ����� �������";  //�������, ����� ����� �� �������� ����� ����� ���������� ������������� ������
		_getch();                                         //� ���� ����������� ��������� ���, ��� ������ ���������.
	}
	delete[] a;
	return EXIT_SUCCESS;
}