#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
vector<int> edges[maxn];
bool g[maxn][maxn];
int vis[maxn], height[maxn];
int n, m;
inline int read(){
    int x = 0;
    char ch = getchar();
    while(!isdigit(ch)){
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x;
}
void input(){
    n = read(); m = read();
    int port[maxn];
    for(int i = 0; i < m; ++i){
        int k, l, r;
        k = read();
        memset(vis, 0, sizeof(vis));
        for(int j = 0; j < k; ++j){
            port[j] = read();
            vis[port[j]] = 1;
        }
        l = port[0]; r = port[k-1];
        for(int p = l; p < r; ++p){
            if(!vis[p]){
                for(int j = 0; j < k; ++j){
                    if(!g[port[j]][p]){
                        edges[port[j]].push_back(p);
                        g[port[j]][p] = true;
                    }
                }
            }
        }
    }
}
int dfs(int p){
    if(height[p]) return height[p];
    int len = edges[p].size();
    for(int i = 0; i < len; ++i){
        height[p] = max(height[p], dfs(edges[p][i]));
    }
    return ++height[p];
}
int main(){
    input();
    // for(int i = 1; i <= n; ++i){
    //     cout<<i<<": ";
    //     for(int j = 0; j < edges[i].size(); ++j)
    //         cout<<edges[i][j]<<" ";
    //     cout<<endl;
    // }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = max(ans, dfs(i));
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}