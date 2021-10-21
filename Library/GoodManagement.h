#ifndef __GOODSMANAGEMENT__
#define __GOODSMANAGEMENT__

#include"goods.h"
#include"Functions.h"
#include<vector>
#include<fstream>
using namespace std;

void updateGoods(vector<goods>& hh) {
	// Neu ma hang ton tai thi cap nhat lai so luong hang hoa tuong ung
	for (int i = 0; i < hh.size(); i++) {
		for (int j = i + 1; j < hh.size(); j++) {
			if (hh[i].seri == hh[j].seri) {

				hh[i] += hh[j];
				hh.erase(hh.begin() + j);
			}
		}
	}

	ofstream file;
	file.open("HangHoa.txt", ios::trunc);
	// trunc: Xoa tat ca du lieu cua file 

	// Update du lieu
	if (file.is_open()) {
		for (int i = 0; i < hh.size(); i++) {
			file << hh[i];
			if (i != hh.size() - 1) {
				file << endl;
			}
		}
		//cout << "updateGoods() : Da Cap Nhap Thanh Cong !" << endl;
	}
	else {
		cout << "updateGoods() : KHONG the mo duoc FILE HangHoa.txt !" << endl;
	}
	file.close();
}
void addGoods(vector<goods>& hh, goods g) {
	hh.push_back(g);
}
void deleteGoods(vector<goods>& hh, string _seri) {
	bool report = true;
	for (int i = 0; i < hh.size(); i++) {
		if (hh[i].seri == _seri) {
			hh.erase(hh.begin() + i);
			report = false;
		}
	}
	if (report) cout << "Ma hang hoa khong ton tai !" << endl;
}
void GM(vector<goods>& hh) {
	int n;
	khung(30, 3, 67, 17, 14);
	int ck = 1;
	int x = 0, y = 0;
	khung(x + 44, y + 5, 40, 2, 14); vietchuoi(x + 45, y + 6, "Them Hang Hoa Moi", 15);
	khung(x + 44, y + 5 + 3, 40, 2, 0);	vietchuoi(x + 45, y + 6 + 3, "Xoa Ma Hang Hoa", 6);
	khung(x + 44, y + 5 + 6, 40, 2, 0);	vietchuoi(x + 45, y + 6 + 6, "Cap Nhap So Luong Hang Hoa", 6);
	khung(x + 44, y + 5 + 9, 40, 2, 0);	vietchuoi(x + 45, y + 6 + 9, "Thoat", 6);
	for (;;) {
		gotoxy(0, 0);
		int k = keyboard();
		if (k == 2) {
			if (ck == 1) {
				ck = 2;
				khung(x + 44, y + 5, 40, 2, 0);	vietchuoi(x + 45, y + 6, "Them Hang Hoa Moi", 6);
				khung(x + 44, y + 5 + 3, 40, 2, 14); vietchuoi(x + 45, y + 6 + 3, "Xoa Ma Hang Hoa", 15);
				khung(x + 44, y + 5 + 6, 40, 2, 0);	vietchuoi(x + 45, y + 6 + 6, "Cap Nhap So Luong Hang Hoa", 6);
				khung(x + 44, y + 5 + 9, 40, 2, 0);	vietchuoi(x + 45, y + 6 + 9, "Thoat", 6);

			}
			else if (ck == 2) {
				ck = 3;
				khung(x + 44, y + 5, 40, 2, 0);	vietchuoi(x + 45, y + 6, "Them Hang Hoa Moi", 6);
				khung(x + 44, y + 5 + 3, 40, 2, 0);	vietchuoi(x + 45, y + 6 + 3, "Xoa Ma Hang Hoa", 6);
				khung(x + 44, y + 5 + 6, 40, 2, 14); vietchuoi(x + 45, y + 6 + 6, "Cap Nhap So Luong Hang Hoa", 15);
				khung(x + 44, y + 5 + 9, 40, 2, 0);	vietchuoi(x + 45, y + 6 + 9, "Thoat", 6);

			}
			else if (ck == 3) {
				ck = 4;
				khung(x + 44, y + 5, 40, 2, 0);	vietchuoi(x + 45, y + 6, "Them Hang Hoa Moi", 6);
				khung(x + 44, y + 5 + 3, 40, 2, 0);	vietchuoi(x + 45, y + 6 + 3, "Xoa Ma Hang Hoa", 6);
				khung(x + 44, y + 5 + 6, 40, 2, 0); vietchuoi(x + 45, y + 6 + 6, "Cap Nhap So Luong Hang Hoa", 6);
				khung(x + 44, y + 5 + 9, 40, 2, 14); vietchuoi(x + 45, y + 6 + 9, "Thoat", 15);

			}
			else if (ck == 4) {
				ck = 1;
				khung(x + 44, y + 5, 40, 2, 14);	vietchuoi(x + 45, y + 6, "Them Hang Hoa Moi", 15);
				khung(x + 44, y + 5 + 3, 40, 2, 0);	vietchuoi(x + 45, y + 6 + 3, "Xoa Ma Hang Hoa", 6);
				khung(x + 44, y + 5 + 6, 40, 2, 0); vietchuoi(x + 45, y + 6 + 6, "Cap Nhap So Luong Hang Hoa", 6);
				khung(x + 44, y + 5 + 9, 40, 2, 0); vietchuoi(x + 45, y + 6 + 9, "Thoat", 6);
			}
		}
		else if (k == 1) {
			if (ck == 1) {
				ck = 4;
				khung(x + 44, y + 5, 40, 2, 0);	vietchuoi(x + 45, y + 6, "Them Hang Hoa Moi", 6);
				khung(x + 44, y + 5 + 3, 40, 2, 0);	vietchuoi(x + 45, y + 6 + 3, "Xoa Ma Hang Hoa", 6);
				khung(x + 44, y + 5 + 6, 40, 2, 0); vietchuoi(x + 45, y + 6 + 6, "Cap Nhap So Luong Hang Hoa", 6);
				khung(x + 44, y + 5 + 9, 40, 2, 14); vietchuoi(x + 45, y + 6 + 9, "Thoat", 15);
			}
			else if (ck == 4) {
				ck = 3;
				khung(x + 44, y + 5, 40, 2, 0);	vietchuoi(x + 45, y + 6, "Them Hang Hoa Moi", 6);
				khung(x + 44, y + 5 + 3, 40, 2, 0);	vietchuoi(x + 45, y + 6 + 3, "Xoa Ma Hang Hoa", 6);
				khung(x + 44, y + 5 + 6, 40, 2, 14); vietchuoi(x + 45, y + 6 + 6, "Cap Nhap So Luong Hang Hoa", 15);
				khung(x + 44, y + 5 + 9, 40, 2, 0); vietchuoi(x + 45, y + 6 + 9, "Thoat", 6);
			}
			else if (ck == 3) {
				ck = 2;
				khung(x + 44, y + 5, 40, 2, 0);	vietchuoi(x + 45, y + 6, "Them Hang Hoa Moi", 6);
				khung(x + 44, y + 5 + 3, 40, 2, 14); vietchuoi(x + 45, y + 6 + 3, "Xoa Ma Hang Hoa", 15);
				khung(x + 44, y + 5 + 6, 40, 2, 0); vietchuoi(x + 45, y + 6 + 6, "Cap Nhap So Luong Hang Hoa", 6);
				khung(x + 44, y + 5 + 9, 40, 2, 0); vietchuoi(x + 45, y + 6 + 9, "Thoat", 6);
			}
			else if (ck == 2) {
				ck = 1;
				khung(x + 44, y + 5, 40, 2, 14); vietchuoi(x + 45, y + 6, "Them Hang Hoa Moi", 15);
				khung(x + 44, y + 5 + 3, 40, 2, 0); vietchuoi(x + 45, y + 6 + 3, "Xoa Ma Hang Hoa", 6);
				khung(x + 44, y + 5 + 6, 40, 2, 0); vietchuoi(x + 45, y + 6 + 6, "Cap Nhap So Luong Hang Hoa", 6);
				khung(x + 44, y + 5 + 9, 40, 2, 0); vietchuoi(x + 45, y + 6 + 9, "Thoat", 6);
			}

		}
		else if (k == 3) {
			if (ck == 1) {
				goods add;
				system("cls");
				vietchuoi(x + 1 , y + 0, "Nhap Hang Hoa: ", 6);
				bangsanpham(1, 1, 4);
				gotoxy(3, 4); cout << "1";
				gotoxy(6, 4); cin >> add.seri; cin.ignore();
				gotoxy(17, 4); getline(cin, add.name); cin.clear();
				gotoxy(45, 4); getline(cin, add.place);  cin.clear();
				gotoxy(59, 4); getline(cin, add.color);	cin.clear();
				gotoxy(74, 4); cin >> add.price;
				gotoxy(88, 4); cin >> add.importDate[0]; gotoxy(90, 4); cout << "/";
				gotoxy(91, 4); cin >> add.importDate[1]; gotoxy(93, 4); cout << "/";
				gotoxy(94, 4); cin >> add.importDate[2];
				gotoxy(106, 4); cin >> add.amount;
				addGoods(hh, add);
				vietchuoi(40 , 6, "De Cap Nhap Hang Hoa Vao File Vui Long Chon Cap Nhap",9);
				Sleep(2000);
				
				
			}
			else if (ck == 2) {
				system("cls");
				string s;
				khung(30, 3, 67, 17, 178);
				vietchuoi(x + 45, y + 6, "Nhap Ma Hang Hoa: ", 6);
				cin >> s;
				deleteGoods(hh, s);
			}
			else if (ck == 3) {
				system("cls");
				khung(30, 3, 67, 17, 178);
				vietchuoi(x + 45, y + 6, "Dang Cap Nhat...", 6);
				updateGoods(hh);

			}
			else if (ck == 4) {
				system("cls");
				
				exit(0);

			}
			system("cls");
			GM(hh);
		}
	}



	
}

#endif
