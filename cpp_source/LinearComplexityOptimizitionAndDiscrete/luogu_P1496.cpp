/*
 * 2020.10.5 T2 106
 * jcy
 * 离散化的小应用
 * 区间转化
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int maxn = 2e4+5;
typedef long long ll;
int start[maxn], last[maxn];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d %d", &start[i], &last[i]);
    }
    sort(start+1, start+n+1);
    sort(last+1, last+n+1);
    ll r = -(1ll<<33);
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += last[i] - start[i];
        if(start[i] <= r)
            ans -= r - start[i];
        r = last[i];
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}