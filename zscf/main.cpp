// dp 推导
// 打表找规律
#include <bits/stdc++.h>
const long long mod = 1000000000;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
long long dp[1000111];
/*long long dp[1000111][30];
long long poww[30];
inline long long solve(long long x,int t){
    if (dp[x][t] != -1) return dp[x][t];
    long long tmpans = 0;
    for (int i = 0;x - i * poww[t] >= 0;i++){
        tmpans = (tmpans + solve(x-i*poww[t],t-1)) % mod;
    }
    return dp[x][t] = tmpans;

}
*/
int main()
{
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3;i<=1000111 ;i++){
        if (dp[i]%2 == 0){
            dp[i] = (dp[i-1] + dp[i/2]) % mod;
        }
        else {
            dp[i] = dp[i-1] % mod;
        }
    }
    long long N;
    while (cin >> N){
        cout << dp[N]<<endl;
    }

    return 0;
}
