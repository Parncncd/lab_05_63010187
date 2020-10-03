#include<stdio.h>
#include<windows.h>
#include<conio.h>

void draw_ship() {
	printf(" <-0-> ");
}
void erase_ship() {
	printf("       ");
}

void setcolor(int fg, int bg)

{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 2);
	draw_ship();
	setcolor(4, 0);
	COORD cd = { x, y - 1 };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), cd);
	erase_ship();
	
	COORD ce = { x, y + 1 };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), ce);
	erase_ship();

}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
int main()
{
	char ch = ' ';
	int x = 38, y = 20;
	setcursor(0);
	gotoxy(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' && x != 0) { gotoxy(--x, y); }
			if (ch == 'd' && x <= 80) { gotoxy(++x, y); }
			if (ch == 'w' && y != 0) { gotoxy(x, y--); }
			if (ch == 's' && y <= 40) { gotoxy(x, y++); }
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}