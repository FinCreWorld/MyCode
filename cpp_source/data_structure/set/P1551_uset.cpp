#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 5005;
int uset[maxn], high[maxn];
int find(int x){
    if(uset[x] == x) return x;
    else return uset[x] = find(uset[x]);
}
void unionSet(int x, int y){
    if(high[find(x)] > high[find(y)])
        uset[uset[y]] = uset[x];
    else{
        uset[uset[x]] = uset[y];
        if(high[uset[x]] == high[uset[y]])
            high[uset[y]]++;
    }
}
int main(){
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    for(int i = 1; i <= n; i++)
        uset[i] = i, high[i] = 1;
    int x, y;
    while(m--){
        scanf("%d %d", &x, &y);
        unionSet(x, y);
    }
    while(p--){
        scanf("%d %d", &x, &y);
        if(find(x) == find(y)) printf("Yes\n");
        else printf("No\n");
    }
    system("pause");
    return 0;
}