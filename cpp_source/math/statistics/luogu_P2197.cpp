/*
 * H F3 室外自习室，2020.12.3
 * jcy
 * Nim 游戏简单模板
 * 今日心情不佳，数字逻辑搞我心态
 */
#include <bits/stdc++.h>
using namespace std;
int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int main(){
    int t, n;
    int x = 0, y;
    t = read();
    while(t--){
        n = read();
        x = 0;
        while(n--){
            y = read();
            x ^= y;
        }
        if(x) printf("Yes\n");
        else printf("No\n");
    }
    system("pause");
    return 0;
}