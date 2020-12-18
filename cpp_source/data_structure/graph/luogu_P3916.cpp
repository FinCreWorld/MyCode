#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
const int maxn = 100005;
const int maxm = 100005;
int head[maxn];
typedef struct Edge{
    int to, next;
}Edge;
Edge edges[maxm];
int n, m, cnt = 0;
int a[maxn];
bool vis[maxn];
void input(void){
    int p, q;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &q, &p);
        edges[++cnt] = (Edge){q, head[p]};
        head[p] = cnt;
    }
}
void dfs(int p, int v){
    a[p] = v;
    vis[p] = true;
    for(int k = head[p]; k; k = edges[k].next){
        if(!vis[edges[k].to])
            dfs(edges[k].to, v);
    }
}
int main(){
    input();
    for(int i = n; i >= 1; --i){
        if(!vis[i]) dfs(i, i);
    }
    for(int i = 1; i <= n; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}