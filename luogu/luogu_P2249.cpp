/*
 * 2020.10.19 H 4
 * jcy
 * 手写一下二分找一下感觉
 */
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 1e6+5;
const int INF = 0x7fffffff;
int n, m, a[maxn];
int find(int x){
    int l = 0, r = n+1, mid;
    while(l < r){
        mid = (l + r)/2;
        if(a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return a[l] == x ? l : -1;
}
int main(){
    scanf("%d %d", &n, &m);
    a[0] = -1; a[n+1] = INF;
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int x;
    for(int i = 1; i <= m; ++i){
        scanf("%d", &x);
        x = find(x);
        printf("%d ", x);
    }
    system("pause");
    return 0;
}