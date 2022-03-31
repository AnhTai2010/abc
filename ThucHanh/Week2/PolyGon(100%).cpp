// Hackerrank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
constexpr auto n = 1000;
constexpr auto Pi = 3.14;
using namespace std;
class Diem
{
    float x = 0, y = 0;
public:
    Diem();
    Diem(float, float);
    void Nhap();
    void Xuat();
    float getx() { return this->x; }
    float gety() { return this->y; }
    float setx(float k) { return this->x = k; }
    float sety(float k) { return this->y = k; }
};
class DaGiac
{
    Diem* d = new Diem[n];
    int sldiem = n;
public:
    DaGiac();
    DaGiac(int, Diem*);
    void Nhap(Diem*);
    float DienTich(Diem*);
};
int main() {
    int sl = 1;
    Diem* t = new Diem[n];
    DaGiac polygon(sl, t);
    polygon.Nhap(t);
    float S = polygon.DienTich(t);
    cout << S;
    return 0;
}
Diem::Diem()
{
}
Diem::Diem(float hd, float td)
{
    hd = this->x;
    td = this->y;
}
void Diem::Nhap()
{
    cin >> x >> y;
}
void Diem::Xuat()
{
    cout << "(" << x << "," << y << ")" << endl;
}
DaGiac::DaGiac()
{
}
DaGiac::DaGiac(int y, Diem* k)
{
    do {
        cin >> y;
    } while (y <= 2);
    sldiem = y;
    k = new Diem[sldiem];
}
void DaGiac::Nhap(Diem* k)
{
    for (int i = 0; i < sldiem; i++)
    {
        k[i].Nhap();
    }
}
float DaGiac::DienTich(Diem* k)
{
    float S = 0;
    int j = sldiem - 1;
    for (int i = 0; i < sldiem; i++)
    {
        S = S + ((k[j].getx() + k[i].getx()) * (k[j].gety() - k[i].gety()));
        j = i;
    }
    return abs(S / 2);
}