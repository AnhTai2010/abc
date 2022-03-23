#include "PhanSo.h"
PhanSo::PhanSo()
{
	tu = 0;
	mau = 1;
}
void PhanSo::Nhap()
{
	cout << "Nhap tu so:";
	cin >> tu;
	do
	{
		cout << "Nhap mau so:";
		cin >> mau;
	} while (mau == 0);
}
void PhanSo::Xuat()
{
	cout << tu << "/" << mau << " ";
}
float PhanSo::sothuc()
{
	return (float)tu / mau;
}