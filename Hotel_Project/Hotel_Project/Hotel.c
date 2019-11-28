#pragma warning (disable:4996)
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define X 50
#define Y 18

void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Hotel_draw(int x, int y);
void menu_draw(int x, int y);

int main() {
	int x, y, choice;
	x = X - 10; y = 7;
	Hotel_draw(x, y);
	x = X; y = Y;
	menu_draw(x, y);
	gotoxy(x, 21);

	scanf("%d", &choice);
}

void Hotel_draw(int x, int y) {
	gotoxy(x, y);
	printf("*     *   *******  *******  ********  *\n");
	y++; gotoxy(x, y);
	printf("*     *  *       *    *     *         *\n");
	y++; gotoxy(x, y);
	printf("*******  *       *    *     ********  *\n");
	y++; gotoxy(x, y);
	printf("*     *  *       *    *     *         *\n");
	y++; gotoxy(x, y);
	printf("*     *   *******     *     ********  ******\n");
	y++; gotoxy(x, y);
}

void menu_draw(int x, int y) {
	gotoxy(x, y - 1);//x=50, y=17
	printf("收收收收收收收收收收收收收收收收收收");
	gotoxy(x, y); //x=50,y=18
	printf("| <1> Owner mode |");
	y++; gotoxy(x, y); //y=19
	printf("| <2> Guest mode |");
	y++; gotoxy(x, y);
	printf("收收收收收收收收收收收收收收收收收收\n");
	y++; gotoxy(x, y);
	printf("___");
}