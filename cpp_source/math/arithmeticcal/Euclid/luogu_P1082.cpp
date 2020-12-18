/*
 * 2020.10.21 T2 106
 * jcy
 * 将同余方程的求解转化为解欧几里得方程
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll a, b, x, y;
void exgcd(ll a, ll b, ll& x, ll& y){
    if(b == 0){x = 1; y = 0;}
    else{exgcd(b, a%b, y, x); y -= a/b*x;}
}
int main(){
    cin>>a>>b;
    exgcd(a, b, x, y);
    cout<<((x % b + b) % b)<<endl;
    system("pause");
    return 0;
}