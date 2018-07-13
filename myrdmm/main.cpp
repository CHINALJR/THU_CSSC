#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
map<string,int> S;

int solve(string s){
    for (int i = 0; i<s.length()-3;i++){
        if (s[i] == '2' && s[i+1] == '0' && s[i+2] == '1' && s[i+3] == '2')
            return S[s] = 0;
    }
    if (S.count(s) != 0 ) return S[s];
    int g = mod;
    string tmp = s;
    S[s] = g;
    for (int i = 0 ; i<s.length()-1 ; i++){
        tmp = s;
        swap(tmp[i],tmp[i+1]);
        g = min(g,solve(tmp)+1);
    }
    return S[s] = g;
}
int main()
{
    int N;
    while (cin >> N){
        S.clear();
        string s;
        cin >> s;
        int ans = solve(s);
        if ( ans >= mod )
            cout << -1 << endl;
        else{
            cout << ans << endl;
        }
    }
    return 0;
}
