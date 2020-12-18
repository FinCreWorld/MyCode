/*
 * 2020.10.13 H F6
 * jcy
 * 多重背包问题
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxm = 105;
const int maxn = 105;
int n, m;   // 分别表示物品数和空间总数

// 调用一次 01 背包放入第 n 件物品
// 入口参数分别为 状态数组、第 n 件物品的容量、第 n 件物品的权值
void zeroOnePack(int * dp, int c, int w){
    for(int i = m; i >= c; --i)
        dp[i] = max(dp[i], dp[i - c] + w);
}

// 调用一次 完全背包 放入第 n 件物品
// 入口参数分别为 状态数组、第 n 件物品的容量、第 n 件物品的权值
void completePack(int * dp, int c, int w){
    for(int i = c; i <= m; ++i)
        dp[i] = max(dp[i], dp[i - c] + w);
}

// 调用一次 多重背包 放入第 n 件物品
// 入口参数分别为 状态数组、容量、权值、允许的数目
void multiplePack(int * dp, int c, int w, int num){
    // 当 num * c 比背包的总容量要大时，此时问题相当于完全背包问题
    if(num * c >= m){
        completePack(dp, c, w);
        return;
    }
    int k = 1;
    while(k < num){
        zeroOnePack(dp, k*c, k*w);
        num -= k;
        k <<= 1;
    }
    zeroOnePack(dp, num*c, num*w);
}