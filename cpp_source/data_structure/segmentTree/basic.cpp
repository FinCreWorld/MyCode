/* 
 * 2020.9.19 T2 106
 * jcy
 * 为了临时抱佛脚，跳了一下进度
 * 提前接触一下线段树
 */
#include<bits/stdc++.h>

using namespace std;

const int maxn = 100;
int a[maxn], d[maxn<<2], b[maxn<<2];

// 为一个数组建立线段树
void build(int s, int t, int p){
    // 对 [s, t] 区间进行建树，区间编号为 p
    if(s == t){
        d[p] = a[s];
        return;
    }
    int m = (s+t)/2;
    build(s, m, 2*p), build(m+1, t, 2*p+1);
    d[p] = d[p*2] + d[p*2+1];
}

// 得到任意区间的和
int getsum(int l, int r, int s, int t, int p){
    // l,r 为查询的区间，s,t 为当前节点包含的区间，p 为当前节点的编号
    if(l<=s && t<=r)
        return d[p];
    int m = (s + t)/2, sum = 0;
    if(l <= m) sum += getsum(l, r, s, m, p*2);
    if(r > m) sum += getsum(l, r, m+1, t, p*2+1);
    return sum;
}

// 区间加上某一个值
void update(int l, int r, int c, int s, int t, int p){
    // [l,r] 为要修改的区间，c 为修改量，[s,t] 为当前节点所在的区间
    // p 为当前节点的编号
    if(l <= s && t <= r){
        d[p] += c*(t - s + 1), b[p] += c;
        return;
    }// 当前区间为修改区间的子集，直接修改该区间的值，并返回

    int m = (s + t)/2;
    if(b[p] && s != t){ // 当其为叶子节点时，无法下移懒惰标记
        // 当前节点并非待修改区间子集，且存在懒惰标记
        // 那么需要将懒惰标记下移，使懒惰标记向待修改区间子集靠近
        d[p*2] += b[p] * (m - s + 1), d[p*2+1] += b[p] * (t - m);
        b[p*2] += b[p], d[p*2+1] += b[p];
        b[p] = 0;   // 下传标记，当前节点标记
    } 
    if(l <= m) update(l, r, c, s, m, p*2);
    if(r > m)  update(l, r, c, m+1, t, p*2+1);
    d[p] = d[2*p] + d[2*p+1];
}

// 查询懒惰节点的值
int getsum(int l, int r, int s, int t, int p){
    // [l,r] 为要查询的区间，[s,t] 为当前区间，p 为当前节点的编号
    if(l <= s && t <= r) return d[p];
    int m = (s + t)/2, sum = 0;
    if(b[p] && s != t){
        d[p*2] += b[p]*(m - s + 1), d[p*2+1] += b[p]*(t - m);
        b[p*2] += b[p], b[p*2+1] += b[p];
        b[p] = 0;
    }
    if(l <= m) sum += (l, r, s, m, p*2);
    if(r > m)  sum += (l, r, m+1, t, p*2+1);
    return sum;
}

// 修改某一区间的值而不是加上某一个值
void update(int l, int r, int s, int t, int c, int p){
    if(l <= s && t <= r){
        d[p] = c*(t - s + 1), b[p] = c;
        return;
    }
    int m = (s + t) / 2;
    if(b[p] && s!=t){
        d[2*p] = b[p]*(m - s + 1), d[2*p+1] = b[p]*(t - m);
        b[2*p] = b[2*p+1] = b[p];
        b[p] = 0;
    }
    if(l <= m) update(l, r, s, m, c, 2*p);
    if(m < r) update(l, r, m+1, t, c, 2*p+1);
    d[p] = d[2*p] + d[2*p+1];
}
int getsum(int l, int r, int s, int t, int p){
    if(l <= s && t <= r) return d[p];
    int m = (s + t) / 2;
    if(b[p] && s!=t){
        d[2*p] = b[p]*(m - s + 1), d[2*p+1] = b[p]*(t - m);
        b[2*p] = b[2*p+1] = b[p];
        b[p] = 0;
    }
    int sum = 0;
    if(l <= m) sum = getsum(l, r, s, m, 2*p);
    if(m <= r) sum += getsum(l, r, m+1, t, 2*p+1);
    return sum;
}