// Hackerrank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
constexpr auto n = 1000;
using namespace std;
class Diem
{
    float x, y;
public:
    Diem();
    void Nhap();
    void Xuat();
    float gethoanhdo();
    float gettungdo();
    float sethoanhdo(float);
    float settungdo(float);
};
class Lenh
{
    int slchithi = n;
    Diem Nika;
    int x = 0;
public:
    Lenh();
    Lenh(int, Diem&);
    Diem thucthi(Diem&);
};

int main() {
    Diem d1, d2;
    d1.Nhap();
    Lenh l1(n, d1);
    d2 = l1.thucthi(d1);
    d2.Xuat();
    return 0;
}
Diem::Diem()
{
    this->x = 0;
    this->y = 0;
}
void Diem::Nhap()
{
    cin >> x >> y;
}
void Diem::Xuat()
{
    cout << "(" << x << "," << y << ")" << endl;
}
float Diem::gethoanhdo()
{
    return this->x;
}
float Diem::gettungdo()
{
    return this->y;
}
float Diem::sethoanhdo(float t)
{
    return this->x = t;
}
float Diem::settungdo(float k)
{
    return this->y = k;
}
Lenh::Lenh()
{

}
Lenh::Lenh(int p, Diem& k)
{
    cin >> p;
    slchithi = p;
}
Diem Lenh::thucthi(Diem& k)
{


    int p = 0;
    float k_hoanh = 0;
    float k_tung = 0;
    for (int i = 0; i < slchithi; i++)
    {
        k_hoanh = k.gethoanhdo();
        k_tung = k.gettungdo();
        cin >> p;
        if (p == 1) // x2 toa do
        {
            k_hoanh *= 2;
            k_tung *= 2;
            k.sethoanhdo(k_hoanh);
            k.settungdo(k_tung);
        }
        else if (p == 2)
        {
            k_hoanh = 0;
            k_tung = 0;
            k.sethoanhdo(k_hoanh);
            k.settungdo(k_tung);
        }
        else if (p == 3)
        {
            float o = 0, d = 0;
            cin >> o;
            cin >> d;
            if (o == 0) // khi o = 0 -> tinh tien x (x+d,y)
            {

                k.sethoanhdo(k_hoanh + d);
                k.settungdo(k_tung);
                // k.Xuat();
            }
            else // o !=0 -> tinh tien y(x,y+d)
            {
                k.sethoanhdo(k_hoanh);
                k.settungdo(k_tung + d);
                //k.Xuat();
            }

        }
        else {
            //i--;
        }

    }
    return k;
}