/*
 * 2020.10.21 T2 106
 * jcy
 * 整数求余的运算性质
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll read(){
    ll x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int main(){
    ll q, l, r, t;
    q = read();
    for(ll i = 0; i < q; ++i){
        l = read(); r = read();
        t = (r - l + 1) % 9;
        l = ((l % 9) * t + t * (t - 1)/2) % 9;
        printf("%d\n", l);
    }
    system("pause");
    return 0;
}