/*
 * 2020.10.7 T2 106
 * jcy
 * 贪心、线性
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e4+1;
int a[maxn], n, k;
int read(){
    char ch=getchar();int x=0;
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int getMax(){
    int i, j, s, t, l, r;
    i = j = l = r = 1;
    s = 0;
    while(j <= n){
        while(j <= n && a[j] - a[i] <= k) ++j;
        if(j - i > s){
            l = i, r = j;
            s = r - l;
        }
        while(a[j] - a[i] > k) ++i;
    }
    int m = r - l;
    for(i = l; i <= n - m; ++i)
        a[i] = a[i + m];
    n -= m;
    return s;
}
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    n = read(); k = read();
    for(int i = 1; i <= n; ++i){
        a[i] = read();
    }
    sort(a+1, a+n+1);
    cout<<getMax() + getMax()<<endl;
    system("pause");
    return 0;
}