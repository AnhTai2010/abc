#include <iostream>
#include<string>
using namespace std;
static int TongSoSanPham = 0;
static int TongSoNgayLamViec = 0;

class NhanVien
{
protected:
    string HoTen;
    float Luong = 0;
public:
    virtual void Nhap();
    void Xuat();
    virtual void TinhLuong() = 0;
};
void NhanVien::Nhap()
{
    cin >> HoTen;
}
void NhanVien::Xuat()
{
    cout << HoTen << ":" << Luong << endl;
}
class NhanVienSanXuat :public NhanVien
{
protected:
    float LuongCoBan;
    int SoSanPham;
public:
    NhanVienSanXuat();
    void Nhap();
    void TinhLuong();
};
NhanVienSanXuat::NhanVienSanXuat()
{
    LuongCoBan = 0;
    SoSanPham = 0;
}
void NhanVienSanXuat::Nhap()
{
    NhanVien::Nhap();
    cin >> LuongCoBan;
    cin >> SoSanPham;
    TongSoSanPham += SoSanPham;
}
void NhanVienSanXuat::TinhLuong()
{
     Luong = (float)LuongCoBan + SoSanPham * 5;
}
class NhanVienVanPhong :public NhanVien
{
protected:
    int SoNgayLamViec;
public:
    NhanVienVanPhong();
    void Nhap();
    void TinhLuong();
};
NhanVienVanPhong::NhanVienVanPhong()
{
    SoNgayLamViec = 0;
}
void NhanVienVanPhong::Nhap()
{
    NhanVien::Nhap();
    cin >> SoNgayLamViec;
    TongSoNgayLamViec += SoNgayLamViec;
}
void NhanVienVanPhong::TinhLuong()
{
    Luong = (float)SoNgayLamViec * 100;
}
class Sep :public NhanVien
{
public:
    void Nhap();
    void TinhLuong();
};
void Sep::Nhap()
{
    NhanVien::Nhap();
}
void Sep::TinhLuong()
{
     Luong = (float)100 + TongSoSanPham * 2 + TongSoNgayLamViec * 40;
}

int main()
{
    int n;
    cin >> n;
    int loai = 0;
    NhanVien** DaCap = new NhanVien * [100];
    for (int i = 0; i < n; i++)
    {
        cin >> loai;
        if (loai == 1)
        {
            DaCap[i] = new NhanVienSanXuat;
        }
        else if (loai == 2)
        {
            DaCap[i] = new NhanVienVanPhong;
        }
        else if (loai == 3)
        {
            DaCap[i] = new Sep;
        }
        else;
        DaCap[i]->Nhap();

    }
    for (int i = 0; i < n; i++)
    {
        DaCap[i]->TinhLuong();
        DaCap[i]->Xuat();
    }

}