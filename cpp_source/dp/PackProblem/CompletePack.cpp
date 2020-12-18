/*
 * 2020.10.12 T2 6 楼
 * jcy
 * 完全背包问题
 */
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e7+5;
const int maxm = 1e4+5;
typedef long long ll;
ll dp[maxn];
int w[maxm], v[maxm];
int n, m;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i)
        scanf("%d %d", &w[i], &v[i]);
    for(int i = 0; i <= n; ++i)
        dp[i] = 0;
    for(int i = 1; i <= m; ++i)
        for(int j = w[i]; j <= n; ++j)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    printf("%lld\n", dp[n]);
    system("pause");
    return 0;
}