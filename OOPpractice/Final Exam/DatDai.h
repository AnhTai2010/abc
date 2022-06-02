#pragma once
#include<iostream>
#include<string>
#include"NguoiSoHuuDat.h"
using namespace std;
class DatDai
{
protected:
	string sogiaychungnhan;
	int sothuadat;
	int sotobando;
	string diachi;
	float dientich;
	string ngaycap;
	float giathue1m2;
	int songuoisohuu;
	NguoiSoHuuDat **human;
	string kieudat;
public:
	DatDai();
	virtual void Nhap();
	virtual void Xuat();
	float TongThueHangNam();
	string GetKieuDat();
};

