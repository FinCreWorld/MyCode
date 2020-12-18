/*
 * 2020.9.13
 * 洛谷 组合数
 * 杨辉三角，二维前缀和
 */
#include<cstdio>
#include<cstdlib>
#include<ctype.h>
using namespace std;
const int maxn = 2005;
int a[maxn][maxn];
int ans[maxn][maxn];
int cnt = 0;
int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
void init(int k){
    for(int i = 1; i < maxn; ++i){
        for(int j = 0; j <= i; ++j){
            if(j==0 || j==i) a[i][j] = 1;
            else a[i][j] = a[i-1][j-1] + a[i-1][j];
            a[i][j] %= k;
        }
    }
    for(int i = 1; i < maxn; ++i){
        for(int j = 1; j <= i; ++j){
            ans[i][j] = ans[i][j-1] + ans[i-1][j] - ans[i-1][j-1];
            if(!a[i][j]) ++ans[i][j];
        }
        ans[i][i+1] = ans[i][i];
    }
}
int main(){
    int n, m, k, t;
    t = read(); k = read();
    init(k);
    for(int p = 0; p < t; ++p){
        n = read(); m = read();
        if(m > n) m = n;
        printf("%d\n", ans[n][m]);
    }
    system("pause");
    return 0;
}