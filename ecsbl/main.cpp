#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
struct node{
    int l,r;
    char c;
}T[3000];
void print(int x){
    if (x<0) return;
    print(T[x].l);
    if (T[x].c != '#' ) cout <<T[x].c<<" ";
    print(T[x].r);

}
string s;
int nowT;
int nows;
void solve (){
    if (nows >= s.length()) return;
    int tmp = nowT;
    T[tmp].c = s[nows];
    nows++;
    nowT++;
    if (T[tmp].c == '#'){
        T[tmp].l = -1;
        T[tmp].r = -1;
        return ;
    }
    T[tmp].l = nowT;
    solve();
    T[tmp].r = nowT;
    solve();
}
int main()
{
    while (cin >> s){
        nowT = 0;
        nows = 0;
        solve();
        print(0);
        cout << endl;
    }
    return 0;
}
