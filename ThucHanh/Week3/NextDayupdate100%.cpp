// Hackerrank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
class NextDay
{
    int thang, nam;
    long ngay;
public:
    NextDay();
    void Nhap();
    void Xuat();
    bool CheckDate();
    long SumNgay();
};
int main()
{
    NextDay d1;
    d1.Nhap();
    //d1.Xuat();
    //cout << endl;
    int n = 0, x = 0;
    cin >> n;
    long temp = d1.SumNgay();
    //cout << temp << endl;
    while (n != 3)
    {
        if (n == 1)
        {
            cin >> x;
            temp += x;
            //cout << temp << endl;
        }
        else if (n == 2)
        {
            cin >> x;
            temp -= x;
            //cout << temp << endl;
        }
        else;
        cin >> n;
    }
    if (n == 3)
    {
        NextDay d2;
        d2.Nhap();
        int temp2 = d2.SumNgay();
        //cout << temp2 << endl;
        temp = abs(temp - temp2);
        //d2.Xuat();
        //cout << endl;
    }
    cout << temp;
    return 0;
}
NextDay::NextDay()
{
    thang = 0;
    nam = 0;
    ngay = 0;
}
void NextDay::Nhap()
{
     cin >> ngay >> thang >> nam;
     thang = abs(thang%12);
     if (thang == 0)
         thang = 12;
     nam = abs(nam);
     ngay = abs(ngay);
     if (this->CheckDate() == 0)
         ngay = 1;
}
void NextDay::Xuat()
{
    cout << ngay << "/" << thang << "/" << nam;
}
long NextDay::SumNgay()
{
    long S = (nam-1) * 365; // so ngay tieu chuan
    int Nhuan = 0;

    for (int j = 0; j < nam; j++)
    {
        if (j % 4 == 0 && j % 100 != 0)
            Nhuan++;
        else if (j % 400 == 0)
            Nhuan++;
        else
            Nhuan = Nhuan;
    }

    int temp = 0, T=0 , temp31 = 0, temp30 = 0, temp2 = 0;
    for (int i = 1; i < thang; i++)
    {
        if (i == 1 || i == 3 ||
            i == 5 || i == 7 ||
            i == 8 || i == 10 ||
            i == 12)
        {
            temp31 += 31;
        }
        else if (i == 4 || i == 6 ||
            i == 9 || i == 11)
        {
            temp30 += 30;
        }
        else if (i == 2)
        {
            if (nam % 4 == 0 && nam%100!=0)
                temp2 += 29;
            else if(nam%400==0)
                temp2+=29;
            else
                temp2 += 28;
        }
        else continue;
        temp = temp31 + temp30 + temp2;
    }
    T = temp + ngay;
    return S + Nhuan + T;
}
bool NextDay::CheckDate()
{
    bool check = 1;
    if (ngay < 1 || ngay > 31 || thang < 1 || thang > 12 || nam < 1)
    {
        check = 0;
    }
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
    {
        if (ngay > 30)
            check = 0;
    }
    if (thang == 2)
    {
        if (nam % 4 == 0)
        {
            if (ngay > 29)
                check = 0;
        }
        else
        {
            if (ngay > 28)
                check = 0;
        }
    }
    return check;
}