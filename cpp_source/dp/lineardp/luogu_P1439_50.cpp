/*
 * 2020.9.25 T2 106
 * jcy
 * 求最长公共子序列，使用递推算法会tle
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 3;
int n;
int a[maxn], b[maxn], dp[maxn];
int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int main(){
    int tmp = 0, last = 0;
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    for(int i = 1; i <= n; ++i) b[i] = read();
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            tmp = dp[j];
            if(a[i] == b[j]) dp[j] = last + 1;
            else dp[j] = max(dp[j], dp[j-1]);
            last = tmp;
        }
        last = 0;
    }
    printf("%d\n", dp[n]);
    system("pause");
    return 0;
}