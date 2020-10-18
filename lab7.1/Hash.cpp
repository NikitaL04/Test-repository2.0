#include <iostream>
#include "Hash.h"


int Hash::AddativeHash(char* Key)
{
	int s = 0;
	while (*Key)
		s += *Key++;
	return s % 10;
}

int Hash::OrHash(char* Key)
{
	int s = 0;
	while (*Key)
		s += s ^ *Key++;
	return s % 10;
}

void Hash::AddElem(char* Key, int Info)
{
	if (strcmp(Array[AddativeHash(Key)].key, "") == 0)
	{
		strcpy_s(Array[AddativeHash(Key)].key, Key);
		Array[AddativeHash(Key)].info = Info;
		return;
	}
	else
	{
		if (strcmp(Array[OrHash(Key)].key, "") == 0)
		{
			strcpy_s(Array[OrHash(Key)].key, Key);
			Array[OrHash(Key)].info = Info;
			return;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (AddativeHash(Key) + i < 10 && strcmp(Array[AddativeHash(Key) + i].key, "") == 0)
		{
			strcpy_s(Array[AddativeHash(Key) + i].key, Key);
			Array[AddativeHash(Key) + i].info = Info;
			break;
		}
		if (AddativeHash(Key) + i >= 10 && strcmp(Array[AddativeHash(Key) + i - 10].key, "") == 0)
		{
			strcpy_s(Array[AddativeHash(Key) + i - 10].key, Key);
			Array[AddativeHash(Key) + i - 10].info = Info;
			break;
		}
	}
}

void Hash::SearchElem(char* Key)
{
	if (strcmp(Array[AddativeHash(Key)].key, Key) == 0)
	{
		std::cout << "Ёлемент найден:" << Array[AddativeHash(Key)].info << std::endl;
		return;
	}
	else
	{
		if (strcmp(Array[OrHash(Key)].key, Key) == 0)
		{
			std::cout << "Ёлемент найден:" << Array[OrHash(Key)].info << std::endl;
			return;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (AddativeHash(Key) + i < 10 && strcmp(Array[AddativeHash(Key) + i].key, Key) == 0)
		{
			std::cout << "Ёлемент:" << Array[AddativeHash(Key) + i].info << std::endl;
			break;
		}
		else
		{
			if (AddativeHash(Key) + i >= 10 && strcmp(Array[AddativeHash(Key) + i - 10].key, Key) == 0)
			{
				std::cout << "Ёлемент:" << Array[AddativeHash(Key) + i - 10].info << std::endl;
				break;
			}
		}
	}

}

void Hash::Del(char* Key)
{
	if (strcmp(Array[AddativeHash(Key)].key, Key) == 0)
	{
		strcpy_s(Array[AddativeHash(Key)].key, "");
		return;
	}
	else
	{
		if (strcmp(Array[OrHash(Key)].key, Key) == 0)
		{
			strcpy_s(Array[OrHash(Key)].key, "");
			return;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (AddativeHash(Key) + i < 10 && strcmp(Array[AddativeHash(Key) + i].key, Key) == 0)
		{
			strcpy_s(Array[AddativeHash(Key)].key, "");
			break;
		}
		else
		{
			if (AddativeHash(Key) + i >= 10 && strcmp(Array[AddativeHash(Key) + i - 10].key, Key) == 0)
			{
				strcpy_s(Array[AddativeHash(Key)].key, "");
				break;
			}
		}
	}
}

void Hash::ShowHashTable()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << Array[i].key << std::endl;
		std::cout << "_________________________________" << std::endl;
	}
}