/*
 * 2020.10.4 T2 106
 * jcy
 * 定长最大值与前缀和
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
typedef long long ll;
ll a[maxn], ans;
int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 1; i < n; ++i){
        scanf("%d", &a[i]);
        ans += a[i];
        a[i] += a[i-1];
    }
    ll tmp = 0;
    for(int i = 0; i <= n - k - 1; ++i){
        tmp = max(tmp, a[i+k] - a[i]);
    }
    cout<<ans - tmp<<endl;
    system("pause");
    return 0;
}