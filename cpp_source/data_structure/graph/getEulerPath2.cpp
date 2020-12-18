#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 105;
const int maxm = 10005;
struct Edge{
    int v, w, nxt, vis;
}edges[maxm<<1];
int head[maxn], cnt = 0;
int path[maxn];
int n, m;
void input(){
    int u, v, w;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &u, &v, &w);
        edges[++cnt] = (Edge){v, w, head[u], 0};
        head[u] = cnt;
        edges[++cnt] = (Edge){u, w, head[v], 0};
        head[v] = cnt;
    }
    cnt = 0;    // 用于在 dfs 中使用
}
void dfs(int u){
    for(int p = head[u]; p; p = edges[p].nxt){
        if(!edges[p].vis){
            edges[p].vis = 1;
            if(p&1) edges[p+1].vis = 1;
            else edges[p-1].vis = 1;
            dfs(edges[p].v);
        }
    }
    path[++cnt] = u;
}
int main(){
    input();
    dfs(1);
    for(int i = 1; i <= cnt; ++i){
        printf("%d ", path[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}