#include<iostream>
#include<cstdlib>
using namespace std;
const int maxn = 1005;
int fa[maxn], high[maxn];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void unionSet(int x, int y){
    if(high[find(x)] > high[find(y)])
        fa[fa[y]] = fa[x];
    else{
        if(high[fa[x]] == high[fa[y]])
            high[fa[y]]++;
        fa[fa[x]] = fa[y];
    }
}
int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) == 2){
        for(int i = 1; i <= n; i++){
            fa[i] = i;
            high[i] = 1;
        }
        int x, y;
        while(m--){
            scanf("%d %d", &x, &y);
            unionSet(x, y);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(fa[i] == i) ++cnt;
        --cnt;
        printf("%d\n", cnt);
    }
    system("pause");
    return 0;
}