#include<stdio.h>
#include<windows.h>
#include<conio.h>

void setcolor(int fg, int bg)

{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void draw_ship() {
	setcolor(0, 0);
	printf(" ");
	setcolor(2, 4);
	printf("<-0->");
	setcolor(0, 0);
	printf(" ");
	
}
void erase_ship() {	
	setcolor(2, 0);
	printf("       ");
	
}

void drawBullet(int x,int y) {
	COORD bullet = { x, y };
	printf("*");

}
void eraseBullet(int x,int y) {
	printf(" ");

}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	draw_ship();

	COORD cs = { x, y - 1 };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), cs);
	erase_ship();
	
	COORD cw = { x, y + 1 };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), cw);
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
	char direction = 's';
	int x = 38, y = 20;
	char bullet[5] = "OFF";
	setcursor(0);
	gotoxy(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' && x != 0) {gotoxy(--x, y);}
			if (ch == 'd' && x <= 80) { gotoxy(++x, y); }
			if (ch == 'w' && y != 0) { gotoxy(x, y--); }
			if (ch == 's' && y <= 40) { gotoxy(x, y++); }
			if (ch == ' ') { bullet[5] = "ON"; 
							drawBullet(x,y--); }
			fflush(stdin);

		}
	if (bullet == "ON") {
		eraseBullet(x,y);
		do {
			drawBullet(x,y--);
			Sleep(100);
			eraseBullet(x, y--);

		} while (x <= 80 && y <= 40);
	}
		
		Sleep(100);
	} while (ch != 'x');

	return 0;
}