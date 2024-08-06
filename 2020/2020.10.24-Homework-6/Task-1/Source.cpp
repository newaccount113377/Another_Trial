#include <iostream>
#include <ctime>
#include "ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - �������� � ������ �������, ��������� � ����������" << endl;
	cout << "2 - ������� ������" << endl;
	cout << "3 - ���������, �������� �� ������ ������������" << endl;
	cout << "4 - ����������� �������� ������ �� n ���������. n>0 - ����� ������, n<0 - ����� �����" << endl;
	cout << "5 - ���������, ����� �� ������ ����� ������������, ���� �� ���� ������� ���� �������" << endl;
}


void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		int element = 0;
		cout << "������� �������, ������� ������ �������� � ������" << endl;
		cin >> element;
		a.add(element);
		break;
	}
	case 2:
	{
		cout << a.toString() << endl;
		break;
	}
	case 3:
	{
		int c = 0;
		for (int i = 0; i < a.length() / 2 + 1; ++i)
		{
			if (a.get(i) != a.get(a.length() - 1 - i))
			{
				c += 1;
				break;
			}
		}
		if (c == 0)
		{
			cout << "������ �������� ������������" << endl;
		}
		else
		{
			cout << "������ �� �������� ������������" << endl;
		}
		break;
	}
	case 4:
	{
		int n = 0;
		cout << "������� n" << endl;
		cin >> n;
		n = n % a.length();
		ArrayList b(a);
		if (n >= 0)
		{
			for (int i = 0; i < a.length(); ++i)
			{
				a.set(i, b.get((i + n) % a.length()));
			}
		}
		else
		{
			for (int i = 0; i < -n; ++i)
			{
				a.set(i, b.get(a.length() + n + i));
			}
			for (int i = -n; i < a.length(); ++i)
			{
				a.set(i, b.get(i + n));
			}
		}
		break;
	}
	case 5:
	{
		int c = 0;
		int d = 0;
		int f = 0;
		ArrayList b(a);
		for (int i = 0; i < a.length() / 2 + 1; ++i)
		{
			if (a.get(i) != a.get(a.length() - 1 - i))
			{
				c = 1;
				d = b.get(i);
				f = i;
			}
		}
		if (c == 0)
		{
			cout << "������ �������� ������������" << endl;
		}
		else
		{
			b.remove(f);
			for (int i = 0; i < b.length() / 2 + 1; ++i)
			{
				if (b.get(i) != b.get(a.length() - 1 - i))
				{
					c = 2;
					break;
				}
			}
			if (c == 1)
			{
				cout << "������ ������ ������������, ���� ������ ������� � �������� " << f << endl;
			}
			else
			{
				b.add(f, d);
				f = b.length() - 1 - f;
				b.remove(f);
				for (int i = 0; i < b.length() / 2 + 1; ++i)
				{
					if (b.get(i) != b.get(a.length() - 1 - i))
					{
						c = 3;
						break;
					}
				}
				if (c == 3)
				{
					cout<< "������ ������ ������������, ���� ������ ������� � �������� " << f << endl;
				}
				else
				{
					cout << "������ �� ����� ����� ������������, ���� ������� �� ���� 1 �������" << endl;
				}
			}
		}
		break;
	}
	}
}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList a;
	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}