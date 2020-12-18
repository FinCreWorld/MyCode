/*
 * 2020.10.21 T2 106
 * jcy
 * 使用 exgcd 得到乘法逆元
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int maxn = 3e6+5;
ll inv[maxn];
int main(){
    ll n, p, x, y;
    cin>>n>>p;
    inv[1] = 1; puts("1");
    for(int i = 2; i <= n; ++i){
        inv[i] = (p - p/i)*inv[p % i]%p;
        printf("%d\n", inv[i]);
    }
    system("pause");
    return 0;
}
/* 总结
 * 使用同余方程解法 TLE 了一个点
 * 使用快速幂解法 TLE 了两个点
 * 正解应该还是使用线性求逆元啊
 */