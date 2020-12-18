#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}
int main(){
    int a[maxn];
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
    }
    int k = 1;
    int num = 0;
    for(int i = 1; i <= n; ++i){
        k = gcd(k, a[i]);
        num = max(num, a[i]);
    }
    num /= k;
    num -= n;
    if(num&1){
        cout<<"Alice\n";
    }else cout<<"Bob\n";
    system("pause");
    return 0;
}