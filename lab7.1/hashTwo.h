#pragma once
#include <iostream>

struct Element1
{
	char key[20];
	int info;
};

class hashTwo
{
private:
	Element1 Array[10];
public:
	hashTwo()
	{
		for (int i = 0; i < 10; i++)
		{
			strcpy_s(Array[i].key, "");
		}
	}
	int AddativeHash(char* Key);
	int OrHash(char* Key);
	void AddElem(char* Key, int Info);
	void SearchElem(char* Key);
	void Del(char* Key);
	void ShowHashTable();
};

