//#include<stdio.h>
//#include<windows.h>
//#include<conio.h>
//
//void setcolor(int fg, int bg)
//
//{
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
//}
//void draw_ship() {
//
//	printf(" <-0-> ");
//}
//void erase_ship() {
//	printf("       ");
//
//}
//
//
//void gotoxy(int x, int y)
//{
//	COORD c = { x, y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
//	setcolor(2, 4);
//	draw_ship();
//	setcolor(2, 0);
//	COORD cs = { x, y - 1 };
//	SetConsoleCursorPosition(
//		GetStdHandle(STD_OUTPUT_HANDLE), cs);
//	erase_ship();
//
//	COORD cw = { x, y + 1 };
//	SetConsoleCursorPosition(
//		GetStdHandle(STD_OUTPUT_HANDLE), cw);
//	erase_ship();
//
//	COORD cd = { --x, y };
//	SetConsoleCursorPosition(
//		GetStdHandle(STD_OUTPUT_HANDLE), cd);
//	printf(" ");
//
//	COORD ca = { ++x, y };
//	SetConsoleCursorPosition(
//		GetStdHandle(STD_OUTPUT_HANDLE), ca);
//	setcolor(0, 0);
//
//
//
//}
//void setcursor(bool visible)
//{
//	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO lpCursor;
//	lpCursor.bVisible = visible;
//	lpCursor.dwSize = 20;
//	SetConsoleCursorInfo(console, &lpCursor);
//}
//int main()
//{
//	char ch = ' ';
//	int x = 38, y = 20;
//	setcursor(0);
//	gotoxy(x, y);
//	do {
//		if (_kbhit()) {
//			ch = _getch();
//			if (ch == 'a' && x != 0) { gotoxy(--x, y); }
//			if (ch == 'd' && x <= 80) { gotoxy(++x, y); }
//			if (ch == 'w' && y != 0) { gotoxy(x, y--); }
//			if (ch == 's' && y <= 40) { gotoxy(x, y++); }
//			fflush(stdin);
//		}
//		Sleep(100);
//	} while (ch != 'x');
//	return 0;
//}