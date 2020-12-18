/*
 * 2020.11.21 library
 * 二分图最大匹配模板 jcy
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