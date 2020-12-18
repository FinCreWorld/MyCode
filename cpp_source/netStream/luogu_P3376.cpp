/*
 * 2020.11.11 T2 40?
 * jcy
 * V1 使用 EdmondKarp 实现
 * V2 使用 Dinic 实现
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <queue>
#define maxn 250
#define INF 0x7fffffff
using namespace std;
typedef long long ll;
struct Edge{
    ll from, to, cap, flow;
    Edge(ll u, ll v, ll c, ll f):from(u), to(v), cap(c), flow(f){}
};
struct Dinic{
    ll n, m, s, t;
    vector<Edge> edges;
    vector<ll> G[maxn];
    ll d[maxn], cur[maxn];
    bool vis[maxn];

    void init(ll n){
        for(ll i = 0; i < n; ++i) G[i].clear();
        edges.clear();
    }

    void AddEdge(ll from, ll to, ll cap){
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool bfs() {    // 用于将网络分层
        queue<ll> q;
        memset(vis, 0, sizeof(vis));
        d[s] = 0;
        vis[s] = 1;
        q.push(s);
        ll x;
        while(!q.empty()){
            x = q.front(); q.pop();
            for(ll i = 0; i < G[x].size(); ++i){   // 遍历所有相邻点
                Edge edge = edges[G[x][i]];
                if(!vis[edge.to] && edge.cap > edge.flow){  // 要求边拥有剩余流量，且不能走添加的余边
                    vis[edge.to] = 1;
                    d[edge.to] = d[x] + 1;
                    q.push(edge.to);
                }
            }
        }
        return vis[t];
    }

    ll dfs(ll x, ll a){
        if(x == t || !a) return a;
        ll flow = 0, f;
        for(ll& i = cur[x]; i < G[x].size(); ++i){
            Edge& e = edges[G[x][i]];
            if(d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0){
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if(!a) break;
            }
        }
        return flow;
    }

    ll Maxflow(ll s, ll t){
        this->s = s;
        this->t = t;
        ll flow = 0;
        while(bfs()){
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, INF);
        }
        return flow;
    }
};
ll read(){
    ll x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int main(){
    ll n, m, s, t;
    ll u, v, w;
    Dinic d;
    n = read(), m = read();
    s = read(), t = read();
    d.n = n;
    d.init(n);
    for(int i = 0; i < m; ++i){
        u = read(), v = read(), w = read();
        d.AddEdge(u, v, w);
    }
    cout<<d.Maxflow(s, t)<<endl;
    system("pause");
    return 0;
}