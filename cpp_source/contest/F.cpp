#include <iostream>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define maxn 200005
#define maxm 200005
#define R register
using namespace std;

typedef long long ll;

ll n, m, k, ai, bi, ci, sum, cnt, dis[maxm], vis[maxm], head[maxn];
ll e1[maxn], e2[maxn];
struct Edge
{
    ll from, to, next, w;
}edge[maxn*2];

struct tree{
    ll from, weight;
}Tree[maxn*2];

ll read(){
    ll x=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}

void add(ll u, ll v, ll w)
{
    edge[++k].to = v;
    edge[k].from = u;
    edge[k].w = w;
    edge[k].next = head[u];
    head[u] = k;
}

typedef pair<ll, ll> pii;
priority_queue <pii, vector<pii>, greater<pii> > q;

void Prim()
{
    dis[1] = 0;
    q.push(make_pair(0, 1));
    while(!q.empty() && cnt<n)
    {
        R ll d = q.top().first, u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        cnt++;
        sum += d;
        vis[u] = 1;
        for(R ll i = head[u]; i != -1; i = edge[i].next)
            if(edge[i].w < dis[edge[i].to]){
                dis[edge[i].to] = edge[i].w;
                q.push(make_pair(dis[edge[i].to], edge[i].to));

                Tree[edge[i].to].from = u;
                Tree[edge[i].to].weight = edge[i].w;
            }
    }
}
ll viss[maxn];
ll cntt = 0;
ll findMaxEdge(ll u, ll v){
    ll a = max(Tree[u].weight, Tree[v].weight);
    ll r, s, t;
    ++cntt;
    for(r = u; r; r = Tree[r].from) viss[r] = cntt;
    ++cntt;
    for(s = v; viss[s] != cntt - 1; s = Tree[s].from) viss[s] = cntt, a = max(a, Tree[s].weight);
    viss[s] = cntt;
    for(t = u; viss[t] != cntt; t = Tree[t].from) a = max(a, Tree[t].weight);
    return a;
}
int main()
{
    ll tmp = 0;
    cin>>n>>m;
    memset(head, -1, sizeof(head));
    memset(dis, 127, sizeof(dis));
    while(m--)
    {
        ai = read(); bi = read(); ci = read();
        add(ai, bi, ci);
        add(bi, ai, ci);
    }
    Prim();
    // if(cnt == n) cout<<sum<<endl;
    // else cout<<"orz"<<endl;
    ll a;

    for(ll i = 1; i <= k; i += 2){
        if(Tree[edge[i].from].from == edge[i].to ||
            Tree[edge[i].to].from == edge[i].from)
            printf("%lld\n", sum);
        else{
            a = findMaxEdge(edge[i].from, edge[i].to);
            printf("%lld\n", sum - a + edge[i].w);
        }
    }
    // system("pause");
    return 0;
}