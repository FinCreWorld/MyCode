/*
 * H301 2020.12.3
 * jcy
 * 换教室，Floyd + 简单期望
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2005;
const int maxv = 305;
int g[maxv][maxv];
int c[maxn], d[maxn];
double k[maxn], excp[maxn];
inline int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
void floyd(int n){
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(g[i][k]>-1 && g[k][j]>-1 && g[i][j]>-1)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
int main(){
    int n, m, v, e; // 基本数据
    int a, b, w;    // 用于建图
    double ans = 0;
    n = read(), m = read(), v = read(), e = read();
    for(int i = 1; i <= n; ++i) c[i] = read();
    for(int i = 1; i <= n; ++i) d[i] = read();
    for(int i = 1; i <= n; ++i) scanf("%lf", &k[i]);
    for(int i = 1; i <= v; ++i)
        for(int j = 1; j <= v; ++j)
            g[i][j] = -1;
    for(int i = 1; i <= e; ++i){
        a = read(), b = read(), w = read();
        if(g[a][b] != -1) g[a][b] = g[b][a] = min(g[a][b], w);
        else g[a][b] = g[b][a] = w;
    }
    for(int i = 1; i <= v; ++i) g[i][i] = 0;
    floyd(v);
    for(int i = 1; i <= n; ++i){
        excp[i] = k[i]*(g[c[i-1]][d[i]]+g[d[i]][c[i+1]] - g[c[i-1]][c[i]]-g[c[i]][c[i+1]]);
        ans += g[c[i-1]][c[i]]+g[c[i]][c[i+1]];
    }
    sort(excp, excp+n);
    for(int i = 1; i <= m && i <= n && excp[i] < 0; ++i){
        ans += excp[i];
    }
    printf("%.2lf\n", ans);
    system("pause");
    return 0;
}