#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 5000;
const int maxm = 500005;
const int MOD = 80112002;
int vis[maxn];
int outdegree[maxn], indegree[maxn];
int head[maxn], point[maxm], nxt[maxm];
int cnt = 0;
int n, m;
int read(void){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x*f;
}
void input(void){
    int a, b;
    n = read(); m = read();
    for(int i = 0; i < m; ++i){
        a = read(); b = read();
        ++outdegree[b];
        ++indegree[a];
        point[++cnt] = a;
        nxt[cnt] = head[b];
        head[b] = cnt;
    }
}
int dfs(int p){
    for(int k = head[p]; k; k = nxt[k]){
        if(vis[point[k]]) vis[p] += vis[point[k]];
        else vis[p] += dfs(point[k]);
        vis[p] %= MOD;
    }
    return vis[p];
}
int main(){
    int ans = 0;
    input();
    for(int i = 1; i <= n; ++i){
        if(!outdegree[i])
            ++vis[i];
    }
    for(int i = 1; i <= n; ++i){
        if(!indegree[i])
            ans += dfs(i);
        ans %= MOD;
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}