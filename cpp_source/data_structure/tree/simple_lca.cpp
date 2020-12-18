#include<iostream>
using namespace std;
const int maxn = 10000;
int n;
int fa[maxn];   // 只用于存储父亲所在的节点
int deep[maxn]; // 用于记录每个节点的深度
void getdeep(void){
    for(int i = 1; i <= n; i++){
        int p = i;
        while(fa[p]){
            ++deep[i];
            p = fa[p];
        }
    }
}
int lca(int a, int b){
    while(a != b){
        if(deep[a] < deep[b])
            a = fa[a];
        else if(deep[a] > deep[b])
            b = fa[b];
        else{
            a = fa[a];
            b = fa[b];
        }
    }
    return a;
}
int main(){
    int a, b;
    cin>>n;
    for(int i = 1; i < n; i++){
        cin>>a>>b;
        fa[a] = b;  // a 的双亲结点为 b
    }
    int q;
    cin>>q; // 查询次数
    while(q--){
        cin>>a>>b; 
        cout<<lca(a, b)<<endl;
    }
}