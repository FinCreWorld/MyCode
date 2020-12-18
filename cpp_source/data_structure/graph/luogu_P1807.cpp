#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 1505;
const int maxm = 50005;
const int INF = 0x7fffffff;
struct Edge{
    int v, w, nxt;
}edges[maxm];
int head[maxn], cnt = 0, len[maxn];
int n, m;
bool vis[maxn];
void input(){
    int u, v, w;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &u, &v, &w);
        edges[++cnt] = (Edge){u, w, head[v]};
        head[v] = cnt;
    }
}
// 返回点 p 到达 1 的最长距离
int dfs(int p){
    if(p == 1) return 0;
    int mx = -INF, v;
    vis[p] = true;
    for(int k = head[p]; k; k = edges[k].nxt){
        v = edges[k].v;
        if(!vis[v]) dfs(v);
        if(len[v] != INF) mx = max(mx, len[v] + edges[k].w);
    }
    if(mx == -INF) mx = INF;
    return len[p] = mx;
}
int main(){
    input();
    int ans = dfs(n);
    if(ans == INF) printf("-1\n");
    else printf("%d\n", ans);
    system("pause");
    return 0;
}