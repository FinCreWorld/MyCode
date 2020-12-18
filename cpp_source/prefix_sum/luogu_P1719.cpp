/*
 * 2020.10.4 T2 106
 * jcy
 * 求最大矩形
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 122;
const int INF = 0xffffffff;
int ps[maxn][maxn]; // the sum of prefix
int subMatrix[maxn], ans;
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%d", &ps[i][j]);
    for(int j = 1; j <= n; ++j){
        for(int i = 1; i <= n; ++i){
            ps[i][j] += ps[i-1][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            int tmp = INF, s;
            for(int k = 1; k <= n; ++k){
                s = ps[j][k] - ps[i-1][k];
                subMatrix[k] = max(subMatrix[k-1] + s, s);
            }
            for(int k = 1; k <= n; ++k){
                tmp = max(tmp, subMatrix[k]);
            }
            ans = max(ans, tmp);
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}