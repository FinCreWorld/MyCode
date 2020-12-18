/*
 * 2020.9.19 T2 106
 * jcy
 * gcd
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL x, LL y){
    if(y == 0) return x;
    return gcd(y, x%y);
}
LL lcm(LL x, LL y){
    return x*y/gcd(x, y);
}
int main(){
    int x, y, z;
    cin>>x>>y>>z;
    cout<<lcm(lcm(x, y), z)<<endl;
    system("pause");
    return 0;
}