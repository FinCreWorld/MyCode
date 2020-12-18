#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 1000005;
const int MOD = 999983;
queue<int> q;
struct edge{
    int to;
    int next;
    int vis;
}edges[maxn<<1];
struct head{
    int point;
    int edgepos;
}heads[maxn];
int cnt;
int find(int a){  // 找到点所对应的第一条边的序号
    int p = a % MOD;
    while(heads[p].point != a){
        ++p;
        p %= MOD;
    }
    return p;
}
void addEdge(int a, int b){
    edges[++cnt] = (edge){b, heads[find(a)].edgepos};
    heads[find(a)].edgepos = cnt;
}
int main(){
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        int n, a, b;
        cnt = 0;
        cin>>n;
        for(int j = 1; j <= n; j++){
            cin>>a>>b;
            addEdge(a, b);
            addEdge(b, a);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            q.push(1);
            while(!q.empty()){
                edge e = edges[q.front()]; q.pop();
                ++ans;
                for(int )
            }
        }
    }
}