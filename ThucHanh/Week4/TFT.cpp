// Hackerrank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
static int luot = 0;
static int mockichhoat = 0;
class MatTham
{
protected:
	int attack;
	string tentuong;
public:
	MatTham();
	virtual void Nhap();
	void Xuat();
	virtual void DealDame () = 0;
};
class Zed:public MatTham
{
public:
	void Nhap();
	void DealDame();
};
class Shaco:public MatTham
{
public:
	void Nhap();
	void DealDame();
};
int main()
{
	int n = 0, flag1 = 0, flag2 = 0;
	cin >> n; // nhap so luong tuong
	MatTham** TFT = new MatTham*[100];
	int loai = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> loai;
		if (loai == 1)
		{
			flag1 = 1;
			TFT[i] = new Shaco;
		}
		if (loai == 2)
		{
			flag2 = 1;
			TFT[i] = new Zed;
		}
		TFT[i]->Nhap();
	}
	cin >> luot;
	if (flag1 == 1 && flag2 == 1)
	{
		mockichhoat = 2;
	}
	for (int i = 0; i < n; i++)
	{
		TFT[i]->DealDame();
		TFT[i]->Xuat();
	}
	return 0;
}
MatTham::MatTham()
{
	attack = 0;
}
void MatTham::Nhap()
{
	cin  >> attack;
}
void MatTham::Xuat()
{
	cout << tentuong << "-" << "Sat thuong gay ra:" << attack << endl;
}
void MatTham::DealDame()
{
	if (mockichhoat >= 2)
		attack += 10; // moc 2 tro len
	else
		attack = attack; // duoi moc 2
}
/////////////////////////////////
void Zed::Nhap()
{
	MatTham::Nhap();
	tentuong = "Zed";
}
void Zed::DealDame()
{
	MatTham::DealDame();
	int temp = attack;
	int bonus = attack * 3;
	for (int i = 0; i < luot-1; i++)
	{
		if (i % 3 == 0)
			attack += bonus; // luot 3 gay sat thuong x3
		else
			attack += temp; // moi luot gay sat thuong = dame co ban + moc 2 mat tham
	}
}
///////////////////////////////////
void Shaco::Nhap()
{
	MatTham::Nhap();
	tentuong = "Shaco";
}
void Shaco::DealDame()
{
	MatTham::DealDame();
	int bonus = attack * 2;
	int temp = bonus;
	for (int i = 0; i < luot-1; i++)
	{
		bonus += temp; // gay x2 dame auto 
	}
	attack = bonus;
}