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
			cout << "Введите ключ:" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin.getline(Key, 19);
			cout << "Введите данные:" << endl;
			cin >> Info;
			hash1.AddElem(Key, Info);
		}
		break;
		case 2:
		{
			cout << "Введите ключ:" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin.getline(Key, 19);
			cout << "Введите данные:" << endl;
			cin >> Info;
			hash2.AddElem(Key, Info);
		}
		break;
		case 3:
		{
			cout << "Ввыедите ключ для удаления:" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin.getline(Key, 19);
			hash1.Del(Key);

		}
		break;
		case 4:
		{
			cout << "Ввыедите ключ для удаления:" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin.getline(Key, 19);
			hash2.Del(Key);
		}
		break;
		case 5:
		{
			cout << "Ввыедите ключ, который нужно найти:" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin.getline(Key, 19);
			hash1.SearchElem(Key);
		}
		break;
		case 6:
		{
			cout << "Ввыедите ключ, который нужно найти:" << endl;
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
		default:cout << "Повторите ввод" << endl;
		}

		system("pause");
		system("cls");
		Menu();
		cin >> choose;
	}
}

void Menu()
{
	cout << "1. Добавить эелемент в таблицу методом кукушки" << endl;
	cout << "2. Добавить эелемент в таблицу методом двойного хеширования" << endl;
	cout << "3. Удалить элемент из таблицы методом кукушки" << endl;
	cout << "4. Удалить элемент из таблицы двойного хеширования" << endl;
	cout << "5. Найти элемент в таблице методом кукушки" << endl;
	cout << "6. Найти элемент в таблице методом двойного хеширования" << endl;
	cout << "7. Показать таблицу методом кукушки" << endl;
	cout << "8. Показать таблицу методом двойного хеширования" << endl;
	cout << "9. Выход" << endl;
}