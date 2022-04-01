#include "DonThuc.h"
float DonThuc::getheso()
{
	return this->heso;
}
int DonThuc::getsomu()
{
	return this->somu;
}
float DonThuc::setheso(float x)
{
	return this->heso = x;
}
int DonThuc::setsomu(int x)
{
	return this->somu = x;
}
DonThuc::DonThuc()
{
	this->heso = 0;
	this->somu = 0;
}
DonThuc::DonThuc(int x, int y)
{
	this->heso = x;
	this->somu = y;
}
void DonThuc::Nhap()
{
	//cout << "Nhap he so:";
	cin >> heso;
	if (heso == 0)
		this->setsomu(0);
	//cout << "Nhap so mu:"; cin >> somu;
}
void DonThuc::Xuat()
{
	if (heso == 1)
	{
		if (somu == 1)
			cout << "x";
		else if (somu == 0)
			cout << heso;
		else cout << "x^" << somu;
	}
	else if (somu == 1)
	{
		cout << heso << "x";
	}
	else if (somu == 0)
	{

		cout << heso;
	}
	else
		cout << heso << "x^" << somu;
}
float DonThuc::GiaTri(float x)
{
	float S = 0;
	if (x == 0)
		return S;
	else return (float)heso * pow(x, somu);
}
DonThuc DonThuc::Cong(DonThuc t)
{
	DonThuc kq;
	kq.heso = heso + t.heso;
	kq.somu = t.somu;
	return kq;
}
DonThuc DonThuc::Tru(DonThuc t)
{
	DonThuc kq;
	kq.heso = heso - t.heso;
	kq.somu = t.somu;
	return kq;
}
DonThuc DonThuc::Nhan(DonThuc t)
{
	DonThuc kq;
	kq.heso = heso * t.heso;
	kq.somu = somu + t.somu;
	return kq;
}
DonThuc DonThuc::Chia(DonThuc t)
{
	DonThuc kq;
	kq.heso = heso / t.heso;
	kq.somu = somu - t.somu;
	return kq;
}
