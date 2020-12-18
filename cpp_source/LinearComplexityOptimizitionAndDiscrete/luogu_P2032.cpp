/*
 * 2020.10.5 T2 106
 * jcy
 * 滑动窗口法的模板题
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+5;
int a[maxn], q[maxn], l, r;
int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    l = r = 1;
    q[1] = 1;
    for(int i = 2; i < k; ++i){
        while(l <= r && a[q[r]] <= a[i]) --r;
        q[++r] = i;
    }
    for(int i = k; i <= n; ++i){
        if(i - q[l] >= k) ++l;
        while(l <= r && a[q[r]] <= a[i]) --r;
        q[++r] = i;
        cout<<a[q[l]]<<endl;
    }
    system("pause");
    return 0;
}