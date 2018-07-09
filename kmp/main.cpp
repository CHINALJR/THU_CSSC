#include <iostream>

using namespace std;
const int maxn = 1000;
const int maxm = 1000;
int nex[maxm];
void getnex(){
    nex[0] = -1
                                                                                                                                                                            }}}})
}
int KmpSearch(char* s, char* p)
{
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    while (i < sLen && j < pLen)
    {
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == pLen)
        return i - j;
    else
        return -1;
}

int main()
{
    string s,p;
    cout << "Hello world!" << endl;
    return 0;
}
