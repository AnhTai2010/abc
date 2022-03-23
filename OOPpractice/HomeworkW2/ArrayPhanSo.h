#pragma once
#include<iostream>
#include "PhanSo.h"
using namespace std;
constexpr auto n = 1000;
class ArrayPhanSo
{
	int slPhanSo = n;
	PhanSo *ps1 = new PhanSo[n];
public:
	ArrayPhanSo(PhanSo *);
	void Nhap(int,PhanSo * );
	void Xuat(PhanSo *);
	PhanSo LonNhat(PhanSo*);
	void SapXep(PhanSo*);
	~ArrayPhanSo();
};

