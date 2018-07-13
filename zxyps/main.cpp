#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
int sc[22];
int main()
{
    int M,N;
    while (cin >> M >> N){
        for (int i = 1 ; i<= N; i++){
            cin >> sc[i];
        }
        int ans = 30;
        for (int i = 0 ; i<(1<<N) ; i++){
            int tmp = 0;
            int tans = 0;
            int t = i;
            for (int j = 1; j<=N; j++){
                if ( t % 2 == 1) {
                    tmp++;
                    tans += sc[j];
                }
                t/=2;
            }
            if (tans == M){
                ans = min(ans,tmp);
            }
        }
        if (ans == 30 )
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
