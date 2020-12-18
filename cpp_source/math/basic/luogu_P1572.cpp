/* 2020.9.19 T2 106
 * jcy
 * 计算分数式之和
 */
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef struct Frac{
    LL x;
    LL y;
}Frac;
Frac a, b;

LL gcd(LL x, LL y){
    if(y == 0) return x;
    else return gcd(y, x%y);
}
LL lcm(LL x, LL y){
    return x*y/gcd(x, y);
}
void simplify(Frac &frac){
    int a = gcd(abs(frac.x), abs(frac.y));
    frac.x /= a;
    frac.y /= a;
}
int main(){
    char ch;
    LL lcmNum;
    scanf("%lld/%lld", &a.x, &a.y);
    simplify(a);
    // cout<<a.x<<" "<<a.y<<endl;
    for(;;){
        ch = getchar();
        if(ch!='+' && ch!='-') break;
        scanf("%lld/%lld", &b.x, &b.y);
        simplify(b);
        lcmNum = lcm(abs(a.y), abs(b.y));
        if(ch == '+')
            a.x = a.x*lcmNum/a.y+b.x*lcmNum/b.y;
        else
            a.x = a.x*lcmNum/a.y-b.x*lcmNum/b.y;
        // cout<<a.x<<" "<<a.y<<endl;
        a.y = lcmNum;
    }
    simplify(a);
    // cout<<(a.x%a.y)<<endl;
    if(!(a.x%a.y)) cout<<a.x/a.y<<endl;
    else cout<<a.x<<"/"<<a.y<<endl;
    system("pause");
    return 0;
}