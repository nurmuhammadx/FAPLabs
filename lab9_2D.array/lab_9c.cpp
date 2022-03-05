﻿// lab_9c.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab_9c.h"
#include <stdio.h>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int array[10][10];
int array2[10][10];
int h; //высота 
int w; //ширина
int k = 0;
int ax[10];
int ay[10];
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
    LoadStringW(hInstance, IDC_LAB9C, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB9C));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB9C));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB9C);
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
    FILE* f;
    fopen_s(&f, "D:\\УлГТУ\\1 Семестер\\Информатика\\ЛАБЫ\\Лаб основы алгаритмизации Лапшов Ю.А\\Отчёты\\temp\\lab9\\lab9.txt", "rt");
    fscanf_s(f, "%d%d", &h, &w);
    for (int x = 0; x < h; x++)
    {
        for (int y = 0; y < w; y++)
        {
            fscanf_s(f, "%d", &array[x][y]);
        }
    }
    fclose(f);

    for (int x = 0; x < h; x++)
    {
        for (int y = 0; y < w; y++)
        {
            array2[x][y] = array[x][y];
        }
    }
    //x
    for (int x = 0; x < h; x++)
    {
        int minx = array2[x][0];
        for (int y = 0; y < w; y++)
        {
            if (minx > array2[x][y])
            {
                minx = array2[x][y];
            }
        }
        ax[x] = minx;
        k++;
    }
    //y
    for (int y = 0; y < w; y++)
    {
        int miny = array2[0][y];
        for (int x = 0; x < h; x++)
        {
            if (miny > array2[x][y])
            {
                miny = array2[x][y];
            }
        }
        ay[y] = miny;
        k++;
    }
    //x & y
    for (int x = 0; x < h; x++)
    {
        for (int y = 0; y < w; y++)
        {
            if (array2[x][y] == ax[x] || array2[x][y] == ay[y])
            {
                array2[x][y] = 0;
            }
        }
    }

    FILE* fi;
    fopen_s(&fi, "D:\\УлГТУ\\1 Семестер\\Информатика\\ЛАБЫ\\Лаб основы алгаритмизации Лапшов Ю.А\\Отчёты\\temp\\lab9\\lab9out.txt", "wt");
    for (int x = 0; x < h; x++)
    {
        for (int y = 0; y < w; y++)
        {
            fprintf(fi, "%d ", array2[x][y]);
        }
    }
    fclose(fi);

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
            HBRUSH blue = CreateSolidBrush(RGB(0, 0, 255));
            HBRUSH green = CreateSolidBrush(RGB(0, 255, 0));
            HBRUSH red = CreateSolidBrush(RGB(255, 0, 0));
            HBRUSH yellow = CreateSolidBrush(RGB(255, 255, 0));

            // 1
            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < h; j++)
                {
                    if (array[j][i] == 1)
                    {
                        HBRUSH blue = CreateSolidBrush(RGB(0, 0, 255));
                        SelectObject(hdc, blue);
                        Rectangle(hdc, 58 + i * 48, 58 + j * 48, 107 + i * 48, 107 + j * 48);
                        DeleteObject(blue);
                    }
                    else if (array[j][i] == 2)
                    {
                        HBRUSH green = CreateSolidBrush(RGB(0, 255, 0));
                        SelectObject(hdc, green);
                        Rectangle(hdc, 58 + i * 48, 58 + j * 48, 107 + i * 48, 107 + j * 48);
                        DeleteObject(green);
                    }
                    else if (array[j][i] == 3)
                    {
                        HBRUSH red = CreateSolidBrush(RGB(255, 0, 0));
                        SelectObject(hdc, red);
                        Rectangle(hdc, 58 + i * 48, 58 + j * 48, 107 + i * 48, 107 + j * 48);
                        DeleteObject(red);
                    }
                    else if (array[j][i] == 4)
                    {
                        HBRUSH yellow = CreateSolidBrush(RGB(255, 255, 0));
                        SelectObject(hdc, yellow);
                        Rectangle(hdc, 58 + i * 48, 58 + j * 48, 107 + i * 48, 107 + j * 48);
                        DeleteObject(yellow);
                    }
                }
            }

            // 2
            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < h; j++)
                {
                    if (array2[j][i] == 0)
                    {
                        HBRUSH white = CreateSolidBrush(RGB(255, 255, 255));
                        SelectObject(hdc, white);
                        Rectangle(hdc, 358 + i * 48, 58 + j * 48, 407 + i * 48, 107 + j * 48);
                        DeleteObject(white);
                    }
                    else if (array2[j][i] == 1)
                    {
                        HBRUSH blue = CreateSolidBrush(RGB(0, 0, 255));
                        SelectObject(hdc, blue);
                        Rectangle(hdc, 358 + i * 48, 58 + j * 48, 407 + i * 48, 107 + j * 48);
                        DeleteObject(blue);
                    }
                    else if (array2[j][i] == 2)
                    {
                        HBRUSH green = CreateSolidBrush(RGB(0, 255, 0));
                        SelectObject(hdc, green);
                        Rectangle(hdc, 358 + i * 48, 58 + j * 48, 407 + i * 48, 107 + j * 48);
                        DeleteObject(green);
                    }
                    else if (array2[j][i] == 3)
                    {
                        HBRUSH red = CreateSolidBrush(RGB(255, 0, 0));
                        SelectObject(hdc, red);
                        Rectangle(hdc, 358 + i * 48, 58 + j * 48, 407 + i * 48, 107 + j * 48);
                        DeleteObject(red);
                    }
                    else if (array2[j][i] == 4)
                    {
                        HBRUSH yellow = CreateSolidBrush(RGB(255, 255, 0));
                        SelectObject(hdc, yellow);
                        Rectangle(hdc, 358 + i * 48, 58 + j * 48, 407 + i * 48, 107 + j * 48);
                        DeleteObject(yellow);
                    }
                }
            }

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
