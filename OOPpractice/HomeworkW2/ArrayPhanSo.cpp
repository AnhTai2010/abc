#include "ArrayPhanSo.h"
ArrayPhanSo::ArrayPhanSo(PhanSo* s)
{
	s = new PhanSo[slPhanSo];
}
void ArrayPhanSo::Nhap(int x , PhanSo *k)
{
	cout << "nhap so luong phan so:";
	cin >> x;
	slPhanSo = x;
	for (int i = 0; i < slPhanSo; i++)
	{
		k[i].Nhap();
	}
}
void ArrayPhanSo::Xuat(PhanSo* k)
{
	cout << "danh sach mang phan so:" << endl;
	for (int i = 0; i < slPhanSo; i++)
	{
		k[i].Xuat();
	}
}
PhanSo ArrayPhanSo::LonNhat(PhanSo* k)
{
	int vitri = 0;
	float s = k[0].sothuc();
	for (int i = 1; i < slPhanSo; i++)
	{
		if (k[i].sothuc() > s)
		{
			s = k[i].sothuc();
			vitri = i;
		}
	}
	return k[vitri];
}
void ArrayPhanSo::SapXep(PhanSo* k)
{
	PhanSo x;
	for (int i = 0; i < slPhanSo; i++)
	{
		for (int j = i + 1; j < slPhanSo; j++)
		{
			if (k[i].sothuc() > k[j].sothuc())
			{
				x = k[i];
				k[i] = k[j];
				k[j] = x;
			}
		}
		k[i].Xuat();
	}
}
ArrayPhanSo::~ArrayPhanSo()
{
	delete[]ps1;
}