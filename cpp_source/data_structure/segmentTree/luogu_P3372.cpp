/*
 * 2020.9.23 T2 106
 * jcy
 * 线段树 模板题
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
int n, m, x, y, a[maxn], flag;
ll d[maxn<<2], b[maxn<<2];
ll k;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}

// 建树
void build(int s, int t, int p){
    if(s == t){
        d[p] = a[s];
        return;
    }
    int m = (s+t)/2;
    build(s, m, p<<1), build(m+1, t, (p<<1)+1);
    d[p] = d[p<<1] + d[(p<<1)+1];
}

// 区间加值
void update(int l, int r, int s, int t, ll c, int p){
    if(l <= s && t <= r){
        d[p] += (t-s+1)*c, b[p] += c;
        return;
    }
    int m = (s+t)/2;
    if(s!=t && b[p]){
        d[p<<1] += b[p]*(m-s+1), d[(p<<1)+1] += b[p]*(t-m);
        b[p<<1] += b[p], b[(p<<1)+1] += b[p];
        b[p] = 0;
    }
    if(m >= l) update(l, r, s, m, c, p<<1);
    if(m < r) update(l, r, m+1, t, c, (p<<1)+1);
    d[p] = d[p<<1] + d[(p<<1)+1];
}

// 得到任意区间的和
ll getsum(int l, int r, int s, int t, int p){
    if(l <= s && t <= r) return d[p];
    int m = (s+t)/2;
    ll sum = 0;
    if(s != t && b[p]){
        d[p<<1] += b[p]*(m-s+1), d[(p<<1)+1] += b[p]*(t-m);
        b[p<<1] += b[p], b[(p<<1)+1] += b[p];
        b[p] = 0;
    }
    if(m >= l) sum = getsum(l, r, s, m, p<<1);
    if(m < r) sum += getsum(l, r, m+1, t, (p<<1)+1);
    return sum;
}

int main(){
    ll sum = 0;
    n = read(); m = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    build(1, n, 1);
    for(int i = 0; i < m; ++i){
        flag = read();
        if(flag == 1){
            x = read(), y = read(), k = read();
            update(x, y, 1, n, k, 1);
        }else{
            x = read(), y = read();
            sum = getsum(x, y, 1, n, 1);
            printf("%lld\n", sum);
        }
    }
    system("pause");
    return 0;
}