#include <queue>
#include <cstring>
using namespace std;
class Solution {
private:
    typedef struct edge{
        int next, v, w;
    }Edge;
    Edge edges[60000];
    int head[105];
    typedef struct point{
        int u, w;
        bool operator<(const struct point& b)const{
            return w < b.w;
        }
    }Point;
    priority_queue<Point> pq;
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int vis[105];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < N; ++i) head[i] = -1;
        int size = times.size();
        for(int i = 0; i < size; ++i){
            edges[i] = (Edge){head[times[i][0]], times[i][1], times[i][2]};
            head[times[i][0]] = i; 
        }

        int d[105];
        const int INF = 0x7fffffff;
        for(int i = 0; i < N; ++i) d[i] = INF;
        d[K] = 0;
        Point p = (Point){K,0};
        pq.push(p);
        int cnt = 0;
        while(!pq.empty()){
            if(cnt == N) break;
            p = pq.top();
            pq.pop();
            if(!vis[p.u]) vis[p.u] = 1, ++cnt;
            else continue;
            for(int k = head[p.u]; k != -1; k = edges[k].next){
                if(d[edges[k].v] < edges[k].w + d[p.u]){
                    d[edges[k].v] = edges[k].w + d[p.u];
                    pq.push((Point){edges[k].v, d[edges[k].v]});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < N; ++i)
            ans = max(ans, d[i]);
        if(ans == INF) return -1;
        else return ans;
    }
};