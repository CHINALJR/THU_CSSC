#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
// 1 red -1 black
int byd[5] = {1,0,0};
int bxd[5] = {0,1,-1};
int yd[5] = {-1,1,0,0};
int xd[5] = {0,0,1,-1};
int xxd[5] = {2,2,-2,-2};
int xyd[5] = {-2,2,2,-2};
int xyxd[5] = {1,1,-1,-1};
int xyyd[5] = {-1,1,1,-1};
int mxd[9] = {1,1,2,2,-1,-1,-2,-2};
int myd[9] = {2,-2,1,-1,2,-2,1,-1};
int mjxd[9] = {0,0,1,1,0,0,-1,-1};
int mjyd[9] = {1,-1,0,0,1,-1,0,0};
int sxd[5] = {-1,-1,1,1};
int syd[5] = {1,-1,-1,1};
int N;
using namespace std;
struct node{
    int tmp[20][3];
    int xs;

    friend bool operator < (struct node const &a,struct node  const &b)
	{
        for (int i = 1;i<=N; i++){
            for (int j = 0; j<3;j++)
            {
                if (a.tmp[i][j] != b.tmp[i][j]){
                    return a.tmp[i][j] < b.tmp[i][j];
                }
            }
        }
        return a.xs < b.xs;
	}
};
map<node,int> M;
int check(node x){
    int flag1 = 0;
    int flag2 = 0;
    for(int i = 1; i<=N; i++){
        if (x.tmp[i][0] == 1 ) {
            flag1 = 1;
        }
        if (x.tmp[i][0] == -1 ) {
            flag2 = 1;
        }
    }
    if (flag1 == 0) return -1;
    else if (flag2 == 0) return 1;
    else return 0;
}
int num = 0;
set<node> inq;
void print(node x){
    for (int i = 1; i<=N; i++)
        cout << x.tmp[i][0] <<" " << x.tmp[i][1] <<" " <<x.tmp[i][2] <<" " << endl;
    cout << endl;
}
bool checkjj(node x){
    for (int i = 1; i<=N; i++){
        if (x.tmp[i][0] == -1) {
            for (int j = 1; j<=N; j++){
                if (x.tmp[i][0] > 0) {
                    if ()
                }
            }
        }
    }
    return false;
}
int solve(node x){
    int shu = 1;
    if (inq.count(x) != 0){
        return M[x];
    }
    int tmp = check(x);
    if (tmp == 1)
    {
        return M[x] = 1;
    }
    else if (tmp == -1) return M[x] = -1;
    inq.insert(x);
    node nextx = x;
// red
    for (int i = 1; i<=N; i++){
// 帅 将
        if (x.tmp[i][0] == x.xs * 1){
            // yidong
            for (int j = 0; j<4 ;j++){
                // nx ny
                int nx = x.tmp[i][1]+yd[j];
                int ny = x.tmp[i][2]+xd[j];
                if ((x.xs == 1) &&(nx > 5 || nx < 3 || ny < 0 || ny > 2)) continue;
                if ((x.xs == -1) &&(nx > 5 || nx < 3 || ny < 7 || ny > 9)) continue;
                int flag = 0 ;
                nextx = x;
                nextx.tmp[i][1] = nx;
                nextx.tmp[i][2] = ny;
                // gansi or zijiren
                for (int k = 1; k<=N; k++){
                    if (k == i )continue;
                    if (x.tmp[k][1] == nx && x.tmp[k][2] == ny  ){
                        // shiti
                        if (x.tmp[k][0] == 0) continue;
                        // zijiren
                        if (x.tmp[k][0] * x.xs > 0) {
                            flag = 1;
                            break;
                        }
                        // gansi
                        if (x.tmp[k][0] * x.xs < 0 ){
                            nextx.tmp[k][0] == 0;
                            break;
                        }
                    }
                }
                //zijiren
                if (flag) continue;
                //sousuo
                int ans = solve(nextx);
                if (ans == x.xs) {
                    return M[x] = x.xs;
                }
                if (ans == -x.xs){
                    return M[x] = -x.xs;
                }
            }
        }
// 兵 卒
        if (x.tmp[i][0] == x.xs * 2){
            // yidong
            for (int j = 0; j<3 ;j++){
                // nx ny
                int nx = x.tmp[i][1]+bxd[j];
                int ny = x.tmp[i][2]+x.xs*byd[j];
                if (nx > 8 || nx < 0 || ny < 0 || ny > 9) continue;
                int flag = 0 ;
                nextx = x;
                nextx.tmp[i][1] = nx;
                nextx.tmp[i][2] = ny;
                // gansi or zijiren
                for (int k = 1; k<=N; k++){
                    if (k == i )continue;
                    if (x.tmp[k][1] == nx && x.tmp[k][2] == ny  ){
                        // shiti
                        if (x.tmp[k][0] == 0) continue;
                        // zijiren
                        if (x.tmp[k][0] * x.xs > 0) {
                            flag = 1;
                            break;
                        }
                        // gansi
                        if (x.tmp[k][0] * x.xs < 0 ){
                            nextx.tmp[k][0] == 0;
                            break;
                        }
                    }
                }
                //zijiren
                if (flag) continue;
                //sousuo
                int ans = solve(nextx);
                 if (ans == x.xs) {
                    return M[x] = x.xs;
                }
                if (ans == -x.xs){
                    return M[x] = -x.xs;
                }
            }
        }
// 马
        if (x.tmp[i][0] == x.xs * 3){
            // yidong
            for (int j = 0; j<8 ;j++){
                // nx ny
                int nx = x.tmp[i][1]+mxd[j];
                int ny = x.tmp[i][2]+myd[j];
                if (nx > 8 || nx < 0 || ny < 0 || ny > 9) continue;
                int flag = 0 ;
                nextx = x;
                nextx.tmp[i][1] = nx;
                nextx.tmp[i][2] = ny;
                // gansi or zijiren
                for (int k = 1; k<=N; k++){
                    // shiti
                    if (x.tmp[k][0] == 0) continue;
                    if (k == i )continue;
                    // bmj
                    if (mjxd[j] + x.tmp[i][1] == x.tmp[k][1] && mjyd[j] + x.tmp[i][2] == x.tmp[k][2]) {
                        flag = 1;
                        break;
                    }
                    if (x.tmp[k][1] == nx && x.tmp[k][2] == ny  ){
                        // zijiren
                        if (x.tmp[k][0] * x.xs > 0) {
                            flag = 1;
                            break;
                        }
                        // gansi
                        if (x.tmp[k][0] * x.xs < 0 ){
                            nextx.tmp[k][0] == 0;
                            break;
                        }
                    }
                }
                //zijiren or bmj
                if (flag) continue;
                //sousuo
                int ans = solve(nextx);
                 if (ans == x.xs) {
                    return M[x] = x.xs;
                }
                if (ans == -x.xs){
                    return M[x] = -x.xs;
                }
            }
        }
// 车
        if (x.tmp[i][0] == 6){
            // yidong x
            for (int j = -8 ; j <= 8 ; j++){
                // nx ny
                int nx = x.tmp[i][1]+j;
                int ny = x.tmp[i][2];
                if (nx > 8 || nx < 0 || ny < 0 || ny > 9) continue;
                int flag = 0 ;
                nextx = x;
                nextx.tmp[i][1] = nx;
                nextx.tmp[i][2] = ny;
                int md = 0;
                // gansi or zijiren
                for (int k = 1; k<=N; k++){
                    // shiti
                    if (x.tmp[k][0] == 0) continue;
                    if (k == i )continue;
                    // bmj
                    if (x.tmp[k][1] > x.tmp[i][1] && ny == x.tmp[k][2] && x.tmp[k][1] < nx ) {
                        flag = 1;
                        break;
                    }
                    if (x.tmp[k][1] > nx && ny == x.tmp[k][2] && x.tmp[k][1] <  x.tmp[i][1]) {
                        flag = 1;
                        break;
                    }
                    if (x.tmp[k][1] == nx && x.tmp[k][2] == ny  ){
                        // zijiren
                        if (x.tmp[k][0] * x.xs > 0) {
                            flag = 1;
                            break;
                        }
                        // gansi
                        if (x.tmp[k][0] * x.xs < 0 ){
                            md = k;
                        }
                    }
                }
                //zijiren or bmj
                if (flag) continue;
                //sousuo
                if (md != 0){
                    nextx.tmp[md][0] = 0;
                }
                int ans = solve(nextx);
                 if (ans == x.xs) {
                    return M[x] = x.xs;
                }
                if (ans == -x.xs){
                    return M[x] = -x.xs;
                }
            }
            for (int j = -9; j<=9 ;j++){
                // nx ny
                int nx = x.tmp[i][1];
                int ny = x.tmp[i][2]+j;
                if (nx > 8 || nx < 0 || ny < 0 || ny > 9) continue;
                int flag = 0 ;
                nextx = x;
                nextx.tmp[i][1] = nx;
                nextx.tmp[i][2] = ny;
                int md = 0;
                // gansi or zijiren
                for (int k = 1; k<=N; k++){
                    // shiti
                    if (x.tmp[k][0] == 0) continue;
                    if (k == i )continue;
                    // bmj
                    if (x.tmp[k][2] > x.tmp[i][2] && nx == x.tmp[k][1] && x.tmp[k][2] < ny ) {
                        flag = 1;
                        break;
                    }
                    if (x.tmp[k][2] > nx && nx == x.tmp[k][1] && x.tmp[k][2] <  x.tmp[i][2]) {
                        flag = 1;
                        break;
                    }
                    if (x.tmp[k][1] == nx && x.tmp[k][2] == ny  ){
                        // zijiren
                        if (x.tmp[k][0] * x.xs > 0) {
                            flag = 1;
                            break;
                        }
                        // gansi
                        if (x.tmp[k][0] * x.xs < 0 ){
                            md = k;
                        }
                    }
                }
                //zijiren or bmj
                if (flag) continue;
                //sousuo
                if (md != 0){
                    nextx.tmp[md][0] = 0;
                }
                int ans = solve(nextx);
                 if (ans == x.xs) {
                    return M[x] = x.xs;
                }
                if (ans == -x.xs){
                    return M[x] = -x.xs;
                }
            }
        }
// 炮
        if (x.tmp[i][0] == 7){
            // yidong x
            for (int j = -8; j<=8 ;j++){
                // nx ny
                int nx = x.tmp[i][1]+j;
                int ny = x.tmp[i][2];
                if (nx > 8 || nx < 0 || ny < 0 || ny > 9) continue;
                int flag = 0 ;
                nextx = x;
                nextx.tmp[i][1] = nx;
                nextx.tmp[i][2] = ny;
                // gansi or zijiren
                int pjz = 0;
                int mb = 0;
                for (int k = 1; k<=N; k++){
                    // shiti
                    if (x.tmp[k][0] == 0) continue;
                    if (k == i )continue;
                    // bmj
                    if (x.tmp[k][1] > x.tmp[i][1] && ny == x.tmp[k][2] && x.tmp[k][1] < nx ) {
                        pjz++;
                    }
                    if (x.tmp[k][1] > nx && ny == x.tmp[k][2] && x.tmp[k][1] <  x.tmp[i][1]) {
                        pjz++;
                    }
                    if (x.tmp[k][1] == nx && x.tmp[k][2] == ny  ){
                        // zijiren
                        if (x.tmp[k][0] * x.xs > 0) {
                            flag = 1;
                            break;
                        }
                        // gansi
                        if (x.tmp[k][0] * x.xs < 0 ){
                            mb = k;
                        }
                    }
                }
                if (mb == 0 && pjz != 0 ) continue;
                //zijiren or bmj
                if (flag) continue;
                //sousuo
                if (mb != 0 && pjz != 1){
                    continue;
                }
                if (mb != 0 && pjz == 1){
                    nextx.tmp[mb][0] == 0;
                }
                int ans = solve(nextx);
                 if (ans == x.xs) {
                    return M[x] = x.xs;
                }
                if (ans == -x.xs){
                    return M[x] = -x.xs;
                }
            }
            for (int j = -9; j<=9 ;j++){
                // nx ny
                int nx = x.tmp[i][1];
                int ny = x.tmp[i][2]+j;
                if (nx > 8 || nx < 0 || ny < 0 || ny > 9) continue;
                int flag = 0 ;
                nextx = x;
                nextx.tmp[i][1] = nx;
                nextx.tmp[i][2] = ny;
                // gansi or zijiren
                int pjz = 0;
                int mb = 0;
                for (int k = 1; k<=N; k++){
                    // shiti
                    if (x.tmp[k][0] == 0) continue;
                    if (k == i )continue;
                    // bmj
                    if (x.tmp[k][2] > x.tmp[i][2] && nx == x.tmp[k][1] && x.tmp[k][2] < ny ) {
                        pjz++;
                    }
                    if (x.tmp[k][2] > ny && nx == x.tmp[k][1] && x.tmp[k][2] <  x.tmp[i][2]) {
                        pjz++;
                    }
                    if (x.tmp[k][1] == nx && x.tmp[k][2] == ny  ){
                        // zijiren
                        if (x.tmp[k][0] * x.xs > 0) {
                            flag = 1;
                            break;
                        }
                        // gansi
                        if (x.tmp[k][0] * x.xs < 0 ){
                            mb = k;
                        }
                    }
                }
                if (mb == 0 && pjz != 0 ) continue;
                //zijiren or bmj
                if (flag) continue;
                //sousuo
                if (mb != 0 && pjz != 1){
                    continue;
                }
                if (mb != 0 && pjz == 1){
                    nextx.tmp[mb][0] == 0;
                }
                int ans = solve(nextx);
                 if (ans == x.xs) {
                    return M[x] = x.xs;
                }
                if (ans == -x.xs){
                    return M[x] = -x.xs;
                }
            }
        }
        // 相
        if (x.tmp[i][0] == 4){
            // yidong
            for (int j = 0; j<4 ;j++){
                // nx ny
                int nx = x.tmp[i][1]+xxd[j];
                int ny = x.tmp[i][2]+xyd[j];
                if ((x.xs  == 1)&&(nx > 8 || nx < 0 || ny < 0 || ny > 4)) continue;
                if ((x.xs  == -1)&&(nx > 8 || nx < 0 || ny < 5 || ny > 9)) continue;
                int flag = 0 ;
                nextx = x;
                nextx.tmp[i][1] = nx;
                nextx.tmp[i][2] = ny;
                // gansi or zijiren
                for (int k = 1; k<=N; k++){
                    // shiti
                    if (x.tmp[k][0] == 0) continue;
                    if (k == i )continue;
                    // bmj
                    if (xyxd[j] + x.tmp[i][1] == x.tmp[k][1] && xyyd[j] + x.tmp[i][2] == x.tmp[k][2]) {
                        flag = 1;
                        break;
                    }
                    if (x.tmp[k][1] == nx && x.tmp[k][2] == ny  ){
                        // zijiren
                        if (x.tmp[k][0] * x.xs > 0) {
                            flag = 1;
                            break;
                        }
                        // gansi
                        if (x.tmp[k][0] * x.xs < 0 ){
                            nextx.tmp[k][0] == 0;
                            break;
                        }
                    }
                }
                //zijiren or bmj
                if (flag) continue;
                //sousuo
                int ans = solve(nextx);
                 if (ans == x.xs) {
                    return M[x] = x.xs;
                }
                if (ans == -x.xs){
                    return M[x] = -x.xs;
                }
            }
        }
        // 仕
        if (x.tmp[i][0] == 5){
            // yidong
            for (int j = 0; j<4 ;j++){
                // nx ny
                int nx = x.tmp[i][1]+xxd[j];
                int ny = x.tmp[i][2]+xyd[j];
                if ((x.xs == 1)&&(nx > 5 || nx < 3 || ny < 0 || ny > 2)) continue;
                if ((x.xs == -1)&&(nx > 5 || nx < 3 || ny < 7 || ny > 9)) continue;
                int flag = 0 ;
                nextx = x;
                nextx.tmp[i][1] = nx;
                nextx.tmp[i][2] = ny;
                // gansi or zijiren
                for (int k = 1; k<=N; k++){
                    // shiti
                    if (x.tmp[k][0] == 0) continue;
                    if (k == i )continue;
                    if (x.tmp[k][1] == nx && x.tmp[k][2] == ny  ){
                        // zijiren
                        if (x.tmp[k][0] == 1) {
                            flag = 1;
                            break;
                        }
                        // gansi
                        if (x.tmp[k][0] < 0 ){
                            nextx.tmp[k][0] == 0;
                            break;
                        }
                    }
                }
                //zijiren or bmj
                if (flag) continue;
                //sousuo
                int ans = solve(nextx);
                if (ans == x.xs) {
                    return M[x] = x.xs;
                }
                if (ans == -x.xs){
                    return M[x] = -x.xs;
                }
            }
        }

    }

    if (shu == 1 && x.xs == -1){
        print(x);
    }
}
int main()
{
    freopen("in2.txt","r",stdin);
    cin >> N;
    node x;
    memset(x.tmp,0,sizeof(x.tmp));
    for (int i = 1 ; i<=N; i++){
        cin >> x.tmp[i][0] >> x.tmp[i][1] >> x.tmp[i][2];
    }
    x.xs = 1;
    solve(x);
    return 0;
}
