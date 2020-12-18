#include<bits/stdc++.h>
using namespace std;
const int maxn = 1003;
typedef long long ll;
int n, m, c;
ll w[maxn][maxn];    // The weight of territory.
int main(){
    ll ans = 0xffffffffffffffff, x = 0, y = 0;
    cin>>n>>m>>c;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%lld", &w[i][j]);
        }
    }
    for(int j = 1; j <= m; ++j){
        for(int i = 1; i <= n; ++i){
            w[i][j] += w[i-1][j] + w[i][j-1] - w[i-1][j-1];
        }
    }
    for(int i = n; i >= c; --i){
        for(int j = m; j >= c; --j){
            w[i][j] -= w[i-c][j] + w[i][j-c] - w[i-c][j-c];
            if(w[i][j] >= ans){
                x = i - c + 1;
                y = j - c + 1;
                ans = w[i][j];
            }
        }
    }
    cout<<x<<" "<<y<<endl;
    system("pause");
    return 0;
}