/*
 * 2020.11.11 T2 40?
 * jcy
 * Ford-Fulkerson 算法的 EdmondKarp 实现
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <queue>
#define maxn 250
#define INF 0x3f3f3f3f;
using namespace std;
typedef struct Edge{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f):from(u),to(v),cap(c),flow(f){}
}Edge;
typedef struct EK{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn], p[maxn];

    void init(int n){
        for(int i = 0; i < n; ++i){
            G[i].clear();
            edges.clear();
        }
    }

    void AddEdge(int from, int to, int cap){
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        int m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    int Maxflow(int s, int t){
        int flow = 0;
        for(;;){
            memset(a, 0, sizeof(a));    // 用于寻找路径上最小流量
            queue<int> q;
            a[s] = INF;
            q.push(s);
            while(!q.empty()){  // 进行 bfs，找到汇点
                int x = q.front(); q.pop();
                for(int i = 0; i < G[x].size(); ++i){
                    Edge& edge = edges[G[x][i]];
                    if(!a[edge.to] && edge.cap > edge.flow){
                        a[edge.to] = min(a[x], edge.cap - edge.flow);
                        p[edge.to] = G[x][i];
                    }
                }
                if(a[t]) break;
            }
            if(!a[t]) break;
            for(int u = t; u != s; u = edges[p[u]].from){
                edges[p[u]].flow += a[t];
                edges[p[u] ^ 1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};