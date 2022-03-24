// Lab2OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
constexpr auto n = 1000;
using namespace std;
class Chocsinh
{
    int stt;
    string ma;
    string HoTen;
    string NgaySinh;
    int Toan, Van, Anh;
public:
    Chocsinh();
    void Nhap();
    void Xuat();
    int Tong();
    int setstt(int);
};
class ArrayHocsinh
{
    int slhocsinh = n;
    Chocsinh* p = new Chocsinh[n];
public:
    ArrayHocsinh();
    ArrayHocsinh(Chocsinh*);
    void Nhap(int, Chocsinh*);
    void Xuat(Chocsinh*);
};
int main()
{
    Chocsinh *hs1 = new Chocsinh[n];
    int sl = 1;
    ArrayHocsinh mhs1(hs1);
    mhs1.Nhap(sl, hs1);
    mhs1.Xuat(hs1);
    return 0;
}
Chocsinh::Chocsinh()
{
    this->stt = 0;
    this->Toan = this->Van = this->Anh = 0;
}
int Chocsinh::setstt(int x)
{
    return this->stt = x;
}
void Chocsinh::Nhap()
{
    cin.ignore();
    getline(cin, ma);
    getline(cin, HoTen);
    getline(cin, NgaySinh);
    do
    {
        cin >> Toan >> Van >> Anh;
    } while (Toan < 0 || Toan>10 || Van < 0 || Van > 10 || Anh < 0 || Anh > 10);
}
void Chocsinh::Xuat()
{
    cout << "-" << endl;
    cout << "STT " << stt << ":" << endl;
    cout << "Thong tin hoc sinh:" << endl;
    cout << "Ma: " << ma << endl;
    cout << "Ho ten: " << HoTen << endl;
    cout << "Ngay sinh: " << NgaySinh << endl;
    cout << "Diem toan: " << Toan << endl;
    cout << "Diem van: " << Van << endl;
    cout << "Diem anh: " << Anh << endl;
}
int Chocsinh::Tong()
{
    return Toan + Van + Anh;
}
ArrayHocsinh::ArrayHocsinh()
{

}
ArrayHocsinh::ArrayHocsinh(Chocsinh*k)
{
    k = new Chocsinh[slhocsinh];
}
void ArrayHocsinh::Nhap(int sl, Chocsinh* k)
{
    int temp = 1;
    cin >> sl;
    slhocsinh = sl;
    for (int i = 0; i < slhocsinh; i++)
    {
        k[i].setstt(temp);
        k[i].Nhap();
        temp++;
    }
}
void ArrayHocsinh::Xuat(Chocsinh* k)
{
    int temp = 0;
    for (int i = 0; i < slhocsinh; i++)
    {
        if (k[i].Tong() > 15)
        {
            k[i].Xuat();
            temp++;
        }
    }
    while (temp == 0)
    {
        cout << "Khong co thi sinh co tong diem lon hon 15" << endl;
    }
        
}