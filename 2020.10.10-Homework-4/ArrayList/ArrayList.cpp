#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;


void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ������� ������ �� �����" << endl;
	cout << "2 - �������� �������" << endl;
	cout << "3 - �������� ������� � �������" << endl;
	cout << "4 - ������� ������� �� �������" << endl;
	cout << "5 - ����� �������" << endl;
	cout << "6 - �������� ��������� ���������" << endl;
	cout << "7 - �������� ��������� ���������, ������� � ��������� �������" << endl;
}



void processChoice(ArrayList& a, ArrayList& b, int choice, int element, int index)
{
	switch (choice)
	{
	case 1:
		a.print();
		break;
	case 2:
		cout << "������� �������, ������� ������ �������� � ������" << endl;
		cin >> element;
		cout << a.add(element) << endl;
		break;
	case 3:
		cout << "������� �������, ������� ������ �������� � ������" << endl;
		cin >> element;
		cout << "������� ������, ������� ������ ��������� ���������� ��������" << endl;
		cin >> index;
		cout << a.add(index, element) << endl;
		break;
	case 4:
		cout << "������� ������ ��������, ������� ������ �������" << endl;
		cin >> index;
		cout << a.remove(index) << endl;
		break;
	case 5:
		cout << "������� �������, ������� ������ �����" << endl;
		cin >> element;
		cout << a.indexOf(element) << endl;
		break;
	case 6:
		b.add_M_Elements();
		cout << a.addAll(b) << endl;
		break;
	case 7:
		cout << "������� ������, � �������� ������ ��������� �������� � ������" << endl;
		cin >> index;
		b.add_M_Elements();
		cout << a.addAll(index, b) << endl;
		break;
	}
}



int main()
{
	int element = 0;
	int index = 0;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList a;
	ArrayList b;
	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, b, choice, element, index);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}