#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn = 1000005;
int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x*f;
}
int flag = 0, ans[maxn], p, flag3 = 0;
bool vis[maxn];
void dfs(int cnt){
    if(cnt == p){
        flag = 1;
        printf("%d\n", p);
        for(int i = 1; i < p; ++i)
            printf("%d ", ans[i]);
        printf("\n");
        if(flag3){
            printf("33333333333333\n");
            flag3 = 0;
        }
        return;
    }
    if(!flag && !vis[ans[cnt-1]*2%p]){
        vis[ans[cnt-1]*2%p] = true;
        ans[cnt] = ans[cnt-1]*2%p;
        dfs(cnt+1);
        vis[ans[cnt-1]*2%p] = false;
    }
    if(!flag && !vis[ans[cnt-1]*3%p]){
        vis[ans[cnt-1]*3%p] = true;
        ans[cnt] = ans[cnt-1]*3%p;
        dfs(cnt+1);
        vis[ans[cnt-1]*3%p] = false;
    }
}
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int t;
    t = read();
    while(t--){
        memset(vis, 0, sizeof(vis));
        p = read();
        flag = 0;
        flag3 = 0;
        vis[0] = true;
        for(int i = 1; i < p && !flag; ++i){
            ans[1] = i;
            vis[i] = true;
            dfs(2);
        }
        if(!flag) printf("-1\n");
    }
    return 0;
}