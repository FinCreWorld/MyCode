/*
 * 2020.10.16 HF5
 * jcy
 * 依赖背包问题
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxm = 65;
const int maxn = 32005;
const int K = 10;
int mainObj[maxm];      // 记录第 k 组主件的物品号
int group[maxm][K];     // 记录第 k 组所包含的附件
int c[maxm], w[maxm];   // 记录第 i 个物品的空间和价值
int dp[maxn], f[maxm][K][2];    // 分别记录总的 dp 结果和所创造的分组
int n, m, cnt;
void read(){
    int v, p, q;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i){
        scanf("%d %d %d", &v, &p, &q);
        c[i] = v;
        w[i] = v * p;
        if(q)
            group[q][++group[q][0]] = i;
        else
            mainObj[++cnt] = i;
    }
}
// 将每一个依赖组转化为分组背包中的组
// 传入参数 k 表示当前处理的是第 k 组
void split(int k){
    int obj = mainObj[k];
    f[k][++f[k][0][0]][0] = c[obj];
    f[k][f[k][0][0]][1] = w[obj]; 
    if(group[obj][0] >= 1){
        // cout<<obj<<endl;
        f[k][++f[k][0][0]][0] = c[group[obj][1]] + f[k][1][0];
        f[k][f[k][0][0]][1] = w[group[obj][1]] + f[k][1][1];
    }
    if(group[obj][0] >= 2){
        // cout<<mainObj[k]<<endl;
        f[k][++f[k][0][0]][0] = c[group[obj][2]] + f[k][1][0];
        f[k][f[k][0][0]][1] = w[group[obj][2]] + f[k][1][1];
        f[k][++f[k][0][0]][0] = c[group[obj][2]] + f[k][2][0];
        f[k][f[k][0][0]][1] = w[group[obj][2]] + f[k][2][1];
    }
}
int main(){
    read();
    // cout<<cnt<<endl;
    for(int k = 1; k <= cnt; ++k)
        split(k);
    for(int k = 1; k <= cnt; ++k)
        for(int j = n; j >= 0; --j)
            for(int i = 1; i <= f[k][0][0]; ++i)
                if(j >= f[k][i][0])
                    dp[j] = max(dp[j], dp[j - f[k][i][0]] + f[k][i][1]);
    printf("%d\n", dp[n]);
    system("pause");
    return 0;
}