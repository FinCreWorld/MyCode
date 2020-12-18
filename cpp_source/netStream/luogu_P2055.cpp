/*
 * 2020.11.21 library
 * luogu_P2055 假期的宿舍
 * 二分图最大匹配模板
 */
#include <bits/stdc++.h>
using namespace std;
struct augment_path{
    vector<vector<int> > g; // 用于存储图
    vector<int> pa; // 用于存储左边点的去向
    vector<int> pb; // 用于存储右边点的来源
    vector<int> vis;    // 用于标记点是否已经被访问过
    int dfn;    // 表示时间戳
    int n, m;   // 表示左右点的数目
    int res;    // 表示匹配边的数目

    augment_path(int n, int m):n(n), m(m){
        pa = vector<int>(n, -1);
        pb = vector<int>(m, -1);
        vis = vector<int>(n);
        g.resize(n);
        dfn = res = 0;
    }

    void add(int u, int v){
        g[u].push_back(v);
    }

    bool dfs(int u){
        vis[u] = dfn;   // 表示本回合所访问到的点
        for(int v : g[u]){
            if(pb[v] == -1){
                pa[u] = v;
                pb[v] = u;
                return true;
            }
        }
        for(int v : g[u]){
            if(vis[pb[v]] != dfn && dfs(pb[v])){
                pa[u] = v;
                pb[v] = u;
                return true;
            }
        }
        return false;
    }

    int solve(){
        for(;;){
            ++dfn;
            int cnt = 0;
            for(int i = 0; i < n; ++i)
                if(pa[i] == -1 && dfs(i))
                    ++cnt;
            if(!cnt) break;
            res += cnt;
        }
        return res;
    }
};
const int maxn = 55;
int t, n;
int pupil[maxn];    // 表示其要住宿
int bed[maxn];  // 表示床位
int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int main(){
    t = read();
    int a, num;
    while(t--){
        n = read();
        num = 0;
        memset(pupil, 0, sizeof(pupil));
        memset(bed, 0, sizeof(bed));
        augment_path ap = augment_path(n, n);
        for(int i = 0; i < n; ++i){
            a = read();
            if(!a) pupil[i] = 1;
            else bed[i] = 1;
        }
        for(int i = 0; i < n; ++i){
            a = read();
            if(!pupil[i] && !a) pupil[i] = 1;
            if(pupil[i]) ++num;
        }
        for(int i = 0; i < n; ++i){
            if(bed[i] && pupil[i]) ap.add(i, i);
            for(int j = 0; j < n; ++j){
                a = read();
                if(a && pupil[i] && bed[j]) ap.add(i, j);
            }
        }
        if(ap.solve() == num) printf("^_^\n");
        else printf("T_T\n");
    }
    system("pause");
    return 0;
}