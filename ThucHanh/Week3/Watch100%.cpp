#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class DongHo
{
    int gio, phut, giay;
public:
    DongHo();
    void Nhap();
    void Xuat();
    long GiosangGiay();
    DongHo GiaysangGio(int);
    DongHo Chithi(DongHo, int);
};
int main() {
    DongHo clock1, boo;
    clock1.Nhap();
    int n = 0;
    cin >> n;
    DongHo clk = clk.GiaysangGio(clock1.GiosangGiay());
    boo = clk.Chithi(clk, n);
    boo.Xuat();
    return 0;
}
DongHo::DongHo()
{
    gio = phut = giay = 0;
}
void DongHo::Nhap()
{
    cin >> gio >> phut >> giay;
}
long DongHo::GiosangGiay()
{
    gio = abs(gio);
    phut = abs(phut);
    giay = abs(giay);
    return (gio * 3600 + phut * 60 + giay);
}
DongHo DongHo::GiaysangGio(int S)
{
    DongHo kq;
    while (S > 86400)
    {
        S = S - 86400; //S > 24h => S- 1 day
    }
    kq.gio = S / 3600; // S <=24h convert 1h = 3600s
    kq.phut = (S % 3600) / 60; // convert 1p = 60s
    kq.giay = S - kq.gio * 3600 - kq.phut * 60; // convert to s
    return kq;
}
void DongHo::Xuat()
{
    cout << gio << "h " << phut << "p " << giay << "s";
}
DongHo DongHo::Chithi(DongHo k, int n)
{
    DongHo kq;
    int x = 0;
    k.giay = k.GiosangGiay();
    while (n != -1)
    {
        if (n == 1)
        {
            k.giay++;
        }
        else if (n == 2)
        {
            k.giay--;
        }
        else if (n == 3)
        {
            cin >> x;
            k.giay += x;
        }
        else if (n == 4)
        {
            cin >> x;
            k.giay -= x;
        }
        cin >> n;
    }
    if (n == -1)
    {
        return kq.GiaysangGio(k.giay);
    }
    return kq.GiaysangGio(k.giay);
}