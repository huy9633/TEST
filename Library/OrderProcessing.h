#ifndef __ORDERSPROCESSING__
#define __ORDERSPROCESSING__

#include"orders.h"
#include"GoodManagement.h"

using namespace std;

void getData(vector< vector<orders> >& _dh) {
	ifstream input;
	input.open("DonHang.txt");

	vector<orders> add;
	while (!input.eof()) {
		orders o;
		input >> o;
		if (o.number == 1) {
			if(add.size() != 0) _dh.push_back(add);	
			add.clear();
		}
		add.push_back(o);
	}
	_dh.push_back(add);

	input.close();
}

void updateFileOrders(vector< vector <orders> > dh) {
	ofstream file;
	file.open("DonHang.txt", ios::trunc);
	// trunc: Xoa tat ca du lieu cua file 

	// Lay du lieu
	if (file.is_open()) {
		for (int i = 0; i < dh.size(); i++) {
			for (int j = 0; j < dh[i].size(); j++) {
				file << dh[i][j];
			}
			if (i != dh.size() - 1) {
				file << endl;
			}
		}
	}
	else {
		cout << "updateOrders() : KHONG the mo duoc FILE HangHoa.txt !" << endl;
	}
	file.close();
}

void process(vector< vector <orders> >& dh, vector<goods>& hh) {
	for (int i = 0; i < dh[0].size(); i++) {
		for (int j = 0; j < hh.size(); j++) {
			if (dh[0][i].seri == hh[j].seri) {
				hh[j].amount = hh[j].amount - dh[0][i].amount;
				break;
			}
		}
	}
	dh.erase(dh.begin());
}

void ORDER(vector< vector <orders> >& dh, vector<goods>& hh) {
	dh.clear();
	getData(dh);
	while(dh.size() != 0){
		process(dh, hh);
		updateGoods(hh);
		updateFileOrders(dh);
	}
	cout << "Don Hang Xu Ly Thanh Cong !";
}

#endif