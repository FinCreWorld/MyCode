#include<bits/stdc++.h>
using namespace std;
const int maxn = 20005;
const int maxm = 100005;
typedef struct edge{
    int a, b, c;
    bool operator<(struct edge p){
        return c < p.c;
    }
}Edge;
Edge edges[maxm];
int uset[maxn], deep[maxn];
int find(int k){
    if(uset[k] == k) return k;
    return uset[k] = find(uset[k]);
}
bool unionSet(int a, int b){
    int pa = find(a), pb = find(b);
    if(pa == pb) return false;
    if(deep[pa] < deep[pb]){
        uset[pa] = pb;
    }else{
        uset[pb] = pa;
        if(deep[pa] == deep[pb]) ++deep[pa];
    }
    return true;
}
int setNum, n, m, a, b, c;
int main(){
    scanf("%d %d", &n, &m);
    setNum = n;
    for(int i = 1; i <= n; ++i) uset[i] = i;
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        edges[i] = (Edge){a, b, c};
    }
    sort(edges+1, edges+m+1);
    int k;
    for(k = 1; k <= m && setNum > 2; ++k){
        if(unionSet(edges[k].a, edges[k].b)) --setNum;
    }
    if(setNum == 2) printf("%d\n", edges[k-1].c);
    else printf("0\n");
    system("pause");
    return 0;
}