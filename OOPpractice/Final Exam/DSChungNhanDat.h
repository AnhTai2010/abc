#pragma once
#include"DatDai.h"
#include"DatNongNghiep.h"
#include"DatXayNha.h"
#include<iostream>
using namespace std;
class DSChungNhanDat
{
	DatDai** dat;
	int loaidat;
	int realyear;
	int soluongdatcapphat;
public:
	DSChungNhanDat();
	void Nhap();
	DatDai ThueNhieuNhat();
	void HetHanSuDung();
	void Xuat();
};

