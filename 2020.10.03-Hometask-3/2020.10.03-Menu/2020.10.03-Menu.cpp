#include<iostream>
#include<clocale>
#include<ctime>

using namespace std;


void printMenu()
{
    cout << "����" << endl;
    cout << "0 - ����� �� ���������" << endl;
    cout << "1 - ������ ��������� ��������� � ����������" << endl;
    cout << "2 - �������� � ������ n ��������� ����� � ���������� �� a �� b(n, a, b �������� � ����������)" << endl;
    cout << "3 - ������� ������ �� �����" << endl;
    cout << "4 - ����� ������� ��������" << endl;
    cout << "5 - ���������� ������ � �������" << endl;
    cout << "6 - ����������� ��������" << endl;
    cout << "7 - ������� �������� � ������" << endl;
    cout << "8 - �������� ���������� ������ ������ ��������� �������" << endl;
    cout << "9 - ����� ���������������������" << endl;
}



void conclusion(int a)
{
    if (a == 0)
    {
        cout << "�������� ��������� �������" << endl;
    }
    else
    {
        cout << "�� ������� ��������� ��������" << endl;
    }
}



int* initArray(int capacity)
{
    int* result = new int[capacity + 2]{ 0 };
    result += 2;
    result[-1] = capacity;
    return result;
}



void deleteArray(int* arr)
{
    arr -= 2;
    delete[] arr;
}



void expandArray(int*& arr, int& cap)    //�������� ������ ������� � ������, ���� ��� �����������
{
    int newCap = cap * 2;
    int* temp = new int[newCap] {0};
    for (int i = 0; i < cap; ++i)        //������������� �������� ��� ������������ ��������� �������
    {
        temp[i] = arr[i];
    }
    cap = newCap;
    delete[] arr;
    arr = temp;
}



void addElement(int*& arr, int &count, int &cap, int element)
{
    if (count + 1 < cap)
    {
        arr[count] = element;
    }
    else
    {
        expandArray(arr, cap);
        arr[count] = element;
    }
    ++count;
}



void add_M_Elements(int*& arr, int& count, int& cap)
{
    cout << "������� ��������, ������� ������ �������� � ������." << endl;
    cout << "����� ���������� �������� ��� �������� � ������ 0, ������� 0." << endl;
    int n = 1;
    while (n != 0)
    {
        cin >> n;
        addElement(arr, count, cap, n);
        ++count;
    }
    cout << "����� ������ 0, ��� ������� �������, ������� 1." << endl;
    cout << "����� ��������� ��������, ������� 0." << endl;
    cin >> n;
    if (n == 1)
    {
        addElement(arr, count, cap, n);
        ++count;
    }
}



void addRandomElements(int*& arr, int& count, int& cap, int n, int min, int max)
{
    for (int i = 0; i < n; ++i)
    {
        addElement(arr, count, cap, rand() % (max - min + 1) + min);
    }
    count += n;
}



void printArray(int* arr, int count)
{
    cout << "[" << arr[-2] << "/" << arr[-1] << "] {";
    for (int i = 0; i < arr[-2]; ++i)
    {
        cout << *(arr + i) << (i == arr[-2] - 1 ? "}\n" : ", ");
    }
}



int search(int* arr, int count, int element, int start)
{
    int a = -1;
    for (int i = start; i < count; ++i)
    {
        if (arr[i] == element)
        {
            a = i;
            break;
        }
    }
    return a;
}



void add(int*& arr, int& count, int& cap, int* addedArr, int addedCount)
{
    for (int i = count; i < count + addedCount; ++i)
    {
        addElement(arr, count, cap, addedArr[i - count]);
    }
}



int* unify(int* a, int countA, int* b, int countB)
{
    int* arr=initArray(countA + countB + 10);
    for (int i = 0; i < countA + countB; i += 2)
    {
        arr[i] = a[i];
        arr[i + 1] = b[i];
    }
    arr[-2] = countA + countB;
    return arr;
}



int extract(int*& a, int& count,  int index)
{
    if ((index < 0) or (index >= count))
    {
        return 1;
    }
    else
    {
        int c = a[index];
        for (int i = index; i < count - 1; ++i)
        {
            a[i] = a[i + 1];
        }
        a[count - 1] = 0;
        return c;
    }
}



int insert(int*& a, int& count, int& cap, int index, int element)
{
    if (index < 0)
    {
        return 1;
    }
    else if (index < cap)
        {
            if (count + 1 >= cap)
            {
                expandArray(a, cap);
            }
            for (int i = count + 1; i > index; --i)
            {
                a[i] = a[i - 1];
            }
            a[index] = element;
            ++count;
            return 0;
        }
    else
    {
        while (index >= cap)
        {
            expandArray(a, cap);
        }
        a[index] = element;
        ++count;
        return 0;
    }
}



int deleteGroup(int*& a, int& count, int startIndex, int n)
{
    if ((startIndex < 0) or (startIndex + n >= count))
    {
        return 1;
    }
    else
    {
        for (int i = startIndex; i < count-n; ++i)
        {
            a[i] = a[i + n];
        }
        count -= n;
        return 0;
    }
}



