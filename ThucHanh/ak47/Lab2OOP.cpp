#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>4
#include<string>
using namespace std;
class CPU
{
protected:
	string MaCPU;
	int LoaiCPU;
	string Hang;
	int core;
	float xungnhip;
	float Gia;
public :
	CPU()
	{
		LoaiCPU = 0;
		core = 0;
		xungnhip = 0;
		Gia = 0;
	}
	virtual void Nhap()
	{
		cout << "Nhap loai CPU (1-loai Alpha, 2-loai Beta, 3-loai Gamma)";
		cin >> LoaiCPU;
		cout << "Nhap Ma CPU: ";
		cin >> MaCPU;
	}
	virtual void Xuat()
	{
		cout << "CPU: " << MaCPU << " " << LoaiCPU << " " << Hang << " " << core << " "
			<< xungnhip << "GHz " << Gia << endl;
	}
	int GetLoaiCPU()
	{
		return LoaiCPU;
	}
	float GetGiaCPU()
	{
		return Gia;
	}
};
class Alpha :public CPU
{
public:
	Alpha()
	{
		LoaiCPU = 1;
		Gia = 200;
		core = 2;
		xungnhip = 1.8;
		Hang = "Black";
	}
	void Nhap()
	{
		CPU::Nhap();
	}
};
class Beta :public CPU
{
public:
	Beta()
	{
		LoaiCPU = 2;
		Gia = 400;
		core = 4;
		xungnhip = 2.46;
		Hang = "Black";
	}
	void Nhap()
	{
		CPU::Nhap();
	}
};
class Gamma :public CPU
{
public:
	Gamma()
	{
		LoaiCPU = 3;
		core = 4;
		xungnhip = 2.6;
		Hang = "White";
		Gia = 600;
	}
	void Nhap()
	{
		CPU::Nhap();
	}
};
////////////////////////////////
class ManHinh
{
protected:
	string MaManHinh;
	string HangSanXuat;
	int DoPhanGiai;
	string kieuPhanGiai;
	float Gia;
public:
	ManHinh()
	{
		DoPhanGiai = 0;
		Gia = 0;
	}
	virtual void Nhap()
	{
		cout << "Nhap Ma Man Hinh:";
		cin >> MaManHinh;
		cout << "Hang San Xuat: ";
		cin >> HangSanXuat;
		cout << "Do Phan Giai(1- HD, 2- FullHD): ";
		cin >> DoPhanGiai;
		if (DoPhanGiai == 1)
		{
			kieuPhanGiai = "HD";
		}
		else if (DoPhanGiai == 2)
		{
			kieuPhanGiai = "FullHD";
		}
		else;
	}
	virtual void Xuat()
	{
		cout << "Man Hinh: " << MaManHinh << " " << HangSanXuat << " " << kieuPhanGiai << " " << Gia;
	}
	int GetLoaiManHinh()
	{
		return DoPhanGiai;
	}
	int GetGiaManHinh()
	{
		return Gia;
	}
};
class HD :public ManHinh
{
public:
	HD()
	{
		DoPhanGiai = 1;
		Gia = 200;
	}
	void Nhap()
	{
		ManHinh::Nhap();
	}
};
class FullHD :public ManHinh
{
	int ChongLoa;
public:
	FullHD()
	{
		ChongLoa = -1;
		DoPhanGiai = 2;
	}
	FullHD(const int )
	{
		ChongLoa = 1;
		DoPhanGiai = 2;
	}
	void Nhap()
	{
		ManHinh::Nhap();
		cout << "Loai Man Hinh Chong Loa(1), Man Hinh Khong Chong Loa(0): ";
		cin >> ChongLoa;
		if (ChongLoa == 1)
		{
			Gia = 500;
		}
		else Gia = 300;
	}
	void Xuat()
	{
		ManHinh::Xuat();
		if (ChongLoa == 1)
		{
			cout << "Chong Loa" << endl;
		}
		else;
	}
};
///////////////////////////////////////////////

