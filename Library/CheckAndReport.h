#ifndef _CHECKANDREPORT_
#define _CHECKANHREPORT_
#include "orders.h"
#include "goods.h"
#include "GoodManagement.h"


void CHECKANDREPORT(vector<goods> hanghoa) {
	Input(hanghoa);
	orders x;
	bool test = false;
	int count = 1, i;

	ofstream os;
	os.open("DonHang.txt", fstream::app);

	for (i = 0; i < count;) {
	
		// nhap don hang
		x.number = count;
		cin >> x.seri;
		cin >> x.amount;					cin.ignore();
		getline(cin, x.customerName);	cin.clear();
		getline(cin, x.address);			cin.clear();
		cin >> x.phoneNumber;
		for (int i = 0; i < 3; i++) {
			cin >> x.orderDate[i];
		}
		x.calculateTotalMoney(hanghoa); // ham tu tinh tong tien (total money)

		for (int i = 0; i < hanghoa.size(); i++)
		{
			if (hanghoa[i].seri == x.seri)
			{
				test = true;
				//  hang hoa trong kho phai lon hon hoac bang so luong hang hoa nhap
				if (hanghoa[i].amount >= x.amount)
				{
					// MINH ghi xuat ra tong tien : x.total_money;

					hanghoa[i].amount -= x.amount;
					os << x << endl;
					count++;
					cout << "Quy khach da dang ky thanh cong. Don hang dang cho xu ly";
					//[ESC]
					Sleep(2000);
					system("cls");
					break;
				}
				else {
					test = true;
					cout << "Hien tai khong du so luong hang hoa. Quy khach vui long chon hang hoa khac. Xin cam on";
					Sleep(2000);
					system("cls");
					break;

				}
			}
		}
		i--;
		if (!test)
		{
			cout << "Ma hang khong ton tai. Vui long dien lai. Xin cam on";
			Sleep(2000);
			system("cls");
		}
		test = false;
	}
	os.close();

}
#endif
