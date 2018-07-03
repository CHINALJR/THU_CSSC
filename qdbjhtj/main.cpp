#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;

int main()
{
    double pi = acos(-1.0);
    double x1,y1,z1,x2,y2,z2;
    while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 ){

    double ans1 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2) );
    double ans2 = 4.0 /3.0 * pi * ans1 * ans1 * ans1;
    printf("%.3f %.3f\n",ans1,ans2);
    }
    return 0;
}
