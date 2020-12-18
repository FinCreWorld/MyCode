/*
 * 2020.10.13 寝室
 * jcy
 * 分组背包模板题
 */
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1005;
vector<int> c[maxn];
vector<int> w[maxn];
int group[maxn], cnt;
int dp[maxn], n, m;
int main(){
    scanf("%d %d", &m, &n);
    int d, e, f;
    for(int i = 1; i <= n; ++i){
        scanf("%d %d %d", &d, &e, &f);
        c[f].push_back(d);
        w[f].push_back(e);
        group[cnt++] = f;
    }
    int k;
    int len = unique(group, group+cnt) - group;
    for(int g = 0; g < len; ++g){
        k = group[g];
        for(int i = m; i >= 0; --i){
            for(int j = 0; j < c[k].size(); ++j){
                if(i >= c[k][j]) dp[i] = max(dp[i], dp[i - c[k][j]] + w[k][j]);
            }
        }
    }
    cout<<dp[m]<<endl;
    system("pause");
    return 0;
}