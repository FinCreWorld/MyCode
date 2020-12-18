/*
 * 2020.9.12
 * 洛谷
 * 最大子序列和
 */
#include<iostream>
#include<cstdio>
#include<ctype.h>
using namespace std;
const int maxn = 200005;
int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x*f;
}
int main(){
    int n, a, b[maxn];
    n = read(); a = read();
    b[0] = a;
    for(int i = 1; i < n; ++i){
        a = read();
        b[i] = max(b[i-1] + a, a);
    }
    int ans = b[0];
    for(int i = 1; i < n; ++i){
        if(b[i] > ans) ans = b[i];
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}