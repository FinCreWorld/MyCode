#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
using namespace std;
const int maxn = 1e7+5;
int vis[maxn], phi[maxn], prime[maxn];
int cnt = 0;
void init(int x){
    phi[1] = 1;
    for(int i = 2; i <= x; ++i){
        if(!vis[i]){
            phi[i] = i - 1;
            prime[cnt++] = i;
        }
        for(int j = 0; j < cnt; ++j){
            if(1ll * i * prime[j] >= maxn) break;
            vis[i * prime[j]] = 1;
            if(i % prime[j]){
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }else{
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
}
int main(){
    int x;
    cin>>x;
    init(x);
    cout<<cnt<<endl;
    ++cnt;
    cout<<cnt*(cnt-1)*(cnt-2)*(cnt-3)/24<<endl;
    system("pause");
    return 0;
}