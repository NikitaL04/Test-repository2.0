#pragma once
#include <iostream>

struct Element
{
	char key[20];
	int info;
};

class Hash
{
private:
	Element Array[10];
public:
	Hash()
	{
		for (int i = 0; i < 10; i++)
		{
			strcpy_s(Array[i].key, "");
		}
	}
	int AddativeHash(char *Key);
	int OrHash(char* Key);
	void AddElem(char* Key, int Info);
	void SearchElem(char* Key);
	void Del(char* Key);
	void ShowHashTable();
};

