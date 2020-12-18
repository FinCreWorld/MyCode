/* 
 * 2020.9.19 T2 106
 * jcy
 * gcd 的应用
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL x, LL y){
    if(!y) return x;
    return gcd(y, x%y);
}
template <typename T>
inline T read(T &x){
    T f=1;char ch=getchar();x=0;
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int main(){
    char ch;
    LL x, y, n, m;
    read(n);
    while(n--){
        read(m);
        read(x);read(y);
        y /= gcd(x, y);
        for(LL i = 2; i < m; ++i){
            read(x);
            if(y != 1) y /= gcd(x, y);
        }
        if(y == 1) printf("Yes\n");
        else printf("No\n");
    }
    system("pause");
    return 0;
}