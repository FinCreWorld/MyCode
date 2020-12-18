/*
 * 2020.10.13 H F6
 * jcy
 * 多重背包问题
 * 此题无法使用 logn 的优化方法！！！！
 * 因为该部分为乘法，不为加法
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll maxm = 6e5;
const ll INF = 0x7fffffff;
ll n, m, k[maxm], c[maxm], dp[maxm];
ll all_money, ans = INF;
int main(){
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; ++i)
        scanf("%lld", &k[i]);
    for(ll i = 1; i <= n; ++i){
        scanf("%lld", &c[i]);
        all_money += k[i] * c[i]; 
    }
    dp[0] = 1;
    for(ll i = 1; i <= n; ++i)
        for(ll j = all_money; j >= 0; --j)
            for(ll p = 1; p <= k[i] && 1ll*p*c[i] <= j; ++p)
                dp[j] = max(dp[j], dp[j - p*c[i]]*p);
    for(ll i = 0; i <= all_money; ++i)
        if(dp[i] >= m){
            ans = i;
            break;
        }
    printf("%lld\n", ans);
    system("pause");
    return 0;
}