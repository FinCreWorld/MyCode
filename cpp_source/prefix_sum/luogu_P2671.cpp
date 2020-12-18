/*
 * 2020.10.4 T2 106
 * jcy
 * 前缀和
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5+2;
const ll maxm = 1e5+2;
const ll MOD = 10007;
template <typename T> void read(T& x){
    x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
}
ll cnt[maxn<<1];
ll number[maxn], sum1[maxn<<1], sum2[maxn<<1], sum3[maxn<<1];
int main(){
    ll n, m, c, ans = 0;
    read(n), read(m);
    for(ll i = 1; i <= n; ++i){
        read(number[i]);
    }
    for(ll i = 1; i <= n; ++i){
        read(c);
        if(i % 2){
            ++cnt[(c<<1)-1];
            sum1[(c<<1)-1] = (sum1[(c<<1)-1] + i * number[i]) % MOD;
            sum2[(c<<1)-1] = (sum2[(c<<1)-1] + number[i]) % MOD;
            sum3[(c<<1)-1] = (sum3[(c<<1)-1] + i) % MOD;
        }else{
            ++cnt[c<<1];
            sum1[c<<1] = (sum1[c<<1] + i * number[i]) % MOD;
            sum2[c<<1] = (sum2[c<<1] + number[i]) % MOD;
            sum3[c<<1] = (sum3[c<<1] + i) % MOD;
        }
    }
    for(ll i = 1; i <= (m<<1); ++i){
        ans = (ans + (cnt[i] - 2) * sum1[i] + sum3[i] * sum2[i]) % MOD;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}