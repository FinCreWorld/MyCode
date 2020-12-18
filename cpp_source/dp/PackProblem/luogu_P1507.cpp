/*
 * 2020.10.13 宿舍
 * jcy
 * 二维背包问题模板
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int maxu = 405;
const int maxv = 505;
const int maxn = 55;
int dp[maxu][maxv], n, u, v;
struct{
    int u, v, w;
}food[maxn];
int main(){
    scanf("%d %d", &u, &v);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d %d %d", &food[i].u, &food[i].v, &food[i].w);
    for(int i = 1; i <= n; ++i)
        for(int j = u; j >= food[i].u; --j)
            for(int k = v; k >= food[i].v; --k)
                dp[j][k] = max(dp[j][k], dp[j-food[i].u][k-food[i].v]+food[i].w);
    printf("%d\n", dp[u][v]);
    system("pause");
    return 0;
}