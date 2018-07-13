
#include <bits/stdc++.h>
using namespace std;
vector <int> w;
vector <int> y;
int main()
{

    w.clear();
    y.clear();
    for (int i = 2; i<= 60 ; i++){
        int tmp  =0;
        for (int j = 1 ; j<i ; j++){
            if (i % j == 0) tmp+= j;
        }
        if (tmp == i){
            w.push_back(i);
        }
        else if (tmp > i ){
            y.push_back(i);
        }
    }
    cout <<"E: ";
    for (int i = 0; i<w.size(); i++){
        printf("%d%c",w[i],i + 1 == w.size() ? '\n' : ' ' );
    }
    cout <<"G: ";
    for (int i = 0; i<y.size(); i++){
        printf("%d%c",y[i],i + 1 == y.size() ? '\n' : ' ' );
    }
    return 0;
}
