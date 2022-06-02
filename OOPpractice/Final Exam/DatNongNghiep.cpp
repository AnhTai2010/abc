#include "DatNongNghiep.h"

DatNongNghiep::DatNongNghiep()
{
    kieudat = "DatNongNghiep";
    HSD = 0;
}

void DatNongNghiep::Nhap()
{
    DatDai::Nhap();
    cout << "Nhap thoi han su dung: ";
    cin >> HSD;
}

void DatNongNghiep::Xuat()
{
    DatDai::Xuat();
    cout << "Thoi han su dung den nam: " << HSD << endl;
}

int DatNongNghiep::GetHSD()
{
    return HSD;
}
