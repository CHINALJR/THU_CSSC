#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    for (int i = 1 ; i<=9 ;i++){
        for (int j = 1; j<=9 ; j++){
            for (int k = 0; k<=9 ;k++){
                if (i*100 + j* 110 + k*12 == 532){
                    cout << i <<" " << j <<" " << k << endl;
                }
            }
        }
    }
    return 0;
}
