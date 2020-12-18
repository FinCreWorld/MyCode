/*
 * 2020.9.12
 * 洛谷 找筷子 异或运算
 * 蒋晨阳
 */
#include<cstdio>
#include<cstdlib>
#include<ctype.h>
int read(){
    int x = 0; char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int main(){
    int n, a = 0, b;
    n = read();
    for(int i = 0; i < n; ++i)
        a ^= (b=read());
    printf("%d\n", a);
    system("pause");
    return 0;
}