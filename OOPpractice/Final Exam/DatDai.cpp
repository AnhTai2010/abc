#include "DatDai.h"
DatDai::DatDai()
{
	sogiaychungnhan = " ";
	sothuadat = 0;
	sotobando = 0;
	diachi = " ";
	dientich = 0;
	ngaycap = " ";
	giathue1m2 = 0;
	songuoisohuu = 1;
	human = new NguoiSoHuuDat*[100];
	kieudat = " ";
	//human = new NguoiSoHuuDat;
}
void DatDai::Nhap()
{
	int temp = 1;
	cout << "Nhap so giay chung nhan: ";
	cin >> sogiaychungnhan;
	cout << "Nhap so nguoi so huu dat: ";
	cin >> songuoisohuu;

	for (int i = 0; i < songuoisohuu; i++)
	{
		cout << "Nhap thong tin nguoi so huu thu " << temp << ":\n";
		human[i] = new NguoiSoHuuDat;
		human[i]->Nhap();
		temp++;
	}

	cout << "Nhap so thua dat: ";
	cin >> sothuadat;
	cout << "Nhap so to ban do: ";
	cin >> sotobando;
	cout << "Dia chi thua dat: ";
	cin.ignore();
	getline(cin, diachi);
	cout << "Dien tich thua dat:";
	cin >> dientich;
	cout << "Nhap ngay cap: ";
	cin >> ngaycap;
	cout << "Thue dong hang nam/1m2: ";
	cin >> giathue1m2;
}
void DatDai::Xuat()
{
	cout << "So giay chung nhan: " << sogiaychungnhan << endl;
	cout << "Thong tin nguoi so huu dat: " << endl;
	int temp = 1;
	for (int i = 0; i < songuoisohuu; i++)
	{
		cout << "Nguoi thu " << temp << ":\n";
		human[i]->Xuat();
		temp++;
	}
	cout << "So thua dat: " << sothuadat << endl;
	cout << "so to ban do: " << sotobando << endl;
	cout << "Dia chi: " << diachi << endl;
	cout << "Dien tich thua dat: " << dientich << endl;
	cout << "Ngay cap:" << ngaycap << endl;
	cout << "Thue hang nam tren 1m2: " << giathue1m2 << endl;
	float S = this->TongThueHangNam();
	cout << "Tong thue tren dat hang nam: " << S << endl;
}
float DatDai::TongThueHangNam()
{
	return giathue1m2 * dientich;
}
string DatDai::GetKieuDat()
{
	return kieudat;
}