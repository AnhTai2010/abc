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
class TamGiac
{
    float goctinhtien; // goc tinh tien 
    float dodaitinhtien; // do dai tinh tien
public:
    TamGiac();
    TamGiac(Diem, Diem, Diem);
    Diem Tinhtien(float, float, Diem);
    float convertinttorad(float);
};
int main() {
    Diem A, B, C;
    TamGiac t(A, B, C);
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
TamGiac::TamGiac()
{
    this->dodaitinhtien = 0;
    this->goctinhtien = 0;
}
TamGiac::TamGiac(Diem A, Diem B, Diem C)
{
    Diem temp1, temp2, temp3;
    float x = 0, y = 0;
    A.Nhap();
    B.Nhap();
    C.Nhap();
    cin >> x >> y;// nhap goc tinh tien =x , do dai tinh tien =y
    temp1 = Tinhtien(x, y, A);
    temp2 = Tinhtien(x, y, B);
    temp3 = Tinhtien(x, y, C);
    temp1.Xuat();
    temp2.Xuat();
    temp3.Xuat();
}
Diem TamGiac::Tinhtien(float x, float y, Diem k)
{
    float temp = x;
    float sinx = sin(Pi / convertinttorad(x)); // convert to standard pi/int

    float doi = sinx * y; // canh doi = sinx * canh huyen

    float ke = sqrt(y * y - doi * doi); // canh ke
    if ((temp < 90 && temp > 0))
    {
        k.setx(k.getx() + ke);
        k.sety(k.gety() + doi);// truong hop 0< x <= 90
    }
    else if (temp > 90 && temp < 180)
    {
        k.sety(k.gety() + doi);
        k.setx(k.getx() - ke);  // truong hop 90 < x <= 180 
    }
    else if (temp > 180 && temp < 270)
    {
        k.sety(k.gety() - doi);
        k.setx(k.getx() - ke); // truong hop 180 < x <= 270
    }
    else if (temp == 90)
    {
        k.setx(roundf((k.getx() + ke) * 10000) / 10000);
        k.sety(k.gety() + doi); // x == 90 tinh tien(x,y+tt)
    }
    else if (temp == 180)
    {
        k.setx(k.getx() - y); // x == 180 tinh tien(x-tt,y)
        k.sety(k.gety());
    }
    else if (temp == 270)
    {
        k.setx(k.getx());          // x == 270 tinh tien(x,y-tt)
        k.sety(k.gety() - y);
    }
    else if (temp == 360 || temp == 0)
    {
        k.setx(k.getx() + y);
        k.sety(k.gety());  //x == 360 tinh tien (x+tt,y)
    }
    else
    {
        k.sety(k.gety() - doi);
        k.setx(k.getx() + ke); // 270 < x <= 360
    }
    return k;
}
float TamGiac::convertinttorad(float t)
{
    if (t >= 0 && t <= 90)
        return 180 / t;
    else if (t > 90 && t <= 180)
        return 180 / (180 - t);
    else if (t > 180 && t <= 270)
        return 180 / (t - 180);
    else
        return 180 / (360 - t);
}