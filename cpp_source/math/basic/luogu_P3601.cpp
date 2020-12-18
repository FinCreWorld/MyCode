/*
 * 2020.9.30 T2 106
 * jcy
 * 互质：1 与任何数都互质
 * 欧拉函数
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 666623333;
const int maxn = 1e6 + 5;
ll l, r;
int pri[maxn], vis[maxn];
ll num[maxn], phi[maxn];
int cnt = 0;
void getPri(int n){
    for(int i = 2; i <= n; ++i){
        if(!vis[i]) pri[cnt++] = i;
        for(int j = 0; j < cnt; ++j){
            if(1ll * i * pri[j] > n) break;
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}
ll getPhi(ll l, ll r){
    ll ans = 0;
    for(int i = 0; i <= r-l; ++i) num[i] = phi[i] = i + l;
    for(int i = 0; i < cnt && 1ll*pri[i]*pri[i] <= r; ++i){
        ll lt = l;
        int prime = pri[i];
        if(lt % prime) lt = (lt/prime + 1)*prime;
        for(ll j = lt; j <= r; j += prime){
            phi[j - l] = phi[j - l] / prime * (prime - 1);
            while(num[j - l] % prime == 0) num[j - l] /= prime;
        }
    }
    for(int i = 0; i <= r-l; ++i){
        if(num[i] > 1) phi[i] = phi[i] / num[i] * (num[i] - 1);
        ans = (ans + i + l - phi[i]) % MOD;
    }
    return ans;
}
int main(){
    cin>>l>>r;
    getPri((int)sqrt(r+0.5));
    cout<<getPhi(l, r)<<endl;
    system("pause");
    return 0;
}