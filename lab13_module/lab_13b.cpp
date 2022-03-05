#include <stdio.h>
#include <locale.h>
#include "headerB.h"

void strlen()
{
	char str[256];
	printf("Введите строку: ");
	gets_s(str);
	int x = Strlen(str);
	printf("Длина строки: %d\n", x);
}

void strcpy()
{
	char str1[256], str2[256];
	printf("\nВведите 1 строку для strcpy: ");
	gets_s(str1);
	printf("Введите 2 строку для strcpy: ");
	gets_s(str2);
	Strcpy(str1, str2);
	printf("Строки после копирование: \n%s\n%s\n", str1, str2);
}

void strcat()
{
	char str1[256], str2[128];
	printf("\nВведите 1 строку для strcat: ");
	gets_s(str1);
	printf("Введите 2 строку для strcat: ");
	gets_s(str2);
	Strcat(str1, str2);
	printf("Строка после дописывание: %s\n", str1);
}

void strcmp()
{
	char str1[256], str2[256];
	printf("\nВведите 1 строку для strcmp: ");
	gets_s(str1);
	printf("Введите 2 строку для strcmp: ");
	gets_s(str2);
	int x = Strcmp(str1, str2);
	printf("Строки после сравнение: %d\n", x);
}

void strchr()
{
	char str[256], ch;
	printf("\nВведите строку для strchr: ");
	gets_s(str);
	printf("Введите букву которую, хотите найти для strchr: ");
	scanf_s("%c", &ch);
	//char* pos = Strchr(str, ch);
	printf("Адрес символа в строке: %s", Strchr(str, ch));
}

int main(void)
{
	setlocale(LC_ALL, "Russian");
	strlen();
	strcpy();
	strcat();
	strcmp();
	strchr();

	printf("\n");
	return 0;
}