#pragma once
#include<iostream>
using namespace std;
class DonThuc
{
	float heso;
	int somu;
public:
	DonThuc();
	DonThuc(int, int);
	float getheso();
	int getsomu();
	float setheso(float);
	int setsomu(int);
	void Nhap();
	void Xuat();
	float GiaTri(float);
	DonThuc Cong(DonThuc);
	DonThuc Tru(DonThuc);
	DonThuc Nhan(DonThuc);
	DonThuc Chia(DonThuc);
};

