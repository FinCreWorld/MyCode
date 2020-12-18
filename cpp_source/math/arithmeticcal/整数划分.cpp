/*
 * 2020.9.15
 * jcy T2 106
 * 直线交点数，转化为整数划分问题
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 30;
int a[maxn][maxn];
int dp(int n, int m){
    if(a[n][m]) return a[n][m];
    if(n == 1 || m == 1){
        a[n][m] = 1;
    }else if(n == m){
        a[n][m] = 1 + dp(n, m-1);
    }else if(n > m){
        a[n][m] = dp(n-m, m) + dp(n, m-1);
    }else{
        a[n][m] = dp(n, n);
    }
    return a[n][m];
}
int main(){
    int n;
    cin>>n;
    cout<<dp(n, n)<<endl;
    system("pause");
    return 0;
}