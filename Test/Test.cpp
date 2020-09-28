//#include<iostream>
//#include<clocale>
//using namespace std;
//
//
//
//void expandArray(int*& arr, int& capacity)
//{
//	int newCapacity = capacity * 2;
//
//
//	int* temp = new int[newCapacity];
//	for (int i = 0; i < capacity; ++i)
//	{
//		temp[i] = arr[i];
//	}
//
//
//	capacity = newCapacity;
//	delete[] arr;
//	arr = temp;
//
//
//}
//
//void printMenu()
//{
//	setlocale(LC_ALL, "Russian");
//	cout << "0. ����� �� ���������" << endl;
//	cout << "1. �������� ����� � ������" << endl;
//	cout << "2. ������� ������ �� �����" << endl;
//	cout << "3. ����� ������������ ������� �������" << endl;
//	cout << "4. ����� ����������� ������� �������" << endl;
//	cout << "5. ��������� ����� ��������� �������" << endl;
//	cout << "6. ������� ������ � �������� �������" << endl;
//}
//
//int main()
//{
//	int x = 0;
//	int capArray = 10;
//	int count = 0;
//	int* Array = new int[capArray] {0};
//	int choice = -1;
//	while (choice != 0)
//	{
//		system("cls");
//		printMenu();
//		cout << ">>";
//		cin >> choice;
//		while (choice < 0 || choice > 6)
//		{
//			cout << "������ �����"<< endl;
//			cout << "������� ��������, ������� ������������ ����" << endl;
//			cout << "<<";
//			cin >> choice;
//		}
//		switch (choice)
//		{
//		case 0:
//			cout << "������ � ���������� ���������";
//			break;
//		case 1:
//			if (count == capArray)
//			{
//				expandArray(Array, capArray);
//			}
//			cout << "�������� ����� � ������" << endl;
//			cout << ">>";
//			cin >> x;
//			Array[count] = x;
//			count++;
//			break;
//		case 2:
//			cout << "[" << count << "/" << capArray << "]" << "{";
//			for (int i = 0; i < count; i++)
//			{
//				cout << Array[i];
//				if (i != (count - 1))
//				{
//					cout << ", ";
//				}
//			}
//			cout << "}" << endl;
//			break;
//		case 3:
//			int max = Array[0];
//			int counter = 0;
//			for (int i = 1; i < count; i++)
//			{
//
//				if (Array[i] > max)
//				{
//					max = Array[i];
//					counter = i;
//				}
//			}
//
//			cout << "������� �"<< counter << "=" << max << "- ������������ � �������" << endl;
//			break;
//		case 4:
//			int min = Array[0];
//			int counter = 0;
//			for (int i = 1; i < count; i++)
//			{
//
//				if (Array[i] < min)
//				{
//					min = Array[i];
//					counter = i;
//				}
//			}
//			cout << "������� �"<< counter << "=" << max << "- ����������� � �������" << endl;
//			break;
//		case 5:
//			int sum = 0;
//			for (int i = 0; i < count; i++)
//			{
//				sum += Array[i];
//			}
//			cout << "����� ��������� ������� = ";
//			cout << sum << endl;
//
//			break;
//		case 6:
//			cout << "[" << count << "/" << capArray << "]" << "{";
//			for (int i = (count - 1); i >= 0; i--)
//			{
//				cout << Array[i];
//				if (i != 0)
//				{
//					cout << ", ";
//				}
//			}
//			cout << "}" << endl;
//			break;
//		}
//		if (choice != 0)
//		{
//			system("pause");
//		}
//	}
//	delete[] Array;
//	return 0;
//}




#include<iostream>
#include<clocale>
using namespace std;



void expandArray(int*& arr, int& capacity)
{
	int newCapacity = capacity * 2;
	int* pmm = new int[newCapacity];
	for (int i = 0; i < capacity; i++)
	{
		pmm[i] = arr[i];

	}

	capacity = newCapacity;
	delete[] arr;
	arr = pmm;
}



void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - �������� ����� � ������" << endl;
	cout << "2 - ������� ������ �� �����" << endl;
	cout << "3 - ����� ����� ������������� �������� �������" << endl;
	cout << "4 - ����� ����������� ������� �������" << endl;
	cout << "5 - ��������� ����� ��������� �������" << endl;
	cout << "6 - ������� ������ � �������� �������" << endl;
}

int main()
{
	int x = 0;
	int cap = 10;
	int count = 0;
	int* a = new int[cap];
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cin >> choice;
		switch (choice)
		{

		case 0:
			break;
		case 1:
			if (count == cap)
			{
				expandArray(a, cap);
			}
			cin >> x;
			a[count] = x;
			count++;

			break;
		case 2:
			cout << "[" << count << "/" << cap << "]" << endl;
			for (int i = 0; i < count; i++)
			{
				cout << a[i] << endl;
			}
			break;
		case 3:
			for (int i = 0; i < count; i++)
			{
				int b = 0;
				int c = 0;

				if (a[i] > b)
				{
					b = a[i];
					c = i;
				}
				if (i == -count)
				{
					cout << c << "-" << a[c] << endl;
				}
			}
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			for (int i = -count; i >= 0; i--)
			{
				cout << a[i] << endl;
			}
			break;
		}
		if (choice != 0)
		{
			system("pause");
		}
	}
	return EXIT_SUCCESS;
}