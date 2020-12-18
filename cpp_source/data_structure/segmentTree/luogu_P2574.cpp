/*
 * 2020.9.23 T2 106
 * jcy
 * 线段树水题——异或
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n, m, op, l, r;
bool a[maxn];
int d[maxn<<2], b[maxn<<2];
void push_up(int p){
    d[p] = d[p<<1] + d[(p<<1)+1];
}
// 用于改变节点的状态
void change(int s, int t, int p){
    d[p] = t - s + 1 - d[p];
    b[p] ^= 1;
}
// 用于将状态向子节点传递
void push_down(int s, int t, int p){
    if(s != t && b[p]){
        int m = (s + t)/2;
        change(s, m, p<<1);
        change(m+1, t, (p<<1)+1);
        b[p] = 0;
    }
}
void build(int s, int t, int p){
    if(s == t){
        d[p] = a[s];
        return;
    }
    int m = (s+t)/2;
    build(s, m, p<<1), build(m+1, t, (p<<1)+1);
    push_up(p);
}
void update(int l, int r, int s, int t, int p){
    if(l<=s && t<=r){
        change(s, t, p);
        return;
    }
    int m = (s + t)/2;
    push_down(s, t, p);
    if(m >= l) update(l, r, s, m, p<<1);
    if(m < r) update(l, r, m+1, t, (p<<1)+1);
    d[p] = d[p<<1] + d[(p<<1)+1];
}
int getsum(int l, int r, int s, int t, int p){
    if(l<=s && t<=r){
        return d[p];
    }
    int m = (s + t)/2;
    push_down(s, t, p);
    // 要记得初始化为 0
    int sum = 0;
    if(m >= l) sum = getsum(l, r, s, m, p<<1);
    if(m < r) sum += getsum(l, r, m+1, t, (p<<1)+1);
    return sum;
}
int main(){
    scanf("%d %d", &n, &m);
    string str;
    cin>>str;
    for(int i = 1; i <= n; ++i){
        a[i] = str[i-1]-'0';
    }
    build(1, n, 1);
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &op, &l, &r);
        if(op){
            printf("%d\n", getsum(l, r, 1, n, 1));
        }else{
            update(l, r, 1, n, 1);
        }
    }
    system("pause");
    return 0;
}