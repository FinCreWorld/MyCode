/*
 * 2020.10.13 宿舍
 * jcy
 * 分组的背包策略
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int dp[100], num[100], c[100], w[100];
int K, V;
// 应该想一下如果调换三重循环的顺序会怎样
int groupPack(){
    for(int k = 1; k <= K; ++k){
        for(int v = V; v >= 0; --v){
            for(int i = 1; i <= num[k]; ++i){
                dp[v] = max(dp[v], dp[v - c[i]] + w[i]);
            }
        }
    }
}
