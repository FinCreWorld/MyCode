#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 10005;
vector<int> v[maxn];
int t[maxn];
int vis[maxn];
int n;
void input(void){
    cin>>n;
    int a, b;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a);
        scanf("%d", &t[a]);
        scanf("%d", &b);
        while(b){
            v[a].push_back(b);
            scanf("%d", &b);
        }
    }
}
int dfs(int p){
    int len = v[p].size();
    int mx = 0;
    for(int i = 0; i < len; ++i){
        if(!vis[v[p][i]]) mx = max(dfs(v[p][i]), mx);
        else mx = max(vis[v[p][i]], mx);
    }
    vis[p] = mx + t[p];
    return vis[p];
}
int main(){
    input();
    int ans = 0;
    for(int i = n; i >= 1; --i){
        if(!vis[i]){
            ans = max(ans, dfs(i));
        }
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}