// 使用双向静态链表
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct A{
    int last;
    int next;
}a[maxn];
int main(){
    // freopen("test.in", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, m, k, p;
    cin>>n;
    for(int i = 0; i <= n; i++){
        a[i].last = a[i].next = 0;
    }
    a[0].next = 1;
    for(int i = 2; i <= n; i++){
        cin>>k>>p;
        if(!p){
            a[a[k].last].next = i;
            a[i].last = a[k].last;
            a[i].next = k;
            a[k].last = i;
        }
        else{
            a[a[k].next].last = i;
            a[i].next = a[k].next;
            a[i].last = k;
            a[k].next = i;
        }
    }
    cin>>m;
    int d;
    while(m--){
        cin>>d;
        if(!a[d].next && !a[d].last) continue;  // 对于删除的点一定要标记并判断
        a[a[d].last].next = a[d].next;
        a[a[d].next].last = a[d].last;
        a[d].next = a[d].last = 0;
    }
    int cur = a[0].next;
    while(cur){
        cout<<cur<<" ";
        cur = a[cur].next;
    }
    cout<<endl;
    return 0;
}