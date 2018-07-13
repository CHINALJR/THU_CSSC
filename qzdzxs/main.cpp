#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
int maxx = 1000001;
int minn = -1000001;
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    int N;
    while (cin >> N){
        int ans1 = maxx;
        int ans2 = minn;
        for (int i = 1 ; i <= N; i++){
            int s;
            cin >> s;
            ans1 = min(ans1,s);
            ans2 = max(ans2,s);
        }
        cout << ans2 <<" " << ans1 << endl;
    }
    return 0;
}
