#include<iostream>
using namespace std;
const int maxn = 105;
int uset[maxn];
int setrank[maxn]; // 记录每个集合的秩
int find(int a){
    if(uset[a] == a) return a;
    return uset[a] = find(uset[a]);
}
void unionSet(int a, int b){
    if(find(a) == find(b)) return;
    if(setrank[a] < setrank[b])
        uset[uset[a]] = uset[b];
    else{
        uset[uset[b]] = uset[a];
        if(setrank[a] == setrank[b])
            setrank[a]++;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        uset[i] = i;
    int op, a, b;
    while(cin>>op){
        switch (op)
        {
        case 1:
            cin>>a;
            cout<<find(a)<<endl;
            break;
        
        default:
            cin>>a>>b;
            unionSet(a, b);
            break;
        }
    }
}