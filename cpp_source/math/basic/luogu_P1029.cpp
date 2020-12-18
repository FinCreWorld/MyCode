/* 2020.9.19
 * T2 106
 * 质因数分解
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef long long LL;
const LL maxn = 100005;
LL index1[maxn];    // 用来存储因数的指数
LL index2[maxn];
void getIndex(LL *index, LL x){
    LL p = 2;
    while(x != 1){
        if(x%p) ++p;
        else{
            ++index[p];
            x /= p;
        }
    }
}
int main(){
    LL x, y, flag = 1;
    long long ans = 1;
    cin>>x>>y;
    getIndex(index1, x);
    getIndex(index2, x*y);
    for(LL i = 2; i <= y; ++i){
        if(index2[i] && index2[i]>2*index1[i]){
            ans <<= 1;
        }
        if(index2[i] < 2*index1[i]){
            flag = 0;
            break;
        }
    }
    if(flag) cout<<ans<<endl;
    else cout<<0<<endl;
    system("pause");
    return 0;
}