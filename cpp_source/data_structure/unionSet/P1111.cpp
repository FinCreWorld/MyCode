#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 1005;
const int maxm = 100005;
typedef struct road{
    int x, y, t;
    bool operator<(road b){
        return t < b.t;
    }
}road;
int uset[maxn], deep[maxn];
road roads[maxm];
int find(int pa){
    if(uset[pa] == pa) return pa;
    return find(uset[pa]);
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i) uset[i] =i;
    for(int i = 1; i <= m; ++i) 
        scanf("%d %d %d", &roads[i].x, &roads[i].y, &roads[i].t);
    sort(roads+1, roads+1+m);
    int setNum = n;
    int i;
    for(i = 1; i <= m && setNum > 1; ++i){
        int pa = find(roads[i].x), pb = find(roads[i].y);
        if(pa != pb){
            --setNum;
            if(deep[pa] < deep[pb]) uset[pa] = pb;
            else{
                uset[pb] = pa;
                if(deep[pb] == deep[pa]) ++deep[pa];
            }
        }
    }
    if(setNum == 1) printf("%d\n", roads[i-1].t);
    else printf("-1\n");
    system("pause");
    return 0;
}