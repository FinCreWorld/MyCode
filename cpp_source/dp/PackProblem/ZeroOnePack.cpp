/*
 * 2020.10.12 T2 F6
 * jcy
 * 0-1 背包问题
 */
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
// 物品的种类的数目
const int maxm = 105;
// 背包的容量
const int maxn = 1005;
int main(){
    // 不强制要求装满
    int dp[maxn], v[maxm], w[maxm];
    int sum[maxn];  // 用于常数优化
    int n, m;       // 分别表示背包总容量和物品种类数
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i)
        scanf("%d %d", &w[i], &v[i]);

    for(int i = 0; i <= n; ++i)
        dp[i] = 0;
    sum[n+1] = 0;
    for(int i = m; i >= 1; --i)
        sum[i] = sum[i+1] + w[i];

    for(int i = 1; i <= m; ++i)
        // 下边的条件使用了常数优化
        for(int j = n; j >= max(w[i], n-sum[i+1]); --j)
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);

    printf("%d\n", dp[n]);
    system("pause");
    return 0;
}

// 强制要求装满
int addObject(int *dp, int *v, int *w, int n, int m){
    const int INF = 0x7fffffff;
    dp[0] = 0;
    for(int i = 1; i <= n; ++i)
        dp[i] = -INF;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    return dp[n];
}