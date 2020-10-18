#include <iostream>
#include "hashTwo.h"


int hashTwo::AddativeHash(char* Key)
{
	int s = 0;
	while (*Key)
		s += *Key++;
	return s % 10;
}

int hashTwo::OrHash(char* Key)
{
	int s = 0;
	while (*Key)
		s += s ^ *Key++;
	return s % 10;
}

void hashTwo::AddElem(char* Key, int Info)
{
	if (strcmp(Array[AddativeHash(Key)].key, "") == 0)
	{
		strcpy_s(Array[AddativeHash(Key)].key, Key);
		Array[AddativeHash(Key)].info = Info;
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		if (strcmp(Array[(AddativeHash(Key) + i * OrHash(Key)) % 10].key, "") == 0)
		{
			strcpy_s(Array[(AddativeHash(Key) + i * OrHash(Key)) % 10].key, Key);
			Array[(AddativeHash(Key) + i * OrHash(Key)) % 10].info = Info;
			break;
		}
	}
}

void hashTwo::SearchElem(char* Key)
{
	if (strcmp(Array[AddativeHash(Key)].key, Key) == 0)
	{
		std::cout << "Ёлемент найден:" << Array[AddativeHash(Key)].info << std::endl;
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		if (strcmp(Array[(AddativeHash(Key) + i * OrHash(Key)) % 10].key, Key) == 0)
		{
			std::cout << "Ёлемент:" << Array[(AddativeHash(Key) + i * OrHash(Key)) % 10].info << std::endl;
			break;
		}
	}

}

void hashTwo::Del(char* Key)
{
	if (strcmp(Array[AddativeHash(Key)].key, Key) == 0)
	{
		strcpy_s(Array[AddativeHash(Key)].key, "");
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		if (strcmp(Array[(AddativeHash(Key) + i * OrHash(Key)) % 10].key, Key) == 0)
		{
			strcpy_s(Array[(AddativeHash(Key) + i * OrHash(Key)) % 10].key, "");
			break;
		}
	}
}

void hashTwo::ShowHashTable()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << Array[i].key << std::endl;
		std::cout << "_________________________________" << std::endl;
	}
}