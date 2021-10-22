#ifndef _CHECKANDREPORT_
#define _CHECKANHREPORT_
#include <iostream>
#include "orders.h"
#include "goods.h"
#include <fstream>
#include "GoodManagement.h"


void CheckAndReport(vector<goods>& hanghoa, vector<orders>& dh)
{
	Input(hanghoa);
	orders x;
	bool test = false;
	int count = 1, i;
	ofstream os;
	os.open("DonHang.txt");
	for (i = 0; i < count;)
	{
		cout << "STT " << count << endl;
		cin >> x;
		for (int i = 0; i < hanghoa.size(); i++)
		{
			if (hanghoa[i].seri == x.seri)
			{
				test = true;
				//  hang hoa trong kho phai lon hon hoac bang so luong hang hoa nhap
				if (hanghoa[i].amount >= x.amount)
				{
					hanghoa[i].amount -= x.amount;
					os << "STT " << count << endl;
					os << x << endl;
					count++;
					cout << "Quy khach da dang ky thanh cong. Don hang dang cho xu ly";
					dh.push_back(x);
					Sleep(2000);
					system("cls");
					break;
				}
				else
				{
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