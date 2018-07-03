#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
int q[112345];
vector<int> G;
void init(){
    G.clear();
    memset(q,0,sizeof(q));
    for (int i = 2 ; i<=111111 ; i++){
        if (q[i] == 0){
            G.push_back(i);
            for (int j = 2 ; j*i <=111111 ; j++)
                q[j*i] = 0;
        }
    }
}
int main()
{
    long long x;
    init();
    while (cin >> x){
        int ans = 0;
        for (int i = 0; G[i]*G[i] <= x ; i++){
            while (x%G[i] == 0) {ans++;x/=G[i];}
        }
        if (x!=1) ans++;
        cout << ans << endl;
    }
    return 0;
}
