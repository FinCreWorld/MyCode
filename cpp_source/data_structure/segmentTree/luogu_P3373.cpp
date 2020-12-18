/*
 * 2020.9.23 T2 106
 * jcy
 * 线段树模板题进阶
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
typedef struct A{
    ll sum;
    ll lazy_times;  // 乘法的懒惰标记
    ll lazy_plus;   // 加法的懒惰标记
    A(){
        sum = 0;
        lazy_times = 1;
        lazy_plus = 0;
    }
}A;
ll a[maxn]; // 用来存储原始数组
A d[maxn<<2];  // 用来存储线段树的相关信息
ll mod;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
void build(int s, int t, int p){
    if(s == t){
        d[p].sum = a[s];
        return;
    }
    int m = (s+t)/2;
    build(s, m, p<<1), build(m+1, t, (p<<1)+1);
    d[p].sum = d[p<<1].sum + d[(p<<1)+1].sum;
    // 注意可能一开始就爆掉
    d[p].sum %= mod;
}
void change(int s, int t, int p, ll times, ll plus){
    d[p].sum *= times, d[p].sum += plus*(t-s+1);
    d[p].lazy_times *= times;
    d[p].lazy_plus *= times;
    d[p].lazy_plus += plus;

    d[p].sum %= mod;
    d[p].lazy_plus %= mod;
    d[p].lazy_times %= mod;
}
void push_down(int s, int t, int p){
    int m = (s+t)/2;
    if((d[p].lazy_plus || d[p].lazy_times!=1) && s!=t){
        ll plus = d[p].lazy_plus, times = d[p].lazy_times;
        change(s, m, p<<1, times, plus);
        change(m+1, t, (p<<1)+1, times, plus);
        d[p].lazy_plus = 0, d[p].lazy_times = 1;
    }
}
void update(int l, int r, int s, int t, ll x, ll y, int p){
    if(l<=s && t<=r){
        change(s, t, p, x, y);
        return;
    }
    int m = (s+t)/2;
    push_down(s, t, p);
    if(m >= l) update(l, r, s, m, x, y, p<<1);
    if(m < r) update(l, r, m+1, t, x, y, (p<<1)+1);
    d[p].sum = d[p<<1].sum + d[(p<<1)+1].sum;
    d[p].sum %= mod;
}
ll getsum(int l, int r, int s, int t, int p){
    if(l<=s && t<=r) {
        return d[p].sum;
    }
    push_down(s, t, p);
    int m = (s+t)/2;
    ll sum = 0;
    if(m >= l) sum = getsum(l, r, s, m, p<<1);
    if(m < r) sum += getsum(l, r, m+1, t, (p<<1)+1);
    return sum%mod;
}
ll n, m, x, y, k, flag;
int main(){
    n = read(), m = read(), mod = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    build(1, n, 1);
    for(int i = 0; i < m; ++i){
        flag = read();
        switch (flag)
        {
        case 1:
            x = read(), y = read(), k = read();
            update(x, y, 1, n, k, 0, 1);
            break;
        case 2:
            x = read(), y = read(), k = read();
            update(x, y, 1, n, 1, k, 1);
            break;
        default:
            x = read(), y = read();
            printf("%lld\n", getsum(x, y, 1, n, 1));
            break;
        }
    }
    system("pause");
    return 0;
}