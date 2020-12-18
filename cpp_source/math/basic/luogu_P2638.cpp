/*
 * 2020.9.16 寝室
 * jcy 安全系统
 * 杨辉三角，排列组合，暴力
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
typedef unsigned long long ULL;
ULL c[maxn][maxn];  // a[i][j] 表示组合数 (i, j)
int a, b;
// 产生组合数
void generate(int n){
    for(int i = 1; i <= n; ++i){
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
}
int main(){
    ULL ans = 0;
    int n;
    cin>>n>>a>>b;
    generate(max(a+n, b+n));
    for(int i = 0; i <= a; ++i){
        for(int j = 0; j <= b; ++j){
            ans += 1ull* c[i-1+n][n-1] * c[j-1+n][n-1];
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}