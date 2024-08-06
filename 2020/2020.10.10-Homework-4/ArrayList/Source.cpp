#include<iostream>
#include<ctime>
#include"ArrayList.h"




void printMenu()
{
	std::cout << "МЕНЮ" << std::endl;
	std::cout << "0 - Выход из программы" << std::endl;
	std::cout << "1 - Вывести массив на экран" << std::endl;
	std::cout << "2 - Добавить элемент" << std::endl;
	std::cout << "3 - Добавить элемент в позицию" << std::endl;
	std::cout << "4 - Удалить элемент по индексу" << std::endl;
	std::cout << "5 - Найти элемент" << std::endl;
	std::cout << "6 - Добавить несколько элементов" << std::endl;
	std::cout << "7 - Добавить несколько элементов, начиная с некоторой позиции" << std::endl;
}



void processChoice(ArrayList& a, ArrayList& b, int choice, int element, int index, int j)
//void processChoice(ArrayList& a, int choice, int element, int index)
{
	switch (choice)
	{
	case 1:
		a.print();
		break;
	case 2:
		std::cout << "Введите элемент, который хотите добавить в список" << std::endl;
		std::cin >> element;
		std::cout << a.add(element) << std::endl;
		break;
	case 3:
		std::cout << "Введите элемент, который хотите добавить в список" << std::endl;
		std::cin >> element;
		std::cout << "Введите индекс, который хотите присвоить введенному элементу" << std::endl;
		std::cin >> index;
		std::cout << a.add(index, element) << std::endl;
		break;
	case 4:
		std::cout << "Введите индекс элемента, который хотите удалить" << std::endl;
		std::cin >> index;
		std::cout << a.remove(index) << std::endl;
		break;
	case 5:
		std::cout << "Введите элемент, который хотите найти" << std::endl;
		std::cin >> element;
		std::cout << a.indexOf(element) << std::endl;
		break;
	case 6:
		std::cout << "Вводите элементы, которые хотите добавить в массив." << std::endl;
		std::cout << "Чтобы остановить операцию, введите 0." << std::endl;
		while ((element != 0) and (b.count < b.capacity))
		{
			std::cin >> element;
			b.data[j] = element;
			++b.count;
			++j;
		}
		std::cout << a.addAll(a.count, b) << std::endl;
		b.clear();
		break;
	case 7:
		std::cout << "Введите индекс, с которого хотите добавлять элементы в список" << std::endl;
		std::cin >> index;
		std::cout << "Вводите элементы, которые хотите добавить в массив." << std::endl;
		std::cout << "Чтобы остановить операцию, введите 0." << std::endl;
		while ((element != 0) and (b.count < b.capacity))
		{
			std::cin >> element;
			b.data[j] = element;
			++b.count;
			++j;
		}
		std::cout << a.addAll(index, b) << std::endl;
		b.clear();
		break;
	}
}


int main()
{
	int element = 1;
	int index = 0;
	int j = 0;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList a;
	ArrayList b;
	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		std::cin >> choice;
		//processChoice(a, choice, element, index);
		processChoice(a, b, choice, element, index, j);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}