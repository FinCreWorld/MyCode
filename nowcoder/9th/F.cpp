#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 200005;
const int INF = 0x7fffffff;
struct Node{
    int x, g;
    bool operator < (Node b){
        return x < b.x;
    }
}a[maxn];
int group = 0;
int vis[maxn];
int main(){
    int n, m, k, cnt = 0, x;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &k);
        while(k--){
            scanf("%d", &x);
            a[++cnt] = (Node){x, i};
        }
    }
    sort(a+1, a+cnt+1);

    int l, r, ans = INF;
    l = r = group = 1; vis[a[l].g]++;
    while(l <= n && r <= n){
        if(group < m){
            ++r;
            if(vis[a[r].g] == 0) ++group;
            ++vis[a[r].g];
        }
        else if(group == m){
            ans = min(ans, a[r].x - a[l].x);
            if(vis[a[r].g] == 1) --group;
            --vis[a[l].g];
            ++l;
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}