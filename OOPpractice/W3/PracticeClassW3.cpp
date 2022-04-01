// PracticeClassW3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DonThuc.h"
#include "DaThuc.h"
using namespace std;
int main()
{
    //DonThuc dt1,dt2, dtcong,dttru,dtnhan,dtchia;
   /* dt1.Nhap();
    dt2.Nhap();
    dt1.Xuat();
    dt2.Xuat();
    float x = 0; cin >> x;
    float S = dt1.GiaTri(x);
    cout << S;
    dtcong = dt1.Cong(dt2);
    dtcong.Xuat();
    dttru = dt1.Tru(dt2);
    dttru.Xuat();
    dtnhan = dt1.Nhan(dt2);
    dtnhan.Xuat();
    dtchia = dt1.Chia(dt2);
    dtchia.Xuat();*/
    DaThuc dt1, dt2, dtcong, dttru, dtnhan;
    dt1.Nhap();
    cout << "da thuc thu nhat:" << endl;
    dt1.Xuat();
    cout << endl;
    dt2.Nhap();
    cout << "da thuc thu hai:" << endl;
    dt2.Xuat();
    cout << endl;
    dtcong = dtcong.Cong(dt1, dt2);
    cout << "Cong hai da thuc:" << endl;
    dtcong.Xuat();
    cout << endl;
    dttru = dttru.Tru(dt1, dt2);
    cout << "Tru hai da thuc:" << endl;
    dttru.Xuat();
    cout << endl;
    dtnhan = dtnhan.Nhan(dt1, dt2);
    cout << "Nhan hai da thuc:" << endl;
    dtnhan.Xuat();
}


