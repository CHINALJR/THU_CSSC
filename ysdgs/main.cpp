#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
long long solve(long long x){
    long long ans = 0 ;
    if ( x==0 ) return 0;
    long long g = sqrt(x);
    for (int i = 1; i<=g ;i++){
        if (x % i == 0) ans+=2;
    }
    if (g * g == x) ans--;
    return ans;
}
int main()
{
    int N;
    cin >> N;
    while (N--){
        long long x;
        cin >> x;
        cout << solve(x)<<endl;
    }
    return 0;
}
