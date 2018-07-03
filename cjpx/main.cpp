// 多组数据
#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
struct node {
    string name;
    int s;
    int id;
};
vector<node> V;
bool cmp1(node x1,node x2){
    if (x1.s == x2.s){
        return x1.id < x2.id;
    }
    return x1.s < x2.s;
}
bool cmp0(node x1,node x2){
    if (x1.s == x2.s){
        return x1.id < x2.id;
    }
    return x1.s > x2.s;
}
int main()
{
    int t,p;
    while (cin >> t >> p){
    V.clear();

    node x;
    for (int i = 1; i<=t ;i++){
        cin >> x.name >> x.s;

        x.id = i;
        V.push_back(x);
    }
    if (p){
        sort(V.begin(),V.end(),cmp1);
    }
    else {
        sort(V.begin(),V.end(),cmp0);
    }
    for (int i = 0; i<V.size() ;i++){
        cout <<V[i].name <<" " <<V[i].s<< endl;
    }
    }
    return 0;
}
