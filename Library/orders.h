#ifndef __ORDERS__
#define __ORDERS__

#include<iostream>
#include<string>
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
		is >> order.number >> order.seri;
		is >> order.amount;					is.ignore();
		getline(is, order.customerName);	is.clear();
		getline(is, order.address);			is.clear();
		is >> order.phoneNumber;
		for (int i = 0; i < 3; i++) {
			is >> order.orderDate[i]; 
		}
		is >> order.total_money;
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
		os << order.total_money;
		return os;
	}
};

#endif