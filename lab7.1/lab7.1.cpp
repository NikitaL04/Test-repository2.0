#include <iostream>
#include "Hash.h"
#include "hashTwo.h"

using namespace std;

void Menu();

int main()
{
	setlocale(LC_ALL, "Russian");
	char Key[20];
	int Info;
	int choose;

	Hash hash1;
	hashTwo hash2;

	Menu();
	cin >> choose;
	while (choose != 9)
	{
		switch (choose)
		{
		case 1:
		{
			cout << "������� ����:" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin.getline(Key, 19);
			cout << "������� ������:" << endl;
			cin >> Info;
			hash1.AddElem(Key, Info);
		}
		break;
		case 2:
		{
			cout << "������� ����:" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin.getline(Key, 19);
			cout << "������� ������:" << endl;
			cin >> Info;
			hash2.AddElem(Key, Info);
		}
		break;
		case 3:
		{
			cout << "�������� ���� ��� ��������:" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin.getline(Key, 19);
			hash1.Del(Key);

		}
		break;
		case 4:
		{
			cout << "�������� ���� ��� ��������:" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin.getline(Key, 19);
			hash2.Del(Key);
		}
		break;
		case 5:
		{
			cout << "�������� ����, ������� ����� �����:" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin.getline(Key, 19);
			hash1.SearchElem(Key);
		}
		break;
		case 6:
		{
			cout << "�������� ����, ������� ����� �����:" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin.getline(Key, 19);
			hash2.SearchElem(Key);
		}
		break;
		case 7:
		{
			hash1.ShowHashTable();
		}
		break;
		case 8:
		{
			hash2.ShowHashTable();
		}
		break;
		default:cout << "��������� ����" << endl;
		}

		system("pause");
		system("cls");
		Menu();
		cin >> choose;
	}
}

void Menu()
{
	cout << "1. �������� �������� � ������� ������� �������" << endl;
	cout << "2. �������� �������� � ������� ������� �������� �����������" << endl;
	cout << "3. ������� ������� �� ������� ������� �������" << endl;
	cout << "4. ������� ������� �� ������� �������� �����������" << endl;
	cout << "5. ����� ������� � ������� ������� �������" << endl;
	cout << "6. ����� ������� � ������� ������� �������� �����������" << endl;
	cout << "7. �������� ������� ������� �������" << endl;
	cout << "8. �������� ������� ������� �������� �����������" << endl;
	cout << "9. �����" << endl;
}