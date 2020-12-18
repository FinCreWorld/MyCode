/*
 * 2020.10.22 T2 106
 * jcy
 * 中国剩余定理基础模板(模数之间不互质)
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long LL;
const int maxn = 12;
void exgcd(LL a, LL b, LL&x, LL& y){
    if(!b) {x=1;y=0;}
    else {exgcd(b, a%b, y, x);y-=a/b*x;}
}
int main(){
    int n;
    LL a[maxn], b[maxn], sumN = 1, m, c, tmp, ans = 0;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>a[i]>>b[i];
        sumN *= a[i];
    }
    for(int i = 1; i <= n; ++i){
        m = sumN / a[i];
        exgcd(m, a[i], c, tmp);
        c = (c % a[i] + a[i]) % a[i];
        ans = (ans + c * m * b[i]) % sumN;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
/*
 * 总结，第一次错误的原因；使用 exgcd 得到的逆元未必为正数
 * 需要将其转化为正数
 */