#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static int TongTien = 0;
static int TongTriTue = 0;
static int TongSucManh = 0;
class Hero
{
    int Tien;
    int TriTue;
    int SucManh;
public:
    Hero();
    Hero(int, int, int);
    void Nhap();
    void Xuat();
    int GetTien();
    int GetTriTue();
    int GetSucManh();
    int SetTien(int);
    int SetTriTue(int);
    int SetSucManh(int);
};
class Gate
{
public:
    Gate();
    virtual void Nhap();
    virtual void DieuKien() = 0;
};
class BusinessGate :
    public Gate
{
    int DonGia;
    int SoHang;
public:
    BusinessGate();
    void Nhap();
    void DieuKien();
};
class IntelligentGate :
    public Gate
{
    int TriTueCauHoi;
public:
    IntelligentGate();
    void Nhap();
    void DieuKien();
};
class PowerGate :
    public Gate
{
    int SucDungSy;
public:
    PowerGate();
    void Nhap();
    void DieuKien();
};
class GiaiCuuCongChua
{
    int SoCong;
    Gate** Cong;
    Hero h1;
public:
    GiaiCuuCongChua();
    void Nhap();
    void Xuat();
};
int main() {
    GiaiCuuCongChua k1;
    k1.Nhap();
    k1.Xuat();
    return 0;
}
Hero::Hero()
{
    Tien = 0;
    TriTue = 0;
    SucManh = 0;
}
Hero::Hero(int x, int y, int z)
{
    Tien = x;
    TriTue = y;
    SucManh = z;
}
void Hero::Nhap()
{
    cin >> Tien >> TriTue >> SucManh;
}
void Hero::Xuat()
{
    if (Tien < 0 || TriTue < 0 || SucManh < 0)
    {
        cout << -1;
    }
    else
    {
        cout << Tien << " " << TriTue << " " << SucManh;
    }

}
int Hero::GetTien()
{
    return this->Tien;
}
int Hero::GetSucManh()
{
    return this->SucManh;
}
int Hero::GetTriTue()
{
    return this->TriTue;
}
int Hero::SetTien(int x)
{
    return Tien = x;
}
int Hero::SetSucManh(int x)
{
    return SucManh = x;
}
int Hero::SetTriTue(int x)
{
    return TriTue = x;
}
Gate::Gate()
{

}
void Gate::Nhap()
{

}
void Gate::DieuKien()
{

}
BusinessGate::BusinessGate()
{
    DonGia = 0;
    SoHang = 0;
}
void BusinessGate::Nhap()
{
    Gate::Nhap();
    cin >> DonGia >> SoHang;

}
void BusinessGate::DieuKien()
{
    TongTien += (DonGia * SoHang);
    Gate::DieuKien();
}
IntelligentGate::IntelligentGate()
{
    TriTueCauHoi = 0;
}
void IntelligentGate::Nhap()
{
    cin >> TriTueCauHoi;
    Gate::Nhap();
}
void IntelligentGate::DieuKien()
{
    if (TriTueCauHoi > TongTriTue)
    {
        TongTriTue = TriTueCauHoi;
    }
    else
    {
        TongTriTue = TongTriTue;
    }
    Gate::DieuKien();
}
PowerGate::PowerGate()
{
    SucDungSy = 0;
}
void PowerGate::Nhap()
{
    cin >> SucDungSy;
    Gate::Nhap();
}
void PowerGate::DieuKien()
{
    TongSucManh += SucDungSy;
    Gate::DieuKien();
}
GiaiCuuCongChua::GiaiCuuCongChua()
{
    Cong = new Gate * [100];
    SoCong = 0;
}
void GiaiCuuCongChua::Nhap()
{
    cin >> SoCong; // Nhap so cong
    int loai = 0;
    for (int i = 0; i < SoCong; i++)
    {
        cin >> loai;
        if (loai == 1)
        {
            Cong[i] = new BusinessGate;
        }
        else if (loai == 2)
        {
            Cong[i] = new IntelligentGate;
        }
        else if (loai == 3)
        {
            Cong[i] = new PowerGate;
        }
        Cong[i]->Nhap();
        Cong[i]->DieuKien();
    }
    h1.Nhap();
}
void GiaiCuuCongChua::Xuat()
{
    Hero h2;
    if (h1.GetTriTue() >= TongTriTue)
    {
        h2.SetTriTue(h1.GetTriTue());
    }
    else {
        h2.SetTriTue(-1);
    }
    h2.SetSucManh(h1.GetSucManh() - TongSucManh);
    h2.SetTien(h1.GetTien() - TongTien);
    h2.Xuat();
}