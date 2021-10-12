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
	void updateGoods();
	void addGoods();
	void deleteGoods(string _seri);
	void display();
};

int main() {
	Goods a;
	string s;
	if (a.input()) {
		a.display();
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

void Goods::updateGoods() {

}

void Goods::addGoods() {
	goods add;
	cin >> add;
	hh.push_back(add);
}

void Goods::deleteGoods(string _seri) {
	bool report = true;
	for (int i = 0; i < hh.size(); i++) {
		if (hh[i].seri == _seri) {
			hh.erase(hh.begin() + i);
			report = false;
		}
	}
	if (report) cout << "Ma hang hoa khong ton tai !" << endl;
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
void Goods::display() {
	input();
	int n = hh.size() + 3;
	bangsanpham(0, 0, n);
	for (int i = 0; i < hh.size(); i++) {
		int y = 3 + i;
		gotoxy(2, y); cout << i + 1;
		gotoxy(5, y); cout << hh[i].seri;
		gotoxy(16, y); cout << hh[i].name;
		gotoxy(44, y); cout << hh[i].place;
		gotoxy(58, y); cout << hh[i].color;
		gotoxy(73, y); cout << hh[i].price;
		gotoxy(87, y); cout << hh[i].importDate[0] << "/" << hh[i].importDate[1] << "/" << hh[i].importDate[2];
		gotoxy(106, y); cout << hh[i].amount;

	}
}