#include <iostream>
#include<string>
using namespace std;
class Thuyen
{
protected:
	string sohieu;
	string loaithuyen;
	string HangDong;
	int thuyenvien;
public:
	Thuyen()
	{
		thuyenvien = 0;
	}
	virtual void Nhap()
	{
		cin >> sohieu;
		cin >> thuyenvien;
	}
	virtual void Xuat()
	{
		cout << sohieu << " - " << loaithuyen << " - " << thuyenvien << " thuyen vien ";
	}
};
class Ghe :public Thuyen
{
	int DongCo ;
public:
	Ghe() { DongCo = 0; }
	void Nhap()
	{
		Thuyen::Nhap();
		loaithuyen = "Ghe";
		cin >> DongCo;
	}
	void Xuat()
	{
		Thuyen::Xuat();
		if (DongCo)
		{
			cout << "- Co Dong Co";
		}
		else;
	}
};
class ThuyenThuong :public Thuyen
{
public:
	ThuyenThuong()
	{

	}
	void Nhap()
	{
		Thuyen::Nhap();
		cin >> HangDong;
		loaithuyen = "Thuyen thuong";
	}
	void Xuat()
	{
		Thuyen::Xuat();
		cout << "- " << HangDong;
	}
};
class ThuyenLon :public Thuyen
{
	int phamvirakhoi;
public:
	ThuyenLon()
	{
		phamvirakhoi = 0;
	}
	void Nhap()
	{
		Thuyen::Nhap();
		cin >> HangDong;
		cin >> phamvirakhoi;
		loaithuyen = "Thuyen lon";
	}
	void Xuat()
	{
		Thuyen::Xuat();
		cout << "- " << HangDong << " - " << phamvirakhoi << "m";
	}
};
class ChiecThuyenNgoaiXa
{
	Thuyen** Phung;
	int soluonganh;
public:
	ChiecThuyenNgoaiXa();
	void Nhap();
	void Xuat();
};
int main()
{
	ChiecThuyenNgoaiXa p1;
	p1.Nhap();
	p1.Xuat();
	return 0;
}
ChiecThuyenNgoaiXa::ChiecThuyenNgoaiXa()
{
	Phung = new Thuyen * [100];
	soluonganh = 0;
}
void ChiecThuyenNgoaiXa::Nhap()
{
	cin >> soluonganh;
	int loai = 0;
	for (int i = 0; i < soluonganh; i++)
	{
		cin >> loai;
		if (loai == 1)
		{
			Phung[i] = new Ghe;
		}
		else if (loai == 2)
		{
			Phung[i] = new ThuyenThuong;
		}
		else if (loai == 3)
		{
			Phung[i] = new ThuyenLon;
		}
		else;
		Phung[i]->Nhap();
	}
}
void ChiecThuyenNgoaiXa::Xuat()
{
	for (int i = 0; i < soluonganh; i++)
	{
		Phung[i]->Xuat();
		cout << endl;
	}
}