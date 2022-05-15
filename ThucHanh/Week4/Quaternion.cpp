#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<istream>
using namespace std;
class Quaternion
{
    int a, b, c, d;
public:
    Quaternion();
    Quaternion(int, int, int, int);
    friend istream& operator>>(istream&, Quaternion&);
    friend ostream& operator<<(ostream&, Quaternion);
    Quaternion operator+(Quaternion);
    Quaternion operator-(Quaternion);
};
int main() {
    Quaternion a, b;
    cin >> a >> b;
    cout << a + b;
    cout << endl;
    cout << a - b;
    system("pause");
    return 0;
}
Quaternion::Quaternion()
{
    a = b = c = d = 0;
}
Quaternion::Quaternion(int i, int j, int k, int l)
{
    a = i;
    b = j;
    c = k;
    d = l;
}
istream& operator>>(istream& is, Quaternion& t)
{
    is >> t.a >> t.b >> t.c >> t.d;
    return is;
}
ostream& operator<<(ostream& os, Quaternion t)
{
    os << "(" << t.a << "," << t.b << "," << t.c << "," << t.d << ")";
    return os;
}
Quaternion Quaternion::operator+(Quaternion t)
{
    return Quaternion(a + t.a, b + t.b, c + t.c, d + t.d);
}
Quaternion Quaternion::operator-(Quaternion t)
{
    return Quaternion(a - t.a, b - t.b, c - t.c, d - t.d);
}