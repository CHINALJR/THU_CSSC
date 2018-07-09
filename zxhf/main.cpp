#include <iostream>
struct node {
    int id;
    long long  x,c;
}E[1123456];
const long long inf = 0x3f3f3f3f3f3f3f3f;
bool cmp(node a,node b){
    return a.x < b.x;
}
using namespace std;
int s,t;
int main()
{
    int l1,l2,l3,l4,l5,l6;
    while (cin >> l1 >> l2 >> l3 >> l4 >> l5 >> l6){
        cin >> s >> t;
        int N;
        cin >> N;
        E[1].id = 1;
        E[1].x = 0;
        E[1].c = inf;
        for (int i = 2; i<=N; i++){
            int l;
            cin >> l;
            E[i].id = i;
            E[i].x = l;
            E[i].c = inf;

        }
        E[s].c = 0;
        for (int i = s+1; i<=t ;i++){
            for (int j = s ; j<i; j++){
                long long tmp = E[i].x - E[j].x;
                long long ans = 0;
                if (tmp>0 && tmp <= l1) ans = l4;
                else if (tmp <=l2) ans = l5;
                else if (tmp <=l3) ans = l6;
                else ans = inf;
                E[i].c = min(E[i].c, E[j].c + ans);
            }
        }
        cout << E[t].c << endl;
    }
    return 0;
}
