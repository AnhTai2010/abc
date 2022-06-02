#pragma once
#include<iostream>
#include<string>
using namespace std;
class NguoiSoHuuDat
{
	string hoten;
	int namsinh;
	long CMND;
	string diachi;
public:
	NguoiSoHuuDat();
	void Nhap();
	void Xuat();
	string SetHoTen();
	string SetDiaChi();
};

