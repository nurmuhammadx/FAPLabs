#include <stdio.h>
#include <locale.h>

struct Point
{
	int x;
	int y;
	int R;
	int W;
	int R1;
	int G;
	int B;
};

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int n;
	FILE* f;
	fopen_s(&f, "D:\\УлГТУ\\1 Семестер\\Информатика\\ЛАБЫ\\Лаб основы алгаритмизации Лапшов Ю.А\\Отчёты\\temp\\lab12\\TOPDOP.bin", "wb");
	printf("Кол - во Звезд: ");
	scanf_s("%d", &n);
	fwrite(&n, sizeof(int), 1, f);
	for (int i = 0; i < n; i++)
	{
		printf("Координаты звезды №%d: ", i + 1);
		Point p;
		printf("\nВведите X1,Y1,R,W,(R G B): ");
		scanf_s("%d%d%d%d%d%d%d", &p.x, &p.y, &p.R, &p.W, &p.R1, &p.G, &p.B);
		fwrite(&p, sizeof(Point), 1, f);
	}
	fclose(f);

	printf("\n");
	return 0;
}