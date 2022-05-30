#include <iostream>
#include<string>

using namespace std;
static float Pi = 3.14;
static float TongDienTichChaiVo = 0;
static float Tongluongnuoc = 0;
static float Luongnuocconlai = 0;
class Chai
{
protected:
    float DienTich;
    float Thetich;
public:
    Chai()
    {
        DienTich = 0;
        Thetich = 0;
    }
    virtual void Nhap();
    void Xuat();
    virtual void TinhDienTich() = 0;
    virtual void TinhTheTich() = 0;
};
void Chai::Nhap()
{

}
void Chai::Xuat()
{

}
/// <summary>
/// /////////////////////
/// </summary>
class HinhTru : public Chai
{
    float chieucao;
    float Rday;
public:
    HinhTru() {

        chieucao = 0;
        Rday = 0;
    }
    void Nhap()
    {
        cin >> chieucao >> Rday;
        Chai::Nhap();
    }
    void TinhDienTich()
    {
        DienTich = 2 * Pi * chieucao * Rday;
        TongDienTichChaiVo += DienTich;
    }
    void TinhTheTich()
    {
        Thetich = chieucao * Rday * Rday * Pi;
        Tongluongnuoc += Thetich;
    }
};
/// <summary>
/// ///////////////////////////
/// </summary>
class HinhHop : public Chai
{
    float chieucao;
    float chieudai;
    float chieurong;
public:
    HinhHop()
    {
        chieucao = 0;
        chieudai = 0;
        chieurong = 0;
    }
    void Nhap()
    {
        cin >> chieucao >> chieudai >> chieurong;
        Chai::Nhap();
    }
    void TinhDienTich()
    {
        DienTich = 2 * chieucao * (chieudai + chieurong) + 2 * chieudai * chieurong;
        TongDienTichChaiVo += DienTich;
    }
    void TinhTheTich()
    {
        Thetich = chieucao * chieudai * chieurong;
        Tongluongnuoc += Thetich;
    }
};
/// <summary>
/// ///////////////////////////
/// </summary>
class LapPhuong : public Chai
{
    float dodaicanh;
public:
    LapPhuong()
    {
        dodaicanh = 0;
    }
    void Nhap()
    {
        cin >> dodaicanh;
        Chai::Nhap();
    }
    void TinhDienTich()
    {
        DienTich = dodaicanh * dodaicanh * 6;
        TongDienTichChaiVo += DienTich;
    }
    void TinhTheTich()
    {
        Thetich = dodaicanh * dodaicanh * dodaicanh;
        Tongluongnuoc += Thetich;
    }
};
///////////////////////
int main()
{
    int n;
    do
    {
        cin >> n;
    } while (n < 0);
    Chai** ChiPheo = new Chai * [100];
    int loai = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> loai;
        if (loai == 1)
        {
            ChiPheo[i] = new HinhTru;
        }
        else if (loai == 2)
        {
            ChiPheo[i] = new HinhHop;
        }
        else if (loai == 3)
        {
            ChiPheo[i] = new LapPhuong;
        }
        else;
        ChiPheo[i]->Nhap();
    }
    for (int i = 0; i < n; i++)
    {
        ChiPheo[i]->TinhDienTich();
        ChiPheo[i]->TinhTheTich();
        ChiPheo[i]->Xuat();
    }
    Luongnuocconlai = Tongluongnuoc * 10 / 100;
    cout << "Dien tich chai vo: " << TongDienTichChaiVo << endl;
    cout << "Luong nuoc tren mat dat: " << Luongnuocconlai << endl;
    return 0;
}