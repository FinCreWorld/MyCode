/*
 * 2020.9.15 T2 106
 * jcy 车的攻击
 * 我是使用哈希解决，但是可以通过unique函数进行去重（需要先排序）
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int row[maxn];
int col[maxn];
int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
void insert(int n, int *a, long long &num){
    int i = n%maxn;
    if(!a[i]) a[i] = n, ++num;
    else{
        while(a[i] != n && a[i]) i = (i+1)%maxn;
        if(!a[i]) a[i] = n, ++num;
    }
}
int main(){
    int n, k, a, b;
    long long p = 0, q = 0;
    n=read(); k=read();
    for(int i = 0; i < k; ++i){
        a = read(); b = read();
        insert(a, row, p); insert(b, col, q);
    }
    cout<<p*n+q*n-p*q<<endl;
    system("pause");
    return 0;
}