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
    float STamGiac(Diem, Diem, Diem);
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
    DaGiac polygon(sl,t);
    polygon.Nhap(t);
    float S = polygon.DienTich(t);
    cout << "Dien tich:" << S;
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
float Diem::STamGiac(Diem A, Diem B, Diem C)
{
    return (0.5 * abs((C.x - A.x) * (B.y - A.y) - (B.x - A.x) * (C.y - A.y))); // dien tich tam giac
}
void Diem::Nhap()
{
    cin >> x >> y;
}
void Diem::Xuat()
{
    cout << "(" << x << "," << y << ")"<<endl;
}
DaGiac::DaGiac()
{
}
DaGiac::DaGiac(int y, Diem* k)
{
    cin >> y;
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
    for (int i = 0; i < sldiem-1; i++)
    {
        S = S + k[i].STamGiac(k[0], k[i], k[i + 1]);
    }
    return S;
}