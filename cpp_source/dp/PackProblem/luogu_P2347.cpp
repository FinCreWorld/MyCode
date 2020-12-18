/*
 * 2020.10.13 宿舍
 * jcy
 * 多重背包可行性的模板题
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 6;
const int maxm = 1e3+5;
int dp[maxm], c[7] = {0, 1, 2, 3, 5, 10, 20}, k[7], ans;
int main(){
    for(int i = 1; i <= maxn; ++i)
        scanf("%d", &k[i]);
    for(int i = 1; i < maxm; ++i)
        dp[i] = -1;
    dp[0] = 0;
    for(int i = 1; i <= maxn; ++i){
        for(int j = 0; j < maxm; ++j)
            if(dp[j] >= 0) dp[j] = k[i];
            else dp[j] = -1;
        for(int j = c[i]; j < maxm; ++j){
            dp[j] = max(dp[j], dp[j-c[i]]-1);
        }
    }
    for(int i = 1; i < maxm; ++i)
        if(dp[i] >= 0) ++ans;
    printf("Total=%d\n", ans);
    system("pause");
    return 0;
}