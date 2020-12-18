#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 250

struct Edge{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f):from(u), to(v), cap(c), flow(f){}
};
struct Dinic{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int d[maxn], cur[maxn];
    bool vis[maxn];

    void init(int n){
        for(int i = 0; i < n; ++i) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap){
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(from, to, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool bfs() {    // 用于将网络分层
        queue<int> q;
        memset(vis, 0, sizeof(vis));
        d[s] = 0;
        vis[s] = 1;
        q.push(s);
        int x;
        while(!q.empty()){
            x = q.front(); q.pop();
            for(int i = 0; i < G[x].size(); ++i){   // 遍历所有相邻点
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

    int dfs(int x, int a){
        if(x == t || !a) return a;
        int flow = 0, f;
        for(int& i = cur[x]; i < G[x].size(); ++i){
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

    int Maxflow(int s, int t){
        this->s = s;
        this->t = t;
        int flow = 0;
        while(bfs()){
            flow += dfs(s, INF);
        }
        return flow;
    }
};