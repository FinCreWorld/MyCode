// 使用邻接矩阵进行dfs得到欧拉回路
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 105;
int graph[maxn][maxn];
int path[maxn], cnt = 0, vis[maxn];
int n, m;
void dfs(int p){
    for(int i = 1; i <= n; ++i){
        if(graph[p][i]){
            --graph[p][i];
            --graph[i][p];
            dfs(i);
        }
    }
    path[cnt++] = p;
}
int main(){
    int u, v;
    cin>>n>>m;
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &u, &v);
        ++graph[u][v];
        ++graph[v][u];
    }
    dfs(1);
    for(int i = 0; i < cnt; ++i){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}