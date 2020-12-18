/*
 * 2020.10.13 H F5
 * jcy
 * 完全背包问题
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int T = 24*60;
const int maxm = 1000+5;
const int maxn = 10000+5;
struct obj{
    int c, w, p;
}obj[maxn];
int dp[maxn], n, m;
inline void zeroOnePack(int c, int w){
    for(int i = m; i >= c; --i)
        dp[i] = max(dp[i], dp[i - c] + w);
}
inline void completePack(int c, int w){
    for(int i = c; i <= m; ++i)
        dp[i] = max(dp[i], dp[i - c] + w);
}
inline void multiplePack(int c, int w, int num){
    if(c * num >= m){
        completePack(c, w);
        return;
    }
    int k = 1;
    while(k < num){
        zeroOnePack(k*c, k*w);
        num -= k;
        k <<= 1;
    }
    zeroOnePack(num*c, num*w);
}
int main(){
    int h1, h2, m1, m2;
    scanf("%2d:%2d %2d:%2d %d", &h1, &m1, &h2, &m2, &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d %d %d", &obj[i].c, &obj[i].w, &obj[i].p);
    }
    m = (h2-h1)*60 + (m2-m1);
    if(m < 0) m += T;
    for(int i = 1; i <= n; ++i){
        if(obj[i].p) multiplePack(obj[i].c, obj[i].w, obj[i].p);
        else completePack(obj[i].c, obj[i].w);
    }
    printf("%d\n", dp[m]);
    system("pause");
    return 0;
}