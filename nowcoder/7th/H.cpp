#include<iostream>
#include<cstdio>
using namespace std;
const int MOD = 1000000007;
int main(){
    long long n, k;
    long long ans = 0;
    cin>>n>>k;
    long long len, a;
    ans = n;    // i = 1 的情况
    if(k > n){
        ans += k - n;
        k = n;
    }
    for(long long i  = 2; i <= k; i = a + 1){
        a = n/(n/i);
        if(a > k) a = k;
        len = a - i + 1;
        ans += len*((n/i)*2+1);
        ans %= MOD;
    }
    long long cnt = 1, b;
    for(long long i = 2; i <= n; i++){
        b = 0;
        for(;;){
            if(n%i == 0){
                ++b;
                n = n/i;
            }
            else{
                cnt *= b+1;
                break;
            }
        }
    }
    --cnt;
    cnt %= MOD;
    ans = (ans + MOD - cnt) % MOD;
    cout<<ans<<endl;
    system("pause");
    return 0;
}