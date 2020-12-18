/*
 * H F3 室外自习室 2020.12.3
 * jcy
 * 三国游戏，偏博弈论，有点难以理解，说不清楚
 */
#include <iostream>
using namespace std;
const int maxn = 505;
int a[maxn][maxn];
int main(){
    int n;
    int x, y, ans = 0;;
    cin>>n;
    for(int i = 1; i < n; ++i){
        for(int j = i + 1; j <= n; ++j){
            cin>>a[i][j];
            a[j][i] = a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        x = y = 0;
        for(int j = 1; j <= n; ++j){
            if(a[i][j] > x){
                y = x;
                x = a[i][j];
            }else if(a[i][j] > y){
                y = a[i][j];
            }
        }
        ans = max(ans, y);
    }
    cout<<1<<endl;
    cout<<ans<<endl;
    system("pause");
    return 0;
}