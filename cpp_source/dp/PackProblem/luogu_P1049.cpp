/*
 * 2020.10.12 宿舍
 * jcy
 * 01 背包问题
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(){
    int v[31], dp[20005];
    int c, n;
    scanf("%d", &c);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);
    for(int i = 0; i <= c; ++i) dp[i] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = c; j >= v[i]; --j)
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
    printf("%d\n", c - dp[c]);
    system("pause");
    return 0;
}