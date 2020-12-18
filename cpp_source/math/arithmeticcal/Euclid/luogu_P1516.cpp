/*
 * 2020.10.20 T2 106
 * jcy
 * 拓展欧几里得算法，包含负数情况
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
    return (!b) ? a : gcd(b, a % b);
}
// 我的代码
void exgcd(ll a, ll b, ll& d, ll& x, ll& y){
    if(!b) {d = a; x = 1; y = 0;}
    else {exgcd(b, a % b, d, y, x); y -= a/b*x;}
}
// // 别人的代码
// int tmp;
// void exgcd(ll a, ll b, ll& d, ll& x, ll& y){
// 	if(!b){x=1;d=a;return;}//顺便求gcd
// 	exgcd(b, a%b, d, x, y);
// 	tmp=x;x=y;y=tmp-a/b*x;
// }
int main(){
    // 用来得到输入数据
    ll x, y, m, n, l;
    // 用来存储方程求解相关数据
    ll a, b, t, c, d, k;
    cin>>x>>y>>m>>n>>l;
    a = n - m;
    b = l;
    c = x - y;
    if(a < 0) a = -a, c = -c;
    exgcd(a, b, d, t, k);

    if(c % d) cout<<"Impossible\n";
    else cout<<(c/d*t%(b/d)+b/d)%(b/d)<<endl;
    system("pause");
    return 0;
}
/*
 * 总结：
 * 使用扩展 gcd 时，代码中的 y -= x*a/b
 * 可以优化称为 y -= a/b*x
 * 因为公式推导中的 a/b 本来就是要是取整的
 * 故前后关系无影响
 */