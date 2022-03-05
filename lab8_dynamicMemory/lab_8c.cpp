#include <iostream>
#include <stdio.h>
#include <locale>
#include <conio.h>
#include <utility> //c++ library
using namespace std;

int* InputArray(int* size)
{
	int* arr;
	int n;
	FILE* f;
	fopen_s(&f, "D:\\УлГТУ\\1 Семестер\\Информатика\\ЛАБЫ\\Лаб основы алгаритмизации Лапшов Ю.А\\Отчёты\\temp\\lab8\\input.txt", "rt");
	fscanf_s(f, "%d", &n);
	*size = n;
	arr = (int*)malloc(n * sizeof(int)); // динамическая память
	for (int i = 0; i < *size; i++)
	{
		fscanf_s(f, "%d", &arr[i]);
	}
	fclose(f);
	return arr;
}

void MinIndex(int* arr, int n, int* k)
{
	int minIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < arr[minIndex])
		{
			minIndex = i;
		}
	}
	*k = minIndex;
}

void MaxIndex(int* arr, int n, int* x)
{
	int maxIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > arr[maxIndex])
		{
			maxIndex = i;
		}
	}
	*x = maxIndex;
}

void OutputBetweenMinMax(int* arr, int n, int* k, int* x)
{
	FILE* f;
	fopen_s(&f, "D:\\УлГТУ\\1 Семестер\\Информатика\\ЛАБЫ\\Лаб основы алгаритмизации Лапшов Ю.А\\Отчёты\\temp\\lab8\\output.txt", "wt");
	int start = min(*k, *x);
	int  end = max(*k, *x);
	fprintf(f, "Четные элементы между мин и макс: ");
	for (int i = start + 1; i < end; i++)
	{
		if (arr[i] % 2 == 0)
		{
			fprintf(f, "%d ", arr[i]);
		}
	}
	fclose(f);
}

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int* a; // создаем указатель на массив
	int n; // создаем переменную для кол-ва элементов массива
	int min, max;
	a = InputArray(&n);
	MinIndex(a, n, &min);
	MaxIndex(a, n, &max);
	OutputBetweenMinMax(a, n, &min, &max);
	free(a); // освободить динамическую память
	_getch();
	return 0;
}