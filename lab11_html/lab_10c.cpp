// lab_10a.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab_10c.h"
#include <stdio.h>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int array[10][10];
int h;
int w;
int px, py, fx, fy, key;

void LEVELUP2(int& h, int& w, int& px, int& py, int& fx, int& fy)
{
    FILE* f;
    fopen_s(&f, "D:\\УлГТУ\\1 Семестер\\Информатика\\ЛАБЫ\\Лаб основы алгаритмизации Лапшов Ю.А\\Отчёты\\temp\\lab10\\level_2.txt", "rt");
    fscanf_s(f, "%d%d%d%d%d%d", &h, &w, &px, &py, &fx, &fy);
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            fscanf_s(f, "%d", &array[x][y]);
        }
    }
    fclose(f);
}

void LEVELUP3(int& h, int& w, int& px, int& py, int& fx, int& fy)
{
    FILE* f;
    fopen_s(&f, "D:\\УлГТУ\\1 Семестер\\Информатика\\ЛАБЫ\\Лаб основы алгаритмизации Лапшов Ю.А\\Отчёты\\temp\\lab10\\level_3.txt", "rt");
    fscanf_s(f, "%d%d%d%d%d%d", &h, &w, &px, &py, &fx, &fy);
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            fscanf_s(f, "%d", &array[x][y]);
        }
    }
    fclose(f);
}

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
    LoadStringW(hInstance, IDC_LAB10C, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB10C));

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

    return (int)msg.wParam;
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

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB10C));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LAB10C);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
    fopen_s(&f, "D:\\УлГТУ\\1 Семестер\\Информатика\\ЛАБЫ\\Лаб основы алгаритмизации Лапшов Ю.А\\Отчёты\\temp\\lab10\\level_1.txt", "rt");
    fscanf_s(f, "%d%d%d%d%d%d", &h, &w, &px, &py, &fx, &fy);
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            fscanf_s(f, "%d", &array[x][y]);
        }
    }
    fclose(f);



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

    case WM_KEYDOWN:
        key = wParam;
        if (key == VK_UP)
        {
            if (array[px][py - 1] != 1)
            {
                py--;
            }
        }

        if (key == VK_DOWN)
        {
            if (array[px][py + 1] != 1)
            {
                py++;
            }
        }

        if (key == VK_LEFT)
        {
            if (array[px - 1][py] != 1)
            {
                px--;
            }
        }

        if (key == VK_RIGHT)
        {
            if (array[px + 1][py] != 1)
            {
                px++;
            }
        }
        if (array[px][py] == 2)
        {
            LEVELUP2(h, w, px, py, fx, fy);
            MessageBoxA(hWnd, "Победа!", "level up", MB_OK);
            InvalidateRect(hWnd, NULL, true);
        }
        if (array[px][py] == 5)
        {
            LEVELUP3(h, w, px, py, fx, fy);
            MessageBoxA(hWnd, "Победа!", "level up", MB_OK);
            InvalidateRect(hWnd, NULL, true);
        }
        InvalidateRect(hWnd, NULL, true);
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        HBRUSH brushes[4];
        brushes[0] = CreateSolidBrush(RGB(200, 200, 200));
        brushes[1] = CreateSolidBrush(RGB(0, 0, 0));
        brushes[2] = CreateSolidBrush(RGB(225, 225, 0));
        brushes[3] = CreateSolidBrush(RGB(0, 159, 23));

        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                SelectObject(hdc, brushes[array[x][y]]);
                Rectangle(hdc, 58 + x * 48, 30 + y * 48, 107 + x * 48, 79 + y * 48);
            }
        }
        //player
        SelectObject(hdc, brushes[2]);
        Rectangle(hdc, 66 + px * 48, 40 + py * 48, 100 + px * 48, 70 + py * 48);

        //final
        SelectObject(hdc, brushes[3]);
        Rectangle(hdc, 58 + fx * 48, 30 + fy * 48, 107 + fx * 48, 79 + fy * 48);

        for (int i = 0; i < 4; i++)
        {
            DeleteObject(brushes[i]);
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
