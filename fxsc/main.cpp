#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
int t[20] = {-1,2,5,8,11,14,18,21,25};
int main()
{
    string s;
    while (cin >> s){
        int l = s.length();
        int ans = 0;
        int last = -1;
        for (int i = 0; i< l ;i++){
            int tmp = s[i]-'a';
            int gg = 0;
            for (int j = 0; j<=8 ; j++){
                if (tmp > t[j]){
                    continue;
                }
                gg = j ;
                break;
            }

            if (last == gg) ans+=2;
            ans += (-t[gg-1] + tmp);
            last = gg;
        }
        cout << ans << endl;
    }
    return 0;
}
