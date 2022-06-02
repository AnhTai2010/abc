#include "NguoiSoHuuDat.h"
NguoiSoHuuDat::NguoiSoHuuDat()
{
	hoten = "";
	namsinh = 0;
	CMND = 0;
	diachi = "";
}
void NguoiSoHuuDat::Nhap()
{
	cout << "Nhap ho ten nguoi so huu dat: ";
	this->SetHoTen();
	cout << "Nhap nam sinh nguoi so huu dat: ";
	cin >> namsinh;
	cout << "Nhap CMND: ";
	cin >> CMND;
	cout << "Nhap dia chi: ";
	this->SetDiaChi();
}
void NguoiSoHuuDat::Xuat()
{
	cout << "Ho ten nguoi so huu dat: " << hoten << endl;
	cout << "Nam sinh: " << namsinh << endl;
	cout << "CMND: " << CMND << endl;
	cout << "Dia chi: " << diachi << endl;
}
string NguoiSoHuuDat::SetHoTen()
{
	cin.ignore();
	getline(cin, hoten);
	return hoten;
}
string NguoiSoHuuDat::SetDiaChi()
{
	cin.ignore();
	getline(cin, diachi);
	return diachi;
}