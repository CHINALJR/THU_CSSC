#include <iostream>

using namespace std;
int l;
long long sum;
long long a[1123456];
int main()
{
    int n;
    while (cin >> n){
        for (int i = 1 ; i<= n; i++){
            cin >> a[i];
        }
        l = 1;
        long long ans = a[1];
        sum = a[1];
        for (int i = 2 ; i<=n ;i++){
            sum += a[i];
            ans = max(ans,sum);
            while (sum < 0 && l <= i){
                sum -= a[l];
                l++;
                if (l != i) ans = max(ans,sum);
            }

        }
        cout << ans << endl;
    }
    return 0;
}
