#include <iostream>

using namespace std;

int main()
{
    int a0,a1,p,q,k;
    while (cin >> a0 >> a1  >> p >> q  >> k){
        int ans = 0;
        a0 %= 10000;
        a1 %= 10000;
        p %= 10000;
        q %= 10000;
        while (k-1){
            ans = ( p * a1 + q * a0 ) % 10000;
            a0 = a1;
            a1 = ans;
            k--;
        }
        cout << ans << endl;
    }
    return 0;
}
