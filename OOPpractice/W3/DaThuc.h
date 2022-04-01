#pragma once
#include<iostream>
#include "DonThuc.h"
constexpr auto n = 1000;
using namespace std;
class DaThuc
{
	int bac;
	DonThuc* dt;
public:
	DaThuc();
	DaThuc(int);
	float GiaTri(float);
	void Nhap();
	void Xuat();
	int getbac();
	int setbac(int);
	DaThuc Cong(DaThuc, DaThuc);
	DaThuc Tru(DaThuc, DaThuc);
	DaThuc Nhan(DaThuc, DaThuc);
	DaThuc Chia(DaThuc, DaThuc);
};

