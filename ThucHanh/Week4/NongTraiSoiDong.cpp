#include <iostream>
#include<string>
using namespace std;
static int solan = 0;
static int sovat = 3;
class GiaSuc
{
    int soluong;
protected:
    string tengiasuc;
    string tiengkeu;
    int milk;
public:
    GiaSuc();
    virtual void Nhap();
    virtual void Keu();
    void Xuat();
    virtual void LitSua() = 0;
};
GiaSuc::GiaSuc()
{
    soluong = 0;
    milk = 0;
    tengiasuc = "";
    tiengkeu = "";
}
void GiaSuc::Nhap()
{
    cin >> soluong;
}
void GiaSuc::Xuat()
{
    cout << "\n" << tengiasuc << ": " << milk;
}
void GiaSuc::LitSua()
{
    milk = milk * solan * soluong;
}
void GiaSuc::Keu()
{
    for (int i = 0; i < soluong; i++)
    {
        if (i < soluong - 1)
            cout << tiengkeu << ",";
        else
            cout << tiengkeu;
    }
}
////////////////////////
class Bo :public GiaSuc
{
public:
    void Nhap();
    void Keu();
    void LitSua();
};
void Bo::Nhap()
{
    GiaSuc::Nhap();
    tengiasuc = "Bo";
}
void Bo::Keu()
{
    tiengkeu = "Booo";
    GiaSuc::Keu();
}
void Bo::LitSua()
{
    milk = 10;
    GiaSuc::LitSua();
}
/////////////////////////
class Cuu :public GiaSuc
{
public:
    void Nhap();
    void Keu();
    void LitSua();
};
void Cuu::Nhap()
{
    GiaSuc::Nhap();
    tengiasuc = "Cuu";
}
void Cuu::Keu()
{
    tiengkeu = "Beee";
    GiaSuc::Keu();
}
void Cuu::LitSua()
{
    milk = 5;
    GiaSuc::LitSua();
}
/////////////////////////
class De :public GiaSuc
{
public:
    void Nhap();
    void Keu();
    void LitSua();
};
void De::Nhap()
{
    GiaSuc::Nhap();
    tengiasuc = "De";
}
void De::Keu()
{
    tiengkeu = "Eeee";
    GiaSuc::Keu();
}
void De::LitSua()
{
    milk = 8;
    GiaSuc::LitSua();
}
/////////////////////////
int main()
{
    GiaSuc** NongTrai = new GiaSuc * [100];
    NongTrai[0] = new Bo;
    NongTrai[1] = new Cuu;
    NongTrai[2] = new De;
    for (int i = 0; i < sovat; i++)
    {
        NongTrai[i]->Nhap();
    }
    cin >> solan;
    for (int i = 0; i < sovat; i++)
    {
        NongTrai[i]->Keu();
        if (i < sovat - 1)
            cout << ",";
        NongTrai[i]->LitSua();
    }
    for (int i = 0; i < sovat; i++)
    {
        NongTrai[i]->Xuat();
    }
    return 0;
}