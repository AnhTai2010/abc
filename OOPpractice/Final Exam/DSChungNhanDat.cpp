#include "DSChungNhanDat.h"
DSChungNhanDat::DSChungNhanDat()
{
	dat = new DatDai * [100];
	loaidat = 0;
	realyear = 2022;
	soluongdatcapphat = 0;
}
void DSChungNhanDat::Nhap()
{
	cout << "Nhap so luong dat cap phat: ";
	cin >> soluongdatcapphat;
	for (int i = 0; i < soluongdatcapphat; i++)
	{
		cout << "Nhap loai dat (1-Dat Nong Nghiep, 2-Dat Phi Nong Nghiep): ";
		cin >> loaidat;
		if (loaidat == 1)
		{
			dat[i] = new DatNongNghiep;
		}
		else if (loaidat == 2)
		{
			dat[i] = new DatXayNha;
		}
		dat[i]->Nhap();
	}
}
DatDai DSChungNhanDat::ThueNhieuNhat()
{
	DatDai *temp = new DatDai;
	for (int i = 0; i < soluongdatcapphat-1; i++)
	{
		if (dat[i]->TongThueHangNam() > dat[i + 1]->TongThueHangNam())
			temp = dat[i];
		else
			temp = dat[i + 1];
	}
	return *temp;
}
void DSChungNhanDat::HetHanSuDung()
{
	//DatNongNghiep* hethan = new DatNongNghiep[100];
	//for (int i = 0; i < soluongdatcapphat; i++)
	//{
	//	if (dat[i]->GetKieuDat() == "DatNongNghiep")
	//	{
	//		hethan[i] = (DatNongNghiep&)dat[i];
	//	}
	//	if (hethan[i].GetHSD() - realyear < 0)
	//		hethan[i].Xuat();
	//}
}
void DSChungNhanDat::Xuat()
{
	cout << "Dat co thue cao nhat: ";
	DatDai d1 = this->ThueNhieuNhat();
	d1.Xuat();
	//cout << "Danh sach dat het han su dung:";
	//this->HetHanSuDung();
}