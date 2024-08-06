#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
using namespace std;


void printMenu(){														//����� ���� �� �����
	setlocale(LC_ALL, "Russian");
	cout << "�������� ��������:" << endl << endl << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - �������� ����� � ������" << endl;
	cout << "2 - ������� ������ �� �����" << endl;
	cout << "3 - ����� ����� ������������� �������� �������" << endl;
	cout << "4 - ����� ����� ������������ �������� �������" << endl;
	cout << "5 - ��������� ����� ��������� �������" << endl;
	cout << "6 - ������� ������ � �������� �������" << endl;
}

void printArray(int*& arr, int& capacity){								//����� ��������� ������� �� �������� �� capacity-1
	if (capacity >= 0)													//���� capacity < 0, ������ ����� ���������� � �������� �������
		for (int i = 0; i < capacity; ++i)
			cout << "a[" << i << "]=" << arr[i] << endl;
	else
		for (int i = 1; i <= abs(capacity); ++i)
			cout << "a[" << abs(capacity) - i << "]=" << arr[abs(capacity) - i] << endl;
}

void expandArray(int*& arr, int& capacity){								//�������, ����������� ����� ������� ����� ������������� ������ ������� � 
	int newcapacity = capacity * 2;										//����������� ������ � ������������� � ���� ��������� �� ����������� �������
	int* temp = new int[newcapacity] {0};
	for (int i = 0; i < capacity; ++i)
		temp[i] = arr[i];

	capacity = newcapacity;
	delete[] arr;
	arr = temp;
}

int sumArray(int*& arr, int& capacity){									//������� ����� ��������� �������
	int s = 0;
	for (int i = 0; i < capacity; ++i)
		s = arr[i] + s;

	return s;
}

int minArray(int*& arr, int& capacity){									//���������� ������������ �������� � �������
	int c = 0;															//���� ����� ��������� ���������, �������� ����� ���������� �� ���
	for (int i = 0; i < capacity; ++i)
		c = (arr[c] >= arr[i] ? i : c);

	return c;
}

int maxArray(int*& arr, int& capacity){									//���������� ������������ �������� � �������
	int c = 0;															//���� ����� ��������� ���������, �������� ����� ���������� �� ���
	int a = 0;									
	for (int i = 0; i < capacity; ++i)										
		c = (arr[c] <= arr[i] ? i : c);

	return c;
}

void swit(int choice, int*& arr, int& capacity){						//�������, � ������� ������� ������������ ����� �������� �����, ������������ � ����
	int n = 0;
	int m = 0;
	char g = 'g';
	switch (choice)
	{
	case 1:
		while (g == 'g')												//��������, ���������� �� �������� ������ �������� ��������� �������
		{																//����� �������, ����� ��������������� �������� ��� �������� ��������� ��������� � ������, �� ����������� � ����
			cout << "������� ����� �������� �������, ������� ������ ��������" << endl;
			cin >> n;
			while (n >= capacity)
				expandArray(arr, capacity);

			cout << "������� �����" << endl;
			cin >> m;
			arr[n] = m;
			cout << "a[" << n << "]=" << arr[n] << endl;
			cout << "���� ������ ����������, ������� \"g\"" << endl;
			cout << "���� ������ ��������� � ������� ����, ������� \"e\"" << endl;
			g = _getch();
		}
		g = 'g';
		break;
	case 2:
		printArray(arr, capacity);
		break;
	case 3:
		n = maxArray(arr, capacity);
		cout << "����� ������������� ��������=" << n << ", a[" << n << "]=" << arr[n] << endl;
		break;
	case 4:
		n = minArray(arr, capacity);
		cout << "����� ������������ ��������=" << n << ", a[" << n << "]=" << arr[n] << endl;
		break;
	case 5:
		n = sumArray(arr, capacity);
		cout << "����� ��������� �������=" << n << endl;
		n = 0;
		break;
	case 6:
		capacity = -capacity;
		printArray(arr, capacity);
		capacity = -capacity;
		break;
	}
	cout << "��� ����������� ������� ����� �������";					//�������, ����� ����� �� �������� ����� ����� ���������� ������������� ������
	system("pause");
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int capacity = 20;
	int* a = new int[capacity];
	for (int i = 0; i < capacity; ++i)
		a[i] = rand() % 101;

	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cin >> choice;
		swit(choice, a, capacity);
	}
	delete[] a;
	return EXIT_SUCCESS;
}
