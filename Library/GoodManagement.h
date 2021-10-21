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
	cout << "0. Thoat\n";
	cout << "1. Them Hang Hoa Moi\n";
	cout << "2. Xoa Ma Hang Hoa\n";
	cout << "3. Cap Nhap So Luong Hang Hoa\n";
	cout << "Nhap Lua Chon: ";
	cin >> n;

	if (n == 0) return;
	else if (n == 1) {
		goods add;
		cout << "Nhap Hang Hoa:\n";
		cin >> add;
		addGoods(hh, add);
	}
	else if (n == 2) {
		string s;
		cout << "Nhap Ma Hang Hoa:\n";
		cin >> s;
		deleteGoods(hh, s);
	}
	else if (n == 3) updateGoods(hh);
	else {
		cout << "\n Vui Long Nhap Lai Dung Lua Chon !\n \n";
	}
	GM(hh);
}

#endif