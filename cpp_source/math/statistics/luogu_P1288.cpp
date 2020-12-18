/*
 * H F3 室外自习室，2020.12.3
 * jcy
 * 取数游戏，使用逼迫策略
 */
#include <iostream>
using namespace std;
int main(){
    int n, ans = 0, x, a = 0, b;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>x;
        if(!x){
            if(!a) a = i;
            b = i;
        }
    }
    if((~a&1) || ((n-b)&1)) cout<<"YES\n";
    else cout<<"NO\n";
    system("pause");
    return 0;
}