#include<iostream>
using namespace std;
const int maxn = 1005;
bool vis[maxn];
int fa[maxn];
int head1[maxn], head2[maxn];
int uset[maxn];
struct edge{
    int to, next, lca;
}edges1[maxn], edges2[maxn];
int find(int t){
    if(uset[t] == t) return t;
    else return find(uset[t]);
}
void Tarjan(int u){ // u 是顶点
    vis[u] = 1;
    for(int i = head1[u]; i != -1; i = edges1[i].next){
        Tarjan(edges1[i].to);
        uset[edges1[i].to] = u;
    }
    for(int i = head2[u]; i != -1; i = edges2[i].next){
        if(vis[edges2[i].to]){
            edges2[i].lca = find(edges2[i].to);
            edges2[i^1].lca = edges2[i].lca;
        }
    }
}
int main(){

}