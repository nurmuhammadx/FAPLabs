// lab_6c.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab_6c.h"
#include <stdio.h>
using namespace std;

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int n;
int minIndex = 0;
int maxIndex = 0;
int arr_1[10];
int arr_2[10];
int start;
int end;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB6C, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB6C));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

void DrawLine(HDC hdc, int x, int y, int s)
{
    MoveToEx(hdc, x, y, NULL);
    LineTo(hdc, x, y + s * 1.5);
    LineTo(hdc, x + s * 3, y + s * 1.5);
}

void DrawTriangleUp(HDC hdc, int x, int y, int s)
{
    MoveToEx(hdc, x, y, NULL);
    LineTo(hdc, x - s / 2, y + s);
    LineTo(hdc, x + s / 2, y + s);
    LineTo(hdc, x, y);
}

void DrawTriangleDawn(HDC hdc, int x, int y, int s)
{
    MoveToEx(hdc, x, y, NULL);
    LineTo(hdc, x, y + s);
    LineTo(hdc, x + s, y + s / 2);
    LineTo(hdc, x, y);
}

//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB6C));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB6C);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    //первая цифра в файле "input.txt" это количество элементов массива
    FILE* f;
    fopen_s(&f, "D:\\УлГТУ\\1 Семестер\\Информатика\\ЛАБЫ\\Лаб основы алгаритмизации Лапшов Ю.А\\Отчёты\\temp\\lab8\\input.txt", "rt");
    fscanf_s(f, "%d", &n);//сдесь задаётся колво элеметов массива
    for (int i = 0; i < n; i++) {
        fscanf_s(f, "%d", &arr_1[i]);
    }
    fclose(f);

    for (int i = 0; i < n; i++) {
        arr_2[i] = arr_1[i];
    }
    //minindex
    for (int i = 0; i < n; i++) {
        if (arr_2[i] < arr_2[minIndex]) {
            minIndex = i;
        }
    }
    //maxindex
    for (int i = 0; i < n; i++) {
        if (arr_2[i] > arr_2[maxIndex]) {
            maxIndex = i;
        }
    }

    start = min(minIndex, maxIndex);
    end = max(minIndex, maxIndex);

   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HPEN hPen;
            HBRUSH hBrush;

            //first diagram
            hPen = CreatePen(PS_SOLID, 2, RGB(184, 220, 220));//154, 255, 255
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(0, 0, 128));
            SelectObject(hdc, hBrush);
            for (int i = 0; i < n; i++) {
                Rectangle(hdc, 10 + i * 30, 300 - arr_1[i], 40 + i * 30, 300);
            }

            //second diagram
            for (int i = 0; i < n; i++) {
                Rectangle(hdc, 400 + i * 30, 300 - arr_2[i], 430 + i * 30, 300);
            }
            //Четные элементы массива между мин и макс
            for (int i = start + 1; i < end; i++) {
                if (arr_2[i] % 2 == 0) {
                    hBrush = CreateSolidBrush(RGB(0, 128, 0));
                    SelectObject(hdc, hBrush);
                    Rectangle(hdc, 400 + i * 30, 300 - arr_2[i], 430 + i * 30, 300);
                    DeleteObject(hBrush);
                }
            }

            DeleteObject(hBrush);
            DeleteObject(hPen);

            //lines and triangles
            hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));//154, 255, 255
            SelectObject(hdc, hPen);
            for (int i = 0; i < 2; i++) {
                DrawLine(hdc, 10 + i * 390, 150, 100);
                DrawTriangleUp(hdc, 9.9 + i * 390, 145, 10);
                DrawTriangleDawn(hdc, 300 + i * 390, 295, 10);
            }
            DeleteObject(hPen);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
