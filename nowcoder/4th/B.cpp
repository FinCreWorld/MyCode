#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const int MOD = 1000000007;
int a[maxn];
void get(){
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    for(int i = 2; i < maxn; i++){
        for(int j = 1; i*j < maxn && j <= i; j++){
            if(!a[i*j]) a[i*j] = a[i]+a[j];
        }
    }
}
int main(){
    // freopen("output.txt", "w", stdout);
    get();
    // for(int i = 0; i < maxn; i++){
    //     printf("%d %d\n", i, a[i]);
    // }
    int t;
    cin>>t;
    long long n, c;
    while(t--){
        scanf("%d %d", &n, &c);
        long long ans = 1;
        if(n == 1)
            ans = 1;
        else{
            for(int i = 0; i < a[n]; i++){
                if(ans*c > MOD){
                    ans = (ans%MOD * c) % MOD;
                }
                else ans *= c;
            }
            
        }
        printf("%d\n", ans);
    }
    //system("pause");
    return 0;
}