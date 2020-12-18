#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cmath>
using namespace std;
typedef long long ll;
const ll INF = 1e9+5;
ll read(){
    ll x=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int main(){
    ll t, n, m, x, k, y;
    ll ans = 0;
    t = read();
    for(ll i = 0; i < t; ++i){
        x = INF; ans = 0;
        n = read();m = read();k = read();
        for(ll j = 0; j < m; ++j){
            y = read();
            ans += abs(k-y)*2;
            x = min(x, y);
        }
        if(x < k) ans += k-1 + x-1 - (k-x);
        else ans += 2*(k-1);
        printf("%d\n", ans);
    }
    // system("pause");
    return 0;
}