/*
 * 2020.10.7 T2 106
 * jcy
 * P1955 把我做吐了, 一堆bug,,,
 * 双指针法
 */
#include <bits/stdc++.h>
using namespace std;
int read(){
    char ch=getchar();int x=0;
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
const int maxn = 1e6+5;
const int maxm = 2e3+5;
int a[maxn], b[maxm];
int n, m;
int main(){
    n = read(); m = read();
    for(int i = 1; i <= n; ++i){
        a[i] = read();
    }
    int l = 1, r = 1, minl = 1, minr = 1;
    ++b[a[1]];
    int cnt = 1;
    while(cnt < m){
        ++r, ++b[a[r]];
        if(b[a[r]] == 1) ++cnt;
    }
    minr = r;
    while(b[a[l]] > 1) --b[a[l]], ++l;
    minl = l;
    while(r < n){
        ++r;
        ++b[a[r]];
        while(b[a[l]] > 1) --b[a[l]], ++l;
        if(r - l < minr - minl){
            minl = l;
            minr = r;
        }
    }
    cout<<minl<<" "<<minr<<endl;
    system("pause");
    return 0;
}