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
    Diem Tinhtien(float, float , Diem);
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
    cout << "(" << x << "," << y << ")"<<endl;
}
TamGiac::TamGiac()
{
    this->dodaitinhtien = 0;
    this->goctinhtien = 0;
}
TamGiac::TamGiac(Diem A, Diem B, Diem C)
{
    Diem temp1, temp2, temp3;
    float x = 0,y = 0;
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
Diem TamGiac::Tinhtien(float x, float y , Diem k)
{

    float sinx = sin(Pi / convertinttorad(x)); // convert to standard pi/int

    float doi = sinx * y; // canh doi = sinx * canh huyen

    float ke = sqrt(y * y - doi * doi); // canh ke

    k.setx(k.getx() + ke);
    k.sety(k.gety() + doi);
    return k;
}
float TamGiac::convertinttorad(float t)
{
    return 180 / t;
}