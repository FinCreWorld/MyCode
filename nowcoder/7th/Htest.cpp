#include<iostream>
#include<cstdio>
using namespace std;
const int MOD = 1000000007;
const long long BIG = (1<<60);
int main(){
    long long n, k, m;
    long long ans = 0;
    int last = 0;
    for(;;){
        cin>>n>>k;
        ans = 0;
            for(int i = 1; i <= k && i <= n; i++){
                if(i == 1) ans += n;
                else if(n%i == 0)
                    ans += n/i*2;
                else
                    ans += n/i*2+1;
                // if(ans > BIG) ans = ans%MOD;
            }
            if(n <= k) ans += k-n;
            ans %= MOD;
            cout<<ans<<" "<<ans-last<<endl;
            last = ans;
    }
    return 0;
}