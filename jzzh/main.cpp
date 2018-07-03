#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
int l;
string div2(string s){
    if (s=="1"){
        l = 1;
        return "0";
    }
    string ans = "";
    int flag = 0;
    int flag2 = 0;
    for (int i = 0 ; i<l ; i++){
        int gg = flag*10 + (int)(s[i] - '0');
        flag = gg % 2;
        char tmp = (char)( gg / 2 + '0') ;
        if (tmp!='0'){
            flag2 = 1;
        }
        if (flag2)
            ans += tmp;
    }
    l = ans.length();
    return ans;
}
int main()
{
    string s;
    string res = "";
    while (cin >> s){
        res = "";
        l = s.length();
        if (s == "0")
        {
            cout <<0<<endl;
            continue;
        }
        while (s!="0"){
            if ((int)(s[l-1]-'0') % 2){
                res = "1" + res;
            }
            else {
                res = "0" + res;
            }
            s = div2(s);
        }
        cout << res << endl;
    }
    return 0;
}
