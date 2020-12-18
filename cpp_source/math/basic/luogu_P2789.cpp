/*
 * 2020.9.15
 * jcy T2 106
 * 直线交点数，转化为整数划分问题
 * 
 * 2020.9.29
 * jcy T2 106
 * 使用整数划分不行，需要使用dp来写
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int ans = 0, vis[maxn];
void dp(int p, int m){
    if(!p && !vis[m]) ++ans, vis[m] = 1;
    else{
        for(int i = 1; i <= p; ++i){
            dp(p-i, m + i*(p-i));
        }
    } 
}
int main(){
    int n;
    cin>>n;
    dp(n, 0);
    cout<<ans<<endl;
    system("pause");
    return 0;
}