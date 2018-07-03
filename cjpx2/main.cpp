#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
struct node {
    int x;
    int y;
}s[111];
bool cmp(node a,node b){
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
int main()
{
    int N;
    while (cin >> N){
        for (int i = 1; i<=N; i++){
            cin >> s[i].x >> s[i].y;
        }
        sort(s+1,s+N+1,cmp);
        for (int i = 1; i<=N ;i++){
            cout << s[i].x <<" " << s[i].y << endl;
        }
    }
    return 0;
}
