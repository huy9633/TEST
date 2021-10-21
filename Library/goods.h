#ifndef __GOODS__
#define __GOODS__

#include<iostream>
#include<string>
using namespace std;

struct goods {
	string seri;
	string name;
	string place;
	string color;
	int price;
	int importDate[3];
	int amount;

	friend istream& operator >>(istream& is, goods& g) {
		is >> g.seri;			is.ignore();
		getline(is, g.name);	is.clear();
		getline(is, g.place);	is.clear();
		getline(is, g.color);	is.clear();
		is >> g.price;
		is >> g.importDate[0] >> g.importDate[1] >> g.importDate[2];
		is >> g.amount;
		return is;
	}
	friend ostream& operator <<(ostream& os, goods g) {
		os << g.seri << endl << g.name << endl << g.place << endl << g.color << endl;
		os << g.price << endl;
		os << g.importDate[0] << " " << g.importDate[1] << " " << g.importDate[2] << " " << endl;
		os << g.amount;
		return os;
	}

	// su dung trong ham void updateGoods()
	void operator +=(goods g) { // Neu ma hang hoa giong nhau thi cap nhap lai so luong
		amount += g.amount;
	}
};

#endif