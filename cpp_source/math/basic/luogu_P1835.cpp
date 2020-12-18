/*
 * 2020.9.29 T2 106
 * jcy
 * 素数密度，初步想法为使用欧拉筛进行给定区间内的质数数目统计
 * 但是发现欧拉筛不太行，故尝试使用埃氏筛，埃氏筛貌似也不行，，，
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
const int maxm = 1e6+5;
int prime[maxn], vis[maxn], cnt = 0;
int ltor[maxm]; // 表示从 l 到 r 的区间
// 欧拉筛，用来得到 1-n 的素数
void Euler(ll n){
    for(int i = 2; i <= n; ++i){
        if(!vis[i]) prime[cnt++] = i;
        for(int j = 0; j <= cnt; ++j){
            if(1ll*i*prime[j] > n) break;
            vis[i*prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

void Era(int l, int r){
    for(int i = 0; i < cnt; ++i){
        int p = l/prime[i], q = r/prime[i];
        if(l%prime[i]) ++p;
        if(p == 1) ++p;
        for(int j = p; j <= q; ++j)
            ltor[j*prime[i]-l] = 1;
    }
}
int main(){
    int l, r;
    cin>>l>>r;
    Euler((int)sqrt(r));
    // for(int i = 0; i < cnt; ++i){
    //     cout<<prime[i]<<" ";
    // }
    // cout<<endl;
    Era(l, r);
    int ans = 0;
    for(int i = 0; i <= r-l; ++i)
        if(!ltor[i]) ++ans;
    cout<<ans<<endl;
    system("pause");
    return 0;
}
