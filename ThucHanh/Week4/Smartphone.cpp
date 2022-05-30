#include <iostream>
#include<string>
using namespace std;
class CPU
{
protected:
	string MaCPU;
	string kieuCPU;
	string hang;
	int core;
	float Xungnhip;
	int Gia;
public:
	CPU()
	{
		MaCPU = " ";
		kieuCPU = " ";
		hang = " ";
		core = 0;
		Xungnhip = 0;
		Gia = 0;
	}
	void SetMaCPU()
	{
		cin.ignore();
		cin >> MaCPU;
	}
	void Xuat()
	{
		cout << MaCPU << " " << kieuCPU << " " << hang << " " << core << "core " << Xungnhip << "GHz " << Gia << endl;
	}
	int GetGia()
	{
		return Gia;
	}
};
class Alpha :public CPU
{
public:
	Alpha()
	{
		kieuCPU = "Alpha";
		hang = "Black";
		core = 2;
		Xungnhip = 1.8;
		Gia = 200;
	}
};
class Beta :public CPU
{
public:
	Beta()
	{
		kieuCPU = "Beta";
		hang = "Black";
		core = 4;
		Xungnhip = 2.46;
		Gia = 400;
	}
};
class Gamma :public CPU
{
public:
	Gamma()
	{
		kieuCPU = "Gamma";
		hang = "White";
		core = 4;
		Xungnhip = 2.6;
		Gia = 600;
	}
};
//////////////////////////////////////
class ManHinh
{
protected:
	string MaManHinh;
	string HangSanXuat;
	string KieuPhanGiai;
	int Gia;
public:
	ManHinh()
	{
		MaManHinh = " ";
		HangSanXuat = " ";
		Gia = 0;
	}
	void SetMaManHinh(string x)
	{
		//cin.ignore();
		//cin >> MaManHinh;
		MaManHinh = x;
	}
	void SetHangSanXuat(string x)
	{
		//cin.ignore();
		//cin >> HangSanXuat;
		HangSanXuat = x;
	}
	void Xuat()
	{
		cout << MaManHinh << " " << HangSanXuat << " " << KieuPhanGiai << " " << Gia;
	}
	int GetGia()
	{
		return Gia;
	}
};
class HD :public ManHinh
{
public:
	HD()
	{
		KieuPhanGiai = "HD";
		Gia = 200;
	}
	void Xuat()
	{
		ManHinh::Xuat();
		cout << endl;
	}
};
class FullHD :public ManHinh
{
	int ChongLoa;
public:
	FullHD()
	{
		KieuPhanGiai = "FullHD";
		ChongLoa = 0;
		Gia = 300;
	}
	FullHD(int x)
	{
		x = 1;
		KieuPhanGiai = "FullHD";
		ChongLoa = x;
		Gia = 500;

	}
	void SetChongLoa()
	{
		cin >> ChongLoa;
	}
	void Xuat()
	{
		ManHinh::Xuat();
		if (ChongLoa)
			cout << " Chong Loa" << endl;
		else
			cout << endl;
	}
};
//////////////////////////////////////////////
class Vo
{
protected:
	string MaVo;
	string KieuVo;
	string Hang;
	int Gia;
	int MauSac;
	string KieuMauSac;
public:
	Vo()
	{
		MauSac = 0;
		MaVo = " ";
		KieuVo = " ";
		Hang = " ";
		Gia = 0;
		KieuMauSac = " ";
	}
	void SetMaVo()
	{
		cin.ignore();
		cin >> MaVo;
	}
	void SetMauSac()
	{
		cin >> MauSac;
		if (MauSac == 1)
			KieuMauSac = "Do";
		else if (MauSac == 2)
			KieuMauSac = "Den";
		else if (MauSac == 3)
			KieuMauSac = "Xanh";
	}
	void Xuat()
	{
		cout << MaVo << " " << KieuVo << " " << Hang << " " << KieuMauSac << " " << Gia << endl;
	}
	int GetGia()
	{
		return Gia;
	}
};
class VoNhom :public Vo
{
public:
	VoNhom()
	{
		KieuVo = "Nhom";
		Gia = 400;
		Hang = "Black";
	}
	void SetMauSac()
	{
		cout << "Chon mau vo: Do(1), Den(2):";
		Vo::SetMauSac();
	}
};
class VoNhua :public Vo
{
public:
	VoNhua()
	{
		KieuVo = "Nhua";
		Gia = 200;
		Hang = "White";
	}
	void SetMauSac()
	{
		cout << "Chon mau vo: Do(1), Den(2) , Xanh(3):";
		Vo::SetMauSac();
	}
};
//////////////////////////////////////////
class SmartPhone
{
protected:
	string MaDT;
	string KieuDT;
	int Gia;
	Vo* Vodt;
	CPU* cp1;
	ManHinh* mh;
	int LoaiCPU;
	int LoaiManHinh;
	int LoaiVo;
	float heso;
	string mamanhinh, hangsanxuat;
public:
	SmartPhone()
	{
		MaDT = " ";
		KieuDT = " ";
		LoaiCPU = 0;
		LoaiManHinh = 0;
		LoaiVo = 0;
		Gia = 0;
		Vodt = new Vo;
		cp1 = new CPU;
		mh = new ManHinh;
		heso = 0;
	}
	virtual void Nhap()
	{
		cout << "Nhap Ma Dien Thoai:";
		cin >> MaDT;
	}
	void Xuat()
	{
		cout << "Smartphone: " << MaDT << " " << KieuDT << " " << Gia << endl;
		cout << "CPU: "; cp1->Xuat();
		cout << "ManHinh: "; mh->Xuat();
		cout << "\n Vo smartphone: "; Vodt->Xuat();
	}
	void SetLoaiCPU()
	{
		cin >> LoaiCPU;
	}
	void SetLoaiManHinh()
	{
		cin >> LoaiManHinh;
	}
	void SetLoaiVo()
	{
		cin >> LoaiVo;
	}
	void GiaDT()
	{
		Gia = (cp1->GetGia() + mh->GetGia() + Vodt->GetGia())*heso;
	}
};
class Venus :public SmartPhone
{
public:
	Venus()
	{
		KieuDT = "Venus";
		heso = 1.3;
	}
	void Nhap()
	{
		SmartPhone::Nhap();

		cout << "Loai CPU: (1-Alpha, 2-Beta):";
		Venus::SetLoaiCPU();
		if (LoaiCPU == 1)
			cp1 = new Alpha;
		else if (LoaiCPU == 2)
			cp1 = new Beta;
		cout << "Nhap Ma CPU:";
		cp1->SetMaCPU();

		cout << "Nhap Ma Man Hinh:";
		cin.ignore();
		cin >> mamanhinh;
		cout << "Nhap Hang San Xuat";
		cin >> hangsanxuat;
		cout << "Nhap Do Phan Giai:(1-HD, 2-FullHD):";
		Venus::SetLoaiManHinh();
		if (LoaiManHinh == 1)
			mh = new HD;
		else if (LoaiManHinh == 2)
		{
			int cl = 0;
			cout << "Chong Loa ? 1- Co, 0 -Khong";
			cin >> cl;
			if (cl)
				mh = new FullHD(1);
			else
				mh = new FullHD;
		}
		mh->SetMaManHinh(mamanhinh);
		mh->SetHangSanXuat(hangsanxuat);
		cout << " Loai Vo SmartPhone(1-Nhom , 2-Nhua): ";
		cin >> LoaiVo;
		if (LoaiVo == 1)
		{
			Vodt = new VoNhom;
			cout << "Nhap Ma Vo: ";
			Vodt->SetMaVo();
			cout << "Mau Vo(1-Do, 2-Den): ";
			Vodt->SetMauSac();
		}
		else if (LoaiVo == 2)
		{
			Vodt = new VoNhua;
			cout << "Nhap Ma Vo: ";
			Vodt->SetMaVo();
			cout << "Mau Vo(1-Do, 2-Den, 3-Xanh): ";
			Vodt->SetMauSac();
		}
	}
};
class Mars :public SmartPhone
{
public:
	Mars()
	{
		KieuDT = "Mars";
		heso = 1.5;
	}
	void Nhap()
	{
		SmartPhone::Nhap();
		cout << "Loai CPU: (1-Alpha, 2-Beta , 3-Gamma):";
		Mars::SetLoaiCPU();
		if (LoaiCPU == 1)
			cp1 = new Alpha;
		else if (LoaiCPU == 2)
			cp1 = new Beta;
		else if (LoaiCPU == 3)
			cp1 = new Gamma;
		cout << "Nhap Ma CPU:";
		cp1->SetMaCPU();

		cout << "Nhap Ma Man Hinh:";
		cin.ignore();
		cin >> mamanhinh;
		cout << "Nhap Hang San Xuat";
		cin >> hangsanxuat;
		int cl = 0;
		cout << "Chong Loa ? 1- Co, 0 -Khong";
		cin >> cl;
		if (cl)
			mh = new FullHD(1);
		else
			mh = new FullHD;
		mh->SetMaManHinh(mamanhinh);
		mh->SetHangSanXuat(hangsanxuat);
		Vodt = new VoNhom;
		cout << "Nhap Ma Vo: ";
		Vodt->SetMaVo();
		cout << "Mau Vo(1-Do, 2-Den): ";
		Vodt->SetMauSac();
	}
};
class Jupiter :public SmartPhone
{
public:
	Jupiter()
	{
		KieuDT = "Jupiter";
		heso = 1.8;
	}
	void Nhap()
	{
		SmartPhone::Nhap();
		cp1 = new Gamma;
		cp1->SetMaCPU();
		cout << "Nhap Ma Man Hinh:";
		cin.ignore();
		cin >> mamanhinh;
		cout << "Nhap Hang San Xuat";
		cin >> hangsanxuat;
		mh = new FullHD(1);
		mh->SetMaManHinh(mamanhinh);
		mh->SetHangSanXuat(hangsanxuat);
		Vodt = new VoNhom;
		cout << "Nhap Ma Vo: ";
		Vodt->SetMaVo();
		cout << "Mau Vo(1-Do, 2-Den): ";
		Vodt->SetMauSac();
	}
};
class DSSmartPhone
{
	int Loai;
	int soluongdt;
	SmartPhone** phone;
public:
	DSSmartPhone()
	{
		soluongdt = 0;
		Loai = 0;
		phone = new SmartPhone*[100];
	}
	void Nhap()
	{
		cout << "Nhap so luong smartphone: ";
		cin >> soluongdt;
		for (int i = 0; i < soluongdt; i++)
		{
			cout << "Dong Smartphone(1- Venus, 2-Mars, 3-Jupiter):";
			cin >> Loai;
			if (Loai == 1)
			{
				phone[i] = new Venus;
			}
			else if (Loai == 2)
			{
				phone[i] = new Mars;
			}
			else if (Loai == 3)
			{
				phone[i] = new Jupiter;
			}
			phone[i]->Nhap();
		}
	}
	void Xuat()
	{
		for (int i = 0; i < soluongdt; i++)
		{
			phone[i]->GiaDT();
			phone[i]->Xuat();
		}
	}
};
int main()
{
	DSSmartPhone TGGD;
	TGGD.Nhap();
	TGGD.Xuat();
	return 0;
}