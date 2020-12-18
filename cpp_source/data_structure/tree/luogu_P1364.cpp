// 树的重心模板题
#include<iostream>
using namespace std;
const int maxn = 105;
int tsize[maxn]; // size[i] 表示以点 i 为根的子树的所有结点权值和
int f[maxn];    // f[i] 表示各个节点到 i 的花费和
int ans = 0x7fffffff, tmp = 0;
struct A{
    A():l(0),r(0),num(0){}
    int l, r, num;
}a[maxn];
int getsize(int p){
    if(!p) return 0;
    tsize[p] = getsize(a[p].l) + getsize(a[p].r) + a[p].num;
    return tsize[p];
}
void dfs(int p, int h){
    if(!p) return;
    tmp += h*a[p].num;
    dfs(a[p].l, h+1);
    dfs(a[p].r, h+1);
}
void getmin(int p, int tmp){
    if(!p) return;
    ans = min(ans, tmp);
    getmin(a[p].l, tmp+tsize[1]-tsize[a[p].l]-tsize[a[p].l]);
    getmin(a[p].r, tmp+tsize[1]-tsize[a[p].r]-tsize[a[p].r]);
}
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].num>>a[i].l>>a[i].r;
    }
    getsize(1);
    dfs(1, 0);
    getmin(1, tmp);
    cout<<ans<<endl;
    // system("pause");
    return 0;
}