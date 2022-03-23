// PracticeOOPClasses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PhanSo.h"
#include "ArrayPhanSo.h"
using namespace std;
int main()
{
    std::cout << "Hello World!\n";
    int sl = 1;
    PhanSo *ps2 = new PhanSo[n];
    ArrayPhanSo arrps1(ps2);
    arrps1.Nhap(sl, ps2);
    arrps1.Xuat(ps2);
    PhanSo max = arrps1.LonNhat(ps2);
    cout << "\nPhan so lon nhat: ";
    max.Xuat();
    cout << "\nmang sap xep tang dan:" << endl;
    arrps1.SapXep(ps2);
}

