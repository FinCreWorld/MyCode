/*
 * 2020.10.19 T2 106
 * jcy
 * 幂数取模
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef unsigned long long ULL;
const int maxn = 1e3+5;
ULL f[maxn*maxn];
ULL t, n;
ULL a, b, T;
void getCycle(ULL n){
    ULL x, y, m, tmp;
    m = n*n;
    f[0] = 0ull; f[1] = 1ull;
    for(int i = 2; i <= m; ++i){
        f[i] = (f[i-1] + f[i-2]) % n;
        if(f[i-1] == 0 && f[i] == 1){
            T = i - 1;
            break;
        }
    }
    // cout<<"T:"<<T<<endl;
}
ULL getMod(ULL a, ULL b, ULL m){
    if(!b) return 1ull;
    ULL ans = getMod(a, b/2, m);
    ans = ans * ans % m;
    if(b&1) ans = ans * a % m;
    return ans;
}
ULL fun(ULL a, ULL b, ULL n){
    if(a == 0 || n == 1) return 0;
    getCycle(n);
    // 注意，此处入口参数需要使用 a%T 进行优化
    ULL mod = getMod(a%T, b, T);
    // cout<<mod<<" "<<q<<endl;
    return f[mod];
}
int main(){
    ULL ans;
    scanf("%llu", &t);
    while(t--){
        scanf("%llu %llu %llu", &a, &b, &n);
        // cout<<n<<endl;
        // printf("%ull %ull %d", a, b, n);
        ans = fun(a, b, n);
        printf("%llu\n", ans);
    }
    system("pause");
    return 0;
}