#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
long long cal(long long x,long long y , long long  k){
    if (y == 1){
        if (x<k) return x;
        int ans = 0;
        while (x >= k ){
            ans = 0;
            while (x!=0){
                ans += x%k;
                x/=k;
            }
            x = ans;
        }
        return ans;
    }
    if (y%2==0){
        return cal(cal(x,y/2,k)*cal(x,y/2,k),1,k);
    }
    else {
        return cal(cal(x,y/2,k)*cal(x,y/2,k)*cal(x,1,k),1,k);
    }
}
int main()
{
    long long x,y,k;
    while (cin >> x >> y >> k){
        cout << cal(x,y,k) << endl;
    }
    return 0;
}
