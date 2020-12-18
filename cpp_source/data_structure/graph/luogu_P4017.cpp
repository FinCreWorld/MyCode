#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;
const int maxn = 5000;
const int maxm = 500005;
const int MOD = 80112002;
int vis[maxn];
int indegree[maxn], outdegree[maxn];   // 存储每一个点的入度
int head[maxn], point[maxm], nxt[maxm];
int cnt = 0;
int n, m;
queue<int> q1, q2;
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
        ++indegree[a];
        ++outdegree[b];
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
        if(!outdegree[i]) vis[i] = 1;
    }
    for(int i = 1; i <= n; ++i){
        if(!indegree[i]) q1.push(i);
    }
    while(!q1.empty()){
        int a = q1.front(); q1.pop();
        q2.push(a);
        for(int k = head[a]; k; k = nxt[k]){
            --indegree[point[k]];
            if(!indegree[point[k]]) q1.push(point[k]);
        }
    }
    int a;
    while(!q2.empty()){
        a = q2.front(); q2.pop();
        if(!vis[a]) {
            ans += dfs(a);
            ans %= MOD;
        }
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}