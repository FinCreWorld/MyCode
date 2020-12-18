#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 200005;
long long a[maxn];
long long dp[maxn];
int getmin(int n){
    int p, q;
    dp[4] = a[3]+a[2]-a[1]-a[0];
    if(n == 4) return dp[4];
    dp[6] = a[2]+a[4]+a[5]-a[0]-a[1]-a[3];
    if(n == 6) return dp[6];
    for(int i = 8; i <= n; i += 2){
        p = a[i-1] + a[i-2] - a[i-3] - a[i-4];
        q = a[i-1] + a[i-2] + a[i-4] - a[i-3] - a[i-5] - a[i-6];
        if(i == 8) dp[i] = dp[4] + p;
        else dp[i] = min(dp[i-4] + p, dp[i-6] + q);
    }
    return dp[n];
}
int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++)
            cin>>a[i];
        sort(a, a+n);
        long long cost1 = 0, cost2;
        for(int i = 0; i < n; i++)
            if(i%2) cost1 += a[i] - a[i-1];
        cost2 = getmin(n);
        cout<<cost1+cost2<<endl;
    }
    return 0;
}