// logo_lab2.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "logo_lab2.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

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
    LoadStringW(hInstance, IDC_LOGOLAB2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LOGOLAB2));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LOGOLAB2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LOGOLAB2);
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

            //ellipse benz
            hPen = CreatePen(PS_SOLID, 7, RGB(131, 137, 150));
            SelectObject(hdc, hPen);
            Ellipse(hdc, 450, 160, 760, 450);
            //m
            MoveToEx(hdc, 530, 510, NULL);
            LineTo(hdc, 530, 470);
            LineTo(hdc, 540, 490);
            LineTo(hdc, 550, 470);
            LineTo(hdc, 550, 510);
            //-
            MoveToEx(hdc, 565, 490, NULL);
            LineTo(hdc, 575, 490);
            //b
            MoveToEx(hdc, 590, 470, NULL);
            LineTo(hdc, 590, 510);
            LineTo(hdc, 610, 510);
            LineTo(hdc, 610, 490);
            LineTo(hdc, 590, 490);
            MoveToEx(hdc, 605, 490, NULL);
            LineTo(hdc, 605, 470);
            LineTo(hdc, 590, 470);
            //e
            MoveToEx(hdc, 640, 470, NULL);
            LineTo(hdc, 620, 470);
            LineTo(hdc, 620, 510);
            LineTo(hdc, 640, 510);
            MoveToEx(hdc, 640, 490, NULL);
            LineTo(hdc, 620, 490);
            //n
            MoveToEx(hdc, 650, 510, NULL);
            LineTo(hdc, 650, 470);
            LineTo(hdc, 670, 510);
            LineTo(hdc, 670, 470);
            //z
            MoveToEx(hdc, 680, 470, NULL);
            LineTo(hdc, 700, 470);
            LineTo(hdc, 680, 510);
            LineTo(hdc, 700, 510);

            

            //Mitsu-bishi
            hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(255, 0, 0));
            SelectObject(hdc, hBrush);

            POINT pt[15];
            pt[0].x = 200;
            pt[0].y = 200;
            pt[1].x = 160;
            pt[1].y = 260;
            pt[2].x = 200;
            pt[2].y = 320;
            pt[3].x = 240;
            pt[3].y = 260;
            pt[4].x = 200;
            pt[4].y = 200; 
            pt[5].x = 200;
            pt[5].y = 320;
            pt[6].x = 120;
            pt[6].y = 320;
            pt[7].x = 80;
            pt[7].y = 370;
            pt[8].x = 160;
            pt[8].y = 370;
            pt[9].x = 200;
            pt[9].y = 320;
            pt[10].x = 200;
            pt[10].y = 320;
            pt[11].x = 275;
            pt[11].y = 320;
            pt[12].x = 320;
            pt[12].y = 370;
            pt[13].x = 240;
            pt[13].y = 370;
            pt[14].x = 200;
            pt[14].y = 320;
            Polygon(hdc, pt, 15);

            //line shadow
            hPen = CreatePen(PS_SOLID, 3, RGB(110, 127, 128));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 200, 200, NULL);
            LineTo(hdc, 240, 260);
            LineTo(hdc, 200, 320);
            LineTo(hdc, 160, 370);
            LineTo(hdc, 80, 370);
            LineTo(hdc, 160, 370);

            MoveToEx(hdc, 275, 320, NULL);
            LineTo(hdc, 320, 370);
            LineTo(hdc, 240, 370);

            //Mercedes-Benz
            
            hBrush = CreateSolidBrush(RGB(131, 137, 150));
            SelectObject(hdc, hBrush);
            
            POINT mb[7];
            mb[0].x = 604;
            mb[0].y = 160;
            mb[1].x = 580;
            mb[1].y = 300;
            mb[2].x = 470;
            mb[2].y = 370;
            mb[3].x = 607;
            mb[3].y = 340;
            mb[4].x = 740;
            mb[4].y = 370;
            mb[5].x = 630;
            mb[5].y = 300;
            mb[6].x = 607;
            mb[6].y = 180;



            Polygon(hdc, mb, 7);






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
