#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int a[maxn], q[maxn];
int n, m;
int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int l, r;
    l = r = 1;
    q[1] = 1;
    cout<<"0"<<endl;
    for(int i = 2; i <= n; ++i){
        if(i - 1 - q[l] >= m) ++l;
        while(l <= r && a[q[r]] >= a[i-1]) --r;
        q[++r] = i - 1;
        printf("%d\n", a[q[l]]);
    }
    system("pause");
    return 0;
}