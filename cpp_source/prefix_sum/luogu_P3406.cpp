/*
 * 2020.10.4 14:06 T2 106
 * jcy
 * 差分
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+2;
typedef long long ll;
int a[maxn], b[maxn], c[maxn];
int num[maxn];
int n, m, x, last, cnt;
ll ans;
int main(){
    scanf("%d %d", &n, &m);
    scanf("%d", &last);
    for(int i = 1; i < m; ++i){
        scanf("%d", &x);
        if(x < last){
            ++num[x];
            --num[last];
        }else{
            ++num[last];
            --num[x];
        }
        last = x;
    }
    for(int i = 1; i < n; ++i){
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }
    
    for(int i = 1; i < n; ++i){
        cnt += num[i];
        ans += min(1ll*cnt*a[i], c[i]+1ll*cnt*b[i]);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}