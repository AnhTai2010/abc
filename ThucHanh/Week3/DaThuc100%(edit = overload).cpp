// Hackerrank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
class DonThuc
{
    int heso;
    int somu;
public:
    DonThuc();
    void Nhap();
    void Xuat();
    int getheso();
    int getsomu();
    int setheso(int);
    int setsomu(int);
    DonThuc operator+(const DonThuc);
    DonThuc operator-(const DonThuc);
    DonThuc operator*(const DonThuc);
};
class DaThuc
{
    int bac;
    DonThuc* dt;
public:
    DaThuc();
    DaThuc(int);
    void Nhap();
    void Xuat();
    DaThuc operator+(const DaThuc);
    DaThuc operator-(const DaThuc);
    DaThuc operator*(const DaThuc);
};

using namespace std;

int main() {
    int x, y, z;
    DaThuc kq;
    do
    {
        cin >> x;
    } while (x < 0);
    DaThuc d1(x);
    d1.Nhap();
    d1.Xuat();
    cout << endl << "\n";
    do {
        cin >> y;
    } while (y < 0);
    DaThuc d2(y);
    d2.Nhap();
    d2.Xuat();
    cout << endl << endl;
    cin >> z;               //string z;
    if (z == 1)             //cin.ignore;
    {                       //getline(cin,z);
        kq = d1 + d2;       // if(z =="+") same z == 1
        kq.Xuat();          // if(z == "-") same z ==2
    }                       // if(z == "*") same z == 3
    else if (z == 2)
    {
        kq = d1 - d2;
        kq.Xuat();
    }
    else if (z == 3)
    {
        kq = d1 * d2;
        kq.Xuat();
    }
    else 
    return 0;
}
DonThuc::DonThuc()
{
    heso = 0;
    somu = 0;
}
void DonThuc::Nhap()
{
    cin >> heso;
}
void DonThuc::Xuat()
{
    cout << heso << "x^" << somu;
}
int DonThuc::getheso()
{
    return this->heso;
}
int DonThuc::getsomu()
{
    return this->somu;
}
int DonThuc::setheso(int x)
{
    return this->heso = x;
}
int DonThuc::setsomu(int x)
{
    return this->somu = x;
}
DonThuc DonThuc::operator+(const DonThuc x)
{
    DonThuc kq;
    kq.heso = this->heso + x.heso;
    kq.somu = this->somu;
    return kq;
}
DonThuc DonThuc::operator-(const DonThuc x)
{
    DonThuc kq;
    kq.heso = this->heso - x.heso;
    kq.somu = this->somu;
    return kq;
}
DonThuc DonThuc::operator*(const DonThuc x)
{
    DonThuc kq;
    kq.heso = this->heso * x.heso;
    kq.somu = this->somu *x.somu;
    return kq;
}
DaThuc::DaThuc()
{
    bac = 0;
    dt = new DonThuc[1000];
}
DaThuc::DaThuc(int x)
{
    bac = x;
    dt = new DonThuc[x+1];
}
void DaThuc::Nhap()
{
    for (int i = 0; i <= bac; i++)
    {
        dt[i].Nhap();
        dt[i].setsomu(i);
    }
}
void DaThuc::Xuat()
{
    for (int i = 0; i <= bac; i++)
    {
        if (dt[i].getheso() != 0)
        {
            dt[i].Xuat();
            if (dt[i + 1].getheso() >= 0 && i < bac)
                cout << "+";
        }
    }
}
DaThuc DaThuc::operator+(const DaThuc x)
{
    DaThuc kq;
    DonThuc temp;
    if (this->bac > x.bac)
    {
        kq.bac = bac;

        for (int i = 0; i <= bac; i++)
        {
            kq.dt[i] = dt[i];
            for (int j = 0; j <= x.bac; j++)
            {
                if (this->dt[i].getsomu() == x.dt[j].getsomu())
                {
                    temp = dt[i] + x.dt[j];
                    kq.dt[i] = temp;
                }
                else continue;
            }

        }
    }
    else if(this->bac < x.bac)
    {
        kq.bac = x.bac;
        for (int i = 0; i <= x.bac; i++)
        {
            kq.dt[i] = x.dt[i];
            for (int j = 0; j <= bac; j++)
            {
                if (this->dt[j].getsomu() == x.dt[i].getsomu())
                {
                    temp = dt[j] + x.dt[i];
                    kq.dt[i] = temp;
                }
                else continue;
            }

        }
    }
    return kq;
}
DaThuc DaThuc::operator-(const DaThuc x)
{
    DaThuc kq;
    DonThuc temp;
    if (this->bac > x.bac)
    {
        kq.bac = bac;
        for (int i = 0; i <= bac; i++)
        {
            kq.dt[i] = dt[i];
            for (int j = 0; j <= x.bac; j++)
            {
                if (this->dt[i].getsomu() == x.dt[j].getsomu())
                {
                    temp = dt[i] - x.dt[j];
                    kq.dt[i] = temp;
                }
                else continue;
            }

        }
    }
    else if(this->bac < x.bac)
    {
        kq.bac = x.bac;
        for (int i = 0; i <= x.bac; i++)
        {
            kq.dt[i] =  x.dt[i];
            kq.dt[i].setheso(-kq.dt[i].getheso());
            for (int j = 0; j <= bac; j++)
            {
                if (this->dt[j].getsomu() == x.dt[i].getsomu())
                {
                    temp = dt[j] - x.dt[i];
                    kq.dt[i] = temp;
                }
                else continue;
            }
        }

    }
    return kq;
}
DaThuc DaThuc::operator*(const DaThuc x)
{
    DaThuc kq(bac+x.bac);
    int tempbac = 0;
    for (int k = 0; k <= kq.bac; k++)
    {
        int temp = 0 ;
        for (int i = 0; i <= bac; i++)
        {
            for (int j = 0; j <= x.bac; j++)
            {
                if (i + j == k)
                {
                    temp = temp + (dt[i].getheso() * x.dt[j].getheso());
                }
            }
        }
        kq.dt[k].setheso(temp);
        kq.dt[k].setsomu(tempbac);
        tempbac++;
    }
    return kq;
}