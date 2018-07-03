// 提前break需要 输入读干净了!!!!!
#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
set<string> S;
set<string> T;
int main()
{
    int n,m;
    while (cin >> n){
        S.clear();
        string s;
        for (int i = 1; i<=n; i++){
            cin >> s;
            S.insert(s);
        }
        int ans = 0;
        T = S;
        cin >> m;
        for (int i = 1; i<=m ;i++){
            cin >> s;
            if (ans == -1) continue;
            if (T.count(s)!=0){
                T.erase(s);
            }
            if (T.size() == 0){
                ans++;
                T = S;
                T.erase(s);
            }
            if (T.size() == 0){
                ans = -1;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
