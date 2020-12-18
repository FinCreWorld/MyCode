#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+3;
int ans[maxn][maxn];
int main(){
    int n, m;
    int x, y, p, q;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d %d", &x, &y, &p, &q);
        ++q;
        for(int j = x; j <= p; ++j){
            ++ans[j][y];
            --ans[j][q];
        }
    }
    for(int i = 1; i <= n; ++i){
        int cnt = 0;
        cnt += ans[i][1];
        printf("%d", cnt);
        for(int j = 2; j <= n; ++j){
            cnt += ans[i][j];
            printf(" %d", cnt);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}