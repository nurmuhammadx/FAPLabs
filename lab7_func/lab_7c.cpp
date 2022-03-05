#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <utility> //c++ library
using namespace std;

void MinIndex(int* size, int* minIndex, int* array)
{
	//int minIndex = 0;
	for (int i = 0; i < *size; i++)
	{
		if (array[i] < array[*minIndex])
		{
			*minIndex = i;
		}
	}
	printf("\nМин индекс массива: %d", *minIndex);
	return;
}

void MaxIndex(int* size, int *maxIndex, int* array)
{
	//int maxIndex = 0;
	for (int i = 0; i < *size; i++)
	{
		if (array[i] > array[*maxIndex])
		{
			*maxIndex = i;
		}
	}
	printf("\nМакс индекс массива: %d\n", *maxIndex);
	return;
}

void BetweenMinMax(int* size, int *minIndex, int *maxIndex, int* array)
{
	int start = min(*minIndex, *maxIndex);
	int  end = max(*minIndex, *maxIndex);
	printf("Чётные элементы массива между мин и макс: ");
	for (int i = start + 1; i < end; i++)
	{
		if (array[i] % 2 == 0)
		{
			printf("%d ", array[i]);
		}
	}
	printf("\n");
	return;
}

void OutputArray(int *size, int* array)
{
	printf("Ваш массив: ");
	for (int i = 0; i < *size; i++)
	{
		printf("%d ", array[i]);
	}
	return;
}

void InputArray(int* size, int* minIndex, int* maxIndex, int* array)
{
	printf("\nВведите количество элементов массива: ");
	scanf_s("%d", size);
	for (int i = 0; i < *size; i++)
	{
		scanf_s("%d", &array[i]);
	}
	printf("\n");
	OutputArray(size, array);
	MinIndex(size, minIndex, array);
	MaxIndex(size, maxIndex, array);
	BetweenMinMax(size, minIndex, maxIndex, array);
	return;
}

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	int arr[10];
	int min = 0;
	int max = 0;
	InputArray(&n, &min, &max, arr);
	return 0;
}