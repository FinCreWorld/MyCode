#include<iostream>
using namespace std;
const int maxn = 5005;
int head[maxn], cnt = 0;
struct Node{
    int to, last;
}nodes[maxn<<1];
int vis[maxn], uset[maxn];
void dfs(int p, int fa){
    vis[p] = 1; uset[p] = fa;
    for(int k = head[p]; k; k = nodes[k].last)
        if(!vis[nodes[k].to]) dfs(nodes[k].to, fa);
}
int main(){
    int n, m, p;
    cin>>n>>m>>p;
    int x, y;
    for(int i = 0; i < m; i++){ // 读入图
        cin>>x>>y;
        nodes[++cnt] = (Node){y, head[x]};
        head[x] = cnt;
        nodes[++cnt] = (Node){x, head[y]};
        head[y] = cnt;
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i]) dfs(i, i);
    while(p--){
        cin>>x>>y;
        if(uset[x] == uset[y]) printf("Yes\n");
        else printf("No\n");
    }
    system("pause");
    return 0;
}