class Vo
{
protected:
	string MaVo;
	int LoaiVo;
	string KieuVo;
	string Hang;
	string KieuMauSac;
	float Gia;
	int mausac;
public:
	Vo()
	{
		LoaiVo = 0;
		Gia = 0;
		mausac = 0;
	}
	virtual void Nhap()
	{
		cout << "Nhap Loai Vo SmartPhone(1-loai nhom, 2 - loai nhua)";
		cin >> LoaiVo;
		cout << "Nhap Ma Vo: ";
		cin >> MaVo;
		if (mausac == 1)
		{
			KieuMauSac = "Do";
		}
		else if (mausac == 2)
		{
			KieuMauSac = "Den";
		}
		else if (mausac == 3)
		{
			KieuMauSac = "Xanh";
		}
	}
	virtual void Xuat()
	{
		cout << "Vo SmartPhone: " << MaVo << " " << KieuVo << " " << Hang << " " << KieuMauSac << " " << Gia << endl;
	}
	int GetLoaiVo()
	{
		return LoaiVo;
	}
	float GetGiaVo()
	{
		return Gia;
	}
};
class VoNhom :public Vo
{
public:
	VoNhom()
	{
		LoaiVo = 1;
		KieuVo = "Nhom";
		Hang = "Black";
		Gia = 400;
	}
	void Nhap()
	{
		Vo::Nhap();
		cout << "Nhap Mau Vo(1-Do, 2-Den): ";
		cin >> mausac;
	}
};
class VoNhua :public Vo
{
public:
	VoNhua()
	{
		LoaiVo = 2;
		KieuVo = "Nhua";
		Hang = "White";
		Gia = 200;
	}
	void Nhap()
	{
		Vo::Nhap();
		cout << "Nhap Mau Vo(1-Do, 2-Den, 3-Xanh): ";
		cin >> mausac;
	}
};
////////////////////////////////////////////
class SmartPhone
{
protected:
	string MaDT;
	int dongDT;
	string KieuDT;
	float Gia;
	CPU *cpu;
	ManHinh *m1;
	Vo *v1;
	float HeSo;
public:
	SmartPhone()
	{
		cpu = new CPU;
		m1 = new ManHinh;
		v1 = new Vo;
		dongDT = 0;
		Gia = 0;
		HeSo = 0;
	}
	virtual void Nhap()
	{
		cout << "Nhap Ma SmartPhone: ";
		cin >> MaDT;
		if (dongDT == 1)
		{
			KieuDT = "Venus";
		}
		else if (dongDT == 2)
		{
			KieuDT = "Mars";
		}
		else if (dongDT == 3)
		{
			KieuDT = "Jupiter";
		}
		else;
		cpu->Nhap();
		m1->Nhap();
		v1->Nhap();
	}
	virtual void Xuat()
	{
		cout << "SmartPhone: " << MaDT << " " << KieuDT << " " << Gia << endl;
		cpu->Xuat();
		m1->Xuat();
		v1->Xuat();
	}
	virtual void GiaDT()
	{
		Gia = (cpu->GetGiaCPU() + m1->GetGiaManHinh() + v1->GetGiaVo())*HeSo;
	}
	int GetDongDT()
	{
		return dongDT;
	}
};
class Venus :public SmartPhone
{
public:
	Venus()
	{
		dongDT = 1;
		KieuDT = "Venus";
		HeSo = 1.3;
	}
	void Nhap()
	{
		SmartPhone::Nhap();
		if (cpu->GetLoaiCPU() == 1)
			cpu = new Alpha;
		else if (cpu->GetLoaiCPU() == 2)
			cpu = new Beta;
		m1 = new FullHD;
		v1 = new VoNhom;
	}
};
class Mars :public SmartPhone
{
public:
	Mars()
	{
		dongDT = 2;
		KieuDT = "Mars";
		m1 = new FullHD;
		v1 = new VoNhom;
		HeSo = 1.5;
	}
	void Nhap()
	{
		SmartPhone::Nhap();
		if (cpu->GetLoaiCPU() == 1)
			cpu = new Alpha;
		else if (cpu->GetLoaiCPU() == 2)
			cpu = new Beta;
		else if (cpu->GetGiaCPU() == 3)
			cpu = new Gamma;
	}
};
class Jupiter :public SmartPhone
{
public:
	Jupiter()
	{
		dongDT = 3;
		KieuDT = "Jupiter";
		cpu = new Gamma;
		m1 = new FullHD(1);
		v1 = new VoNhom;
		HeSo = 1.7;
	}
	void Nhap()
	{
		SmartPhone::Nhap();
	}
};
//////////////////////////////////
class CongTyDT
{
	int soluongDT;
	SmartPhone** p;
public:
	CongTyDT()
	{
		soluongDT = 0;
		p = new SmartPhone * [100];
	}
	void Nhap()
	{

		cout << "Nhap So luong SmartPhone: ";
		cin >> soluongDT;
		for (int i = 0; i < soluongDT; i++)
		{
			int loai = 0;
			cout << "Nhap Dong SmartPhone(1- dong Venus,2- dong Mars,3- Jupiter):";
			cin >> loai;
			if (loai == 1)
				p[i] = new Venus;
			else if (loai == 2)
				p[i] = new Mars;
			else if (loai == 3)
				p[i] = new Jupiter;
			else;
			p[i]->Nhap();
		}
	}
	void Xuat()
	{
		for (int i = 0; i < soluongDT; i++)
		{
			p[i]->GiaDT();
			p[i]->Xuat();
		}
	}
};
int main()
{
	CongTyDT d1;
	d1.Nhap();
	d1.Xuat();
}