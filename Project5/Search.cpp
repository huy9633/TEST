#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include<iomanip>
#include<math.h>
using namespace std;
struct goods {
	string seri;
	string name;
	string place;
	string color;
	int price;
	int importDate[3];
	int amount;

	friend istream& operator >>(istream& is, goods& p) {
		is >> p.seri;			is.ignore();
		getline(is, p.name);	is.clear();
		getline(is, p.place);	is.clear();
		getline(is, p.color);	is.clear();
		is >> p.price;
		is >> p.importDate[0] >> p.importDate[1] >> p.importDate[2];
		is >> p.amount;
		return is;
	}
};

class Goods {
protected:
	vector<goods> hh;
public:
	bool input();
	void Search();
	
};
void textcolor(int x);
void gotoxy(short x, short y);
void viet(int x, int y, int z);
int tksanpham(vector <goods> hanghoa, string s);
void xoaTK();
void khung(int x, int y, int m, int n, int mau);
void bangsanpham(int x, int y, int sl);
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
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

void vietchuoi(int x, int y, string s, int mau)
{
	gotoxy(x, y);
	textcolor(mau);
	cout << s;
}
int tksanpham(vector <goods> hanghoa , string s)
{

	for (int i = 0; i < hanghoa.size(); i++)
	{
		if (hanghoa[i].name == s)//stricmp so sanh chuoi
		{
			return i;
		}
	}
	return -1;
}
void xoaTK(int x, int y, string s) {
	for (int i = 0; i <=s.size(); i++) {
		gotoxy(x + s.size()- 1, y);
		printf(" ");
	}
}
void khung(int x, int y, int m, int n, int mau)
{
	int i, j;
	textcolor(mau);
	for (i = x; i <= x + m; i++)
		for (j = y; j <= y + n; j++)
		{
			if (i == x || i == x + m)
			{
				if (j == y && i != x + m)
					viet(i, j, 45);
				else if (j == y && i != x)
					viet(i, j, 45);
				else if (j == y + n && i != x + m)
					viet(i, j, 45);
				else if (j == y + n && i != x)
					viet(i, j, 45);
				else viet(i, j, 124);
			}
			else if (j == y || j == y + n)
				viet(i, j, 45);
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
int main() {
	Goods a;
	string s;
	if (a.input()) {
		a.Search();
	}
	for (;;);
	return 0;
}
bool Goods::input() {
	ifstream input;
	input.open("HangHoa.txt");

	if (input.is_open()) {
		while (!input.eof()) {
			goods add;
			input >> add;
			hh.push_back(add);
		}
	}
	else {
		cout << "KHONG the mo duoc FILE HangHoa.txt !" << endl;
		return false;
	}

	input.close();
	return true;
}
void Goods::Search() {
	string s;
	int vitriTK=12;
nhaplai:
	khung(0+vitriTK, 0, 100, 2, 14);
	vietchuoi(1+vitriTK, 1, "TIEM KIEM:", 206);
	gotoxy(12 + vitriTK, 1);textcolor(14); fflush(stdin); getline(cin, s);
	int tam = tksanpham(hh, s);
	if (tam == -1) {
		vietchuoi(1 + vitriTK, 3, "Khong co san pham ton tai",12 );
		//xoaTK(12,1,s);
		Sleep(1000);
		system("cls");
		goto nhaplai;
	}
	else {
		bangsanpham(0, 5, 4);
		int y = 5 + 3;
		gotoxy(2, y); cout << 1;
		gotoxy(5, y); cout << hh[tam].seri;
		gotoxy(16, y); cout << hh[tam].name;
		gotoxy(44, y); cout << hh[tam].place;
		gotoxy(58, y); cout << hh[tam].color;
		gotoxy(73, y); cout << hh[tam].price;
		gotoxy(87, y); cout << hh[tam].importDate[0] << "/" << hh[tam].importDate[1] << "/" << hh[tam].importDate[2];
		gotoxy(106, y); cout << hh[tam].amount;
	}
}