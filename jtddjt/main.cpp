#include <iostream>

using namespace std;
int m[20] = {31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int a,b,c;
    while (cin >> a >> b >> c){
        int ans = 0;
        if ((a% 4 == 0 && a % 100 != 0 ) || a % 400 == 0) m[1] = 29;
        for(int i = 0; i<b-1 ; i++){
            ans += m[i];
        }
        ans += c;
        cout << ans << endl;
        m[1] = 28;
    }


}
