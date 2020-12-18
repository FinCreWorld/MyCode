/*
 * 2020.9.13
 * 洛谷 编号
 * 取模运算
 */
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 51;
const int MOD = 1000000007;
int main(){
    int n, a[maxn];
    cin>>n;
    for(int i = 0; i < n; ++i) cin>>a[i];
    sort(a, a+n);
    long long ans = 1, b = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] - b <= 0){
            ans = 0;
            break;
        }else{
            ans *= (a[i] - b);
            ans %= MOD;
            ++b;
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}