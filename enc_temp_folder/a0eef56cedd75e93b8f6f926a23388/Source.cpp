#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>


using namespace std;

void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void viet(int x, int y, int z)
{
	gotoxy(x, y);
	printf("%c", z);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void vietchuoi(int x, int y, string s, int mau)
{
	gotoxy(x, y);
	textcolor(mau);
	cout << s;
}
void tbmenu(int x, int y)
{
	int i, j;
	for (i = x; i <= x + 90; i++)
		for (j = y; j <= y + 25; j++)
		{
			if (i == x || i == x + 30 || i == x + 90)
			{
				if (j == y && i != x && i != x + 90)
					viet(i, j, 203);
				else if (j == y && i != x + 90)
					viet(i, j, 201);
				else if (j == y && i != x)
					viet(i, j, 187);
				else if (j == y + 25 && i != x && i != x + 90)
					viet(i, j, 202);
				else if (j == y + 25 && i != x + 90)
					viet(i, j, 200);
				else if (j == y + 25 && i != x)
					viet(i, j, 188);
				else viet(i, j, 186);
			}
			else if (j == y || j == y + 25)
				viet(i, j, 205);
		}
}

void bangsanpham(int x, int y, int sl)
{
	int i, j;
	textcolor(2);
	for (i = x; i <= x + 117; i++)
		for (j = y; j <= y + sl; j++)
		{
			if (i == x || i == x + 4 || i == x + 15 || i == x + 43 || i == x + 57 || i == x + 72 || i == x + 86 || i == x + 104 || i == x + 117)
			{
				if (j == y && i != x && i != x + 117)
					viet(i, j, 45);
				else if (j == y && i != x + 117)
					viet(i, j, 45);
				else if (j == y && i != x)
					viet(i, j, 45);
				else if (j == y + 2 && i != x && i != x + 117)
					viet(i, j, 45);
				else if (j == y + 2 && i != x + 117)
					viet(i, j, 45);
				else if (j == y + 2 && i != x)
					viet(i, j, 45);
				else if (j == y + sl && i != x && i != x + 117)
					viet(i, j, 45);
				else if (j == y + sl && i != x + 117)
					viet(i, j, 45);
				else if (j == y + sl && i != x)
					viet(i, j, 45);
				else viet(i, j, 124);
			}
			else if (j == y || j == y + 2 || j == y + sl)
				viet(i, j, 45);
		}
	vietchuoi(x + 1, y + 1, "STT", 11);
	vietchuoi(x + 5, y + 1, "Ma hang", 11);
	vietchuoi(x + 16, y + 1, "Ten san pham", 11);
	vietchuoi(x + 44, y + 1, "Noi san xuat", 11);
	vietchuoi(x + 58, y + 1, "Mau sac", 11);
	vietchuoi(x + 73, y + 1, "Gia Ban", 11);
	vietchuoi(x + 87, y + 1, "Ngay nhap kho", 11);
	vietchuoi(x + 106, y + 1, "So luong", 11);
	//		vietchuoi(x+105,y+1,"Thanh tien",11);
}
void display() {
	int n = 10;
	bangsanpham(0, 0, 19);
	for (int i = 0; i < n; i++) {
		gotoxy(2, 3 + i); cout << i;
		
	}
}
int main() {
	display();
	for (;;);
	system("pause");
	return 0;
}