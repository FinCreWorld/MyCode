/*
 * 2020.9.25 T2 106
 * jcy
 * 最长公共子序列问题转化为lis问题，通过二分进行优化
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 1e5+5;
const int INF = 0xfffffff;
int a[maxn], b[maxn], map[maxn], dp[maxn];
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++i){
        scanf("%d", &b[i]);
        map[b[i]] = i;
    }
    for(int i = 1; i <= n; ++i){
        a[i] = map[a[i]];
    }
    for(int i = 1; i <= n; ++i) dp[i] = INF;
    dp[1] = a[1];
    int len = 1;
    for(int i = 2; i <= n; ++i){
        int l = 0, r = len, mid;
        if(a[i] > dp[len]){
            dp[++len] = a[i];
        }else{
            while(l < r){
                mid = (l + r)/2;
                if(dp[mid] > a[i]) r = mid;
                else l = mid+1;
            }
            // 用于排除重复数字的影响
            if(a[i] == dp[l-1]) continue;
            dp[l] = a[i];
        }
    }
    cout<<len<<endl;
    system("pause");
    return 0;
}