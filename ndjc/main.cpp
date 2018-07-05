#include <iostream>

using namespace std;
long long ans[30];
int main()
{
    ans[1] = 1;
    for (int i = 2 ; i<= 20 ; i++){
        ans[i] = ans[i-1] * i;
    }
    int N;
    while (cin >> N){
        cout << ans[N] << endl;
    }
    return 0;
}
