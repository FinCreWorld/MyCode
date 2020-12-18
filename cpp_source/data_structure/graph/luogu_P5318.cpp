#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100006;
vector<int> q[maxn];
queue<int> qq;
bool vis[maxn];
void dfs(int p){
    vis[p] = true;
    printf("%d ", p);
    int len = q[p].size();
    for(int i = 0; i < len; ++i){
        if(vis[q[p][i]]) continue;
        dfs(q[p][i]);
    }
}
void bfs(int p){
    qq.push(p); vis[p] = true;
    while(!qq.empty()){
        int a = qq.front();
        int len = q[a].size();
        printf("%d ", a);
        qq.pop();
        for(int i = 0; i < len; ++i){
            if(vis[q[a][i]]) continue;
            qq.push(q[a][i]);
            vis[q[a][i]] = true;
        }
    }
}
int main(){
    int n, m, a, b;
    cin>>n>>m;
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &a, &b);
        q[a].push_back(b);
    }
    for(int i = 1; i <= n; ++i){
        sort(q[i].begin(), q[i].end());
    }
    // for(int i = 1; i <= n; ++i){
    //     for(int j = 0; j < q[i].size(); ++j){
    //         printf("%d ", q[i][j]);
    //     }
    //     printf("\n");
    // }
    memset(vis, 0, sizeof(vis));
    dfs(1);printf("\n");
    memset(vis, 0, sizeof(vis));
    bfs(1);printf("\n");
    system("pause");
    return 0;
}