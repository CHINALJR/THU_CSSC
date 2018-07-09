#include <bits/stdc++.h>

using namespace std;
struct node {
    int l,r;
}E[111];
bool cmp(node a,node b){
    if (a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}
int main()
{
    int L,m;
    while (cin >> L >> m){
        for (int i = 1; i<=m ;i++){
            cin >> E[i].l >> E[i].r;
        }
        sort(E+1,E+m+1,cmp);
        int l = 0;
        int r = 0;
        int ans = 0;
        for (int i = 1; i<=m;){
            l = E[i].l;
            r = E[i].r;

            while (E[i+1].l<=r + 1 && i < m){
                r = max(E[i+1].r , r);
                i++;
            }
            ans += r - l + 1;
            i++;
        }
        ans = L - ans;
        cout << ans + 1 << endl;
    }
    return 0;
}
