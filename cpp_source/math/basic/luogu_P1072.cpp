/*
 * 2020.10.3 T2 106
 * jcy
 * 因数分解（非质因数），gcd以及lcm逆应用
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int factor[maxn];   // 用来存储 b 的因子
int cnt = 0;
int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
// 注：此处的因子不能是质因子
void getFactor(int x){
    cnt = 0;
    for(int i = 1; i * i <= x; ++i){
        if(!(x%i)){
            factor[cnt++] = i;
            if(i * i != x) factor[cnt++] = x/i;
        }
    }
}
int gcd(int x, int y){
    return y ? gcd(y, x%y) : x;
}
int main(){
    int t;
    int a0, a1, b0, b1;
    t = read();
    while(t--){
        a0 = read(), a1 = read();
        b0 = read(), b1 = read();
        int a = a0/a1, b = b1/b0;
        int ans = 0;
        // cout<<a<<" "<<b<<endl;
        getFactor(b1);
        // for(int i = 0; i < cnt; ++i) cout<<factor[i]<<" ";cout<<endl;
        for(int i = 0; i < cnt; ++i){
            int x = factor[i];
            // cout<<x % a1<<" "<<gcd(x/a1, a)<<" "<<gcd(b, b1/x)<<endl;
            if(x % a1 == 0 && gcd(x/a1, a) == 1 
                && gcd(b, b1/x) == 1)
                ++ans;
        }
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}