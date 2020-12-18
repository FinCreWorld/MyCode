/*
 * H F3 室外空间，2020.12.3
 * jcy
 * 绿豆蛙的归宿，概率dp
 * 今日心情不佳，数字逻辑搞我心态，毫无进展
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = (maxn << 2);
int cnt, indegree[maxn], head[maxn];
double dp[maxn];
int p[maxn];
struct Edge{
    int from, to, weight, next;
}edge[maxm];
int read(){
    char ch=getchar();int x=0;
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
inline void addEdge(int from, int to, int weight){
    edge[++cnt] = (Edge){from, to, weight, head[from]};
    head[from] = cnt;
    ++indegree[to];
    ++p[to];
}
queue<int> q;
int main(){
    int n, m;
    int a, b, c;
    n = read();
    m = read();
    for(int i = 1; i <= m; ++i){
        a = read(); b = read(); c = read();
        addEdge(b, a, c);
    }
    dp[n] = 0;
    q.push(n);
    while(!q.empty()){
        int x = q.front();q.pop();
        for(int k = head[x]; k; k = edge[k].next){
            int s = edge[k].to;
            int t = edge[k].from;
            dp[s] += (dp[t] + edge[k].weight) / p[s];
            --indegree[s];
            if(!indegree[s]) q.push(s);
        }
    }
    printf("%.2lf\n", dp[1]);
    system("pause");
    return 0;
}