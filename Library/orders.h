#ifndef __ORDERS__
#define __ORDERS__

#include<iostream>
#include<string>
#include<vector>
#include"goods.h"

using namespace std;

struct orders {
	int number;
	string seri;
	int amount;
	string customerName;
	string address;
	string phoneNumber;
	int orderDate[3];
	long total_money;

	friend istream& operator >> (istream& is, orders& order) {
		is >> order.number; // number se tu dong nhap o checkandreport()
		is >> order.seri;
		is >> order.amount;					is.ignore();
		getline(is, order.customerName);	is.clear();
		getline(is, order.address);			is.clear();
		is >> order.phoneNumber;
		for (int i = 0; i < 3; i++) {
			is >> order.orderDate[i]; 
		}
		is >> order.total_money; // total_money se tu dong tinh bang ham calculateTotalMoney() o checkandreport()
		return is;
	}
	friend ostream& operator << (ostream& os, orders order) {
		os << order.number << endl;
		os << order.seri << endl;
		os << order.amount << endl;
		os << order.customerName << endl;
		os << order.address << endl;
		os << order.phoneNumber << endl;
		for (int i = 0; i < 3; i++) {
			os << order.orderDate[i] << " ";
		}
		os << endl << order.total_money;
		return os;
	}
	void calculateTotalMoney(vector<goods> hh) {
		for (int i = 0; i < hh.size(); i++) {
			if (hh[i].seri == seri) {
				total_money = (long) amount * hh[i].price;
				return;
			}
		}
	}
};

#endif