int subSequence(int* a, int countA, int* b, int countB)
{
    int k = 0;
    int* c = initArray(countB);
    for (int i = 0; i < countA - countB; ++i)
    {
        c[0] = search(a, countA, b[0], i);
        for (int j = 1; j < countB; ++j)
        {
            c[j] = search(a, countA, b[j], i);
            if (c[j] != c[j - 1] + 1)
            {
                k = -1;
                break;
            }
            else
            {
                k = 2;
            }
        }
        if (k == 2)
        {
            k = c[0];
            break;
        }
    }
    return k;
}



void processChoice(int*& arr1, int*& arr2, int choice)
{
    int n = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    switch (choice)
    {
    case 1:
        cout << "������� 0, ����� �������� �������� � ������ a" << endl;
        cout << "������� 1, ����� �������� �������� � ������ b" << endl;
        cin >> c;
        if (c == 0)
        {
            add_M_Elements(arr1, arr1[-2], arr1[-1]);
        }
        else
        {
            add_M_Elements(arr2, arr2[-2], arr2[-1]);
        }
        break;
    case 2:
        cout << "������� 0, ����� �������� �������� � ������ a" << endl;
        cout << "������� 1, ����� �������� �������� � ������ b" << endl;
        cin >> c;
        cout << "������� n" << endl;
        cin >> n;
        cout << "������� a" << endl;
        cin >> a;
        cout << "������� b" << endl;
        cin >> b;
        if (c == 0)
        {
            addRandomElements(arr1, arr1[-2], arr1[-1], n, a, b);
        }
        else
        {
            addRandomElements(arr2, arr2[-2], arr2[-1], n, a, b);
        }
        break;
    case 3:
        cout << "������� 0, ����� ������� ������ a" << endl;
        cout << "������� 1, ����� ������� ������ b" << endl;
        cin >> c;
        if (c == 0)
        {
            printArray(arr1, arr1[-2]);
        }
        else
        {
            printArray(arr2, arr2[-2]);
        }
        break;
    case 4:
        cout << "������� 0, ����� ����� ����� �������� ������� a" << endl;
        cout << "������� 1, ����� ����� ����� �������� ������� b" << endl;
        cin >> c;
        cout << "������� �������, ������� ������ �����" << endl;
        cin >> a;
        cout << "������� ������, � ������� ������ �����" << endl;
        cin >> n;
        if (c == 0)
        {
            b = search(arr1, arr1[-2], a, n);
        }
        else
        {
            b = search(arr2, arr2[-2], a, n);
        }
        cout << b;
        break;
    case 5:
        cout << "������� 0, ����� �������� ������ b � ������ a" << endl;
        cout << "������� 1, ����� �������� ������ a � ������ b" << endl;
        cin >> c;
        if (c == 0)
        {
            add(arr1, arr1[-2], arr1[-1], arr2, arr2[-2]);
        }
        else
        {
            add(arr2, arr2[-2], arr2[-1], arr1, arr1[-2]);
        }
        break;
    case 6:
        cout << "������� 0, ����� �������� ������� a ������ �� �������� �������" << endl;
        cout << "������� 1, ����� �������� ������� b ������ �� �������� �������" << endl;
        cin >> c;
        if (c == 0)
        {
            int* a = unify(arr1, arr1[-2], arr2, arr2[-2]);
            printArray(a, a[-2]);
            deleteArray(a);
        }
        else
        {
            int* a = unify(arr2, arr2[-2], arr1, arr1[-2]);
            printArray(a, a[-2]);
            deleteArray(a);
        }
        break;
    case 7:
        cout << "������� 0, ����� �������� ������� � ������ a" << endl;
        cout << "������� 1, ����� �������� ������� � ������ b" << endl;
        cin >> c;
        cout << "������� �������, ������� ������ ��������" << endl;
        cin >> a;
        cout << "������� ������, ������� ����� ��������� ������ ��������" << endl;
        cin >> n;
        if (c == 0)
        {
            b = insert(arr1, arr1[-2], arr1[-1], a, n);
        }
        else
        {
            b = insert(arr2, arr2[-2], arr2[-1], a, n);
        }
        conclusion(b);
        break;
    case 8:
        cout << "������� 0, ����� ������� ������������������ �� ������� a" << endl;
        cout << "������� 1, ����� ������� ������������������ �� ������� b" << endl;
        cin >> c;
        cout << "������� ������, � �������� ���������� ������������������" << endl;
        cin >> a;
        cout << "������� ���������� ��������� ������������������" << endl;
        cin >> n;
        if (c == 0)
        {
            b = deleteGroup(arr1, arr1[-2], a, n);
        }
        else
        {
            b = deleteGroup(arr2, arr2[-2], a, n);
        }
        conclusion(b);
        break;
    case 9:
        cout << "������� 0, ����� ����� ������������������ b � ������� a" << endl;
        cout << "������� 1, ����� ����� ������������������ a � ������� b" << endl;
        cin >> c;
        if (c == 0)
        {
            b = subSequence(arr1, arr1[-2], arr2, arr2[-2]);
        }
        else
        {
            b = subSequence(arr2, arr2[-2], arr1, arr1[-2]);
        }
        conclusion(b);
        break;
    }
}



int main(int argc, char* argv[])
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    int* a = initArray(10);
    int* b = initArray(10);
    int choice = 0;
    do
    {
        system("cls");
        printMenu();
        cin >> choice;
        processChoice(a, b, choice);
        system("pause");
    } while (choice != 0);
    deleteArray(a);
    deleteArray(b);
    return EXIT_SUCCESS;
}