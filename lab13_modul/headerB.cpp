#include <stdio.h>
#include "headerB.h"

int Strlen(char* str)
{
	int i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return i;
}

void Strcpy(char* str1, char* str2)
{
	for (int i = 0; i <= Strlen(str1); i++)
	{
		str2[i] = str1[i];
	}
}

void Strcat(char* str1, char* str2)
{
	int str2_size = Strlen(str2);
	int size = Strlen(str1) + Strlen(str2);

	for (unsigned int i = str2_size; i <= size; i++)
	{
		str1[i] = str2[i - str2_size];
	}
}

int Strcmp(char* str1, char* str2)
{
	for (int i = 0; ; i++) {
		if (str1[i] != str2[i])
			return str1[i] - str2[i];

		if (str1[i] == '\0')
			return 0;
	}
}

char* Strchr(char* str, char ch)
{
	for (; *str != '\0'; str++)
		if (*str == ch)
			return (char*)str;

	return NULL;
}