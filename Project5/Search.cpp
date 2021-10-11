#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

//hàm chung
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
int tksanpham(SANPHAM A[], char s[])
{
	int i;
	for (i = 0; i < a; i++)
	{
		if (stricmp(s, A[i].masp) == 0)//stricmp so sanh chuoi
		{
			return i;
		}
	}
	return -1;
}
int main() {

}