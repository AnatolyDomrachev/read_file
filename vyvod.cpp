#include <iostream>

using namespace std;

int main()
{
long double a,b,c,d,e,f;
a = 1234.342516354876342;
b = 354768372546382.47620958670295847;
c = 356476532875.23546534219;
d = 46347629.24354657291;
e = 45237294875637.25364875968235124;
f = 25465342638756.6765423122435467;

cout.setf(ios::fixed);
cout.precision(15);
//cout.width(15);
cout << a << endl;//"\t" << b << "\t" << c << "\n" << d << "\t" << e << "\t" << f;

cout << "1234.342516354876342";

return 0;
}

