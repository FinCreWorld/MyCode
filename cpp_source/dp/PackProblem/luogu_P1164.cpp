/*
 * 2020.10.13 T2 106
 * jcy
 * 分类说是 01 背包，貌似是 01 背包的变形
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxm = 1e4+5;
const int maxn = 105;
int dp[maxm], price[maxn];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &price[i]);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = m; j >= price[i]; --j)
            dp[j] += dp[j - price[i]];
    printf("%d\n", dp[m]);
    system("pause");
    return 0;
}