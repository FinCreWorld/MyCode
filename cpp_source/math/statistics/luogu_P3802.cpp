/*
 * 2020.12.2 H308
 * jcy
 * 小魔女帕琪 独立期望的可加性，期望的求和
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[7];
    int sum = 0;
    double ans = 1;
    for(int i = 0; i < 7; ++i) cin>>a[i], sum += a[i];
    for(int i = 0; i < 7; ++i){
        ans *= a[i];
        ans /= sum - i;
    }
    if(sum < 7) printf("0.000\n");
    else printf("%.3lf\n", ans*(sum-6)*5040);
    system("pause");
    return 0;
}