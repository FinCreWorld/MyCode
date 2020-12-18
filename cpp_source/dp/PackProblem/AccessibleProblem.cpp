/*
 * 2020.10.13 寝室
 * jcy
 * 多重背包无权值的可行性问题
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 105;
// f 表示状态方程、v 表示物品的容量
// f[i][j] 表示前 i 种物品将容量为 j 的背包填满时
// 所剩下的物品 j 的数目，不满足条件时其值为 -1
// 其状态转移方程为 f[i][j] = max(f[i][j], f[i][j-c[i]]-1)
int f[maxn], c[maxn], k[maxn], n, m;
int main(){
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>c[i]>>k[i];
    for(int i = 1; i <= m; ++i)
        f[i] = -1;
    f[0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j)
            if(f[j] >= 0) f[j] = k[i];
        for(int j = c[i]; j <= m; ++j)
            f[j] = max(f[j], f[j-c[i]]-1);
    }
    return 0;
}