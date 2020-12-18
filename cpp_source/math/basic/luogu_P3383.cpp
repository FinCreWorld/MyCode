/* 2020.9.19 T2 106
 * jcy 线性筛素数
 */
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn = 100000005;
bool is_prime[maxn];
int prime[maxn];
int read(){
    int x=0; char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int Euler(int n){
    int p = 0;
    for(int i = 0; i <= n; ++i) is_prime[i] = true;
    for(int i = 2; i <= n; ++i){
        if(is_prime[i]) prime[++p] = i;
        for(int j = 1; j <= p; ++j){
            if(prime[j]*i > n) break;
            is_prime[prime[j]*i] = false;
            if(!i%prime[j]) break;
        }
    }
    return p;
}
int main(){
    int n, q, k;
    n = read(); q = read();
    Euler(n);
    for(int i = 0; i < q; ++i){
        k = read();
        printf("%d\n", prime[k]);
    }
    system("pause");
    return 0;
}