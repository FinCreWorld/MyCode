#include<iostream>
#include<algorithm>

using namespace std;

// 两种离散化的代码
const int N = 1e5 + 7;
// 可以用于处理重复元素
int discrete1(){
    int t[N], a[N];
    int n, m;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
        t[i] = a[i];
    }
    sort(t+1, t+n+1);
    m = unique(t+1, t+n+1) - t - 1;
    for(int i = 1; i <= n; ++i){
        a[i] = lower_bound(t+1, t+m+1, a[i]) - t;
    }
    return m;
}

struct Node{
    int v, id;
    bool operator < (const Node a) const{
        return v < a.v;
    }
}b[N];
void discrete2(){
    int n, rank[N];
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>b[i].v;
        b[i].id = i;
    }
    sort(b+1, b+n+1);
    for(int i = 1; i <= n; ++i){
        rank[b[i].id] = i;
    }
}
int main(){
    system("pause");
    return 0;
}