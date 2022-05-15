#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<istream>
using namespace std;
class MYINT
{
    int x;
public:
    MYINT();
    MYINT(int);
    friend istream& operator>>(istream&, MYINT);
    friend ostream& operator<<(ostream&, MYINT);
    MYINT operator+(MYINT);
    MYINT operator-(MYINT);
    MYINT operator*(MYINT);
};
int main() {
    MYINT a(4), b(5);
    cout << (a + b) * a;
    cout << endl;
    cout << a * b;
    system("pause");
    return 0;
}
MYINT::MYINT()
{
    x = 0;
}
MYINT::MYINT(int k)
{
    x = k;
}
istream& operator>>(istream& is, MYINT t)
{
    is >> t.x;
    return is;
}
ostream& operator<<(ostream& os, MYINT t)
{
    os << t.x;
    return os;
}
MYINT MYINT::operator+(MYINT t)
{
    return MYINT(x - t.x);
}
MYINT MYINT::operator-(MYINT t)
{
    return MYINT(x + t.x);
}
MYINT MYINT::operator*(MYINT t)
{
    return MYINT(x * t.x);
}