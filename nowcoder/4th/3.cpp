#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const int MOD = 1000000007;
typedef long long LL;
int a[maxn];
int get(int n){
    if(a[n]) return a[n];
    else{
        int num = n;
        for(int i = 2; i < num; i++){
            while(num!=2)
                if(num%i == 0){
                    a[n]++;
                    num = num/i;
                }
                else break;
        }
    }
    return a[n];
}
LL q_mul(LL m, LL n){
    LL ans = 0;
    while(n){
        if(n&1LL) ans = (ans+m)%MOD;
        m = (m+m)%MOD;
        n >>= 1;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    int c, n, b, ans = 0;
    while(t--){
        scanf("%d %d", &n, &c);
        ans = c;
        b = get(n);
        //cout<<b<<endl;
        for(int i = 0; i < b; i++)
            ans = q_mul(c, c);
        printf("%d\n", ans);
    }
    return 0;
}