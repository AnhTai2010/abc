// Hackerrank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<string>
using namespace std;
class DongHo
{
    int gio, phut, giay;
public:
    DongHo();
    void Nhap();
    void Xuat();
    long GiosangGiay();
    DongHo GiaysangGio(DongHo);
    DongHo Chithi(DongHo, int);
    DongHo overload(DongHo, string);
    DongHo operator+( int);
    DongHo operator-( int);
    DongHo operator++();
    DongHo operator--();
};
int main() {
    
    DongHo clock1 ,temp1, boo;
    clock1.Nhap();
    //clock1.Xuat();
    //cout << endl << endl;
    int n = 0;
    cin >> n;
    string t;
    //operator p;
   /* DongHo clk = clock1.Chithi(clock1, n);
    DongHo boo = boo.GiaysangGio(clk);*/ //Bai1
    temp1 = clock1;
    for (int i = 0; i < n; i)
    {
        cin >> t;
        temp1 = temp1.overload(temp1, t);
        boo = temp1;
        i++;
    } //Bai2
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
    return abs(gio * 3600 + phut * 60 + giay);
}
DongHo DongHo::GiaysangGio(DongHo k)
{
    DongHo kq;
    long S = k.GiosangGiay();
    while (S > 86400)
    {
        S = S - 86400;
    } 
    kq.gio = S / 3600;
    kq.phut = (S%3600) / 60;
    kq.giay = S%3600%60;
    return kq;
}
void DongHo::Xuat()
{
    cout << gio << "h " << phut << "p " << giay << "s";
}
DongHo DongHo::Chithi(DongHo k, int n)
{
    int x = 0;
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
            k.giay = k.giay - x;
        }
        cin >> n;
    }
    if (n == -1)
        return k;
    return k;
}
DongHo DongHo::overload(DongHo k, string n)
{
    DongHo kq;
    int temp = 0;
    if (n == "+")
    {
        cin >> temp;
        kq = k.operator+(temp);
        //kq.Xuat();
        //cout << endl;
    }
    else if (n == "-")
    {
        cin >> temp;
        kq = k.operator-(temp);
        //kq.Xuat();
        //cout << endl;
    }
    else if (n == "++")
    {
        kq = k.operator++();
        //kq.Xuat();
        //cout << endl;
    }
    else if (n == "--")
    {
        kq = k.operator--();
        //kq.Xuat();
        //cout << endl;
    }
    return kq;
}
DongHo DongHo::operator+( int x)
{
    DongHo kq, temp;
    temp.giay = this->GiosangGiay() + x;
    kq = this->GiaysangGio(temp);
    return kq;
}
DongHo DongHo::operator-( int x)
{
    DongHo kq, temp;
    temp.giay = this->GiosangGiay() - x;
    kq = this->GiaysangGio(temp);
    return kq;
}
DongHo DongHo::operator++()
{
    DongHo kq, temp;
    temp.giay = this->GiosangGiay() + 1;
    kq = this->GiaysangGio(temp);
    return kq;
}
DongHo DongHo::operator--()
{
    DongHo kq, temp;
    temp.giay = this->GiosangGiay() - 1;
    kq = this->GiaysangGio(temp);
    return kq;
}