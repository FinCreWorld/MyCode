#include<iostream>
using namespace std;
const int maxn = 10005;
int setrank[maxn], uset[maxn];
int find(int x){
    if(uset[x] == x) return x;
    return uset[x] = find(uset[x]);
}
void setunion(int x, int y){
    if(find(x) == find(y)) return;
    if(setrank[x] < setrank[y]){
        uset[uset[x]] = uset[y];
    }
    else{
        uset[uset[y]] = uset[x];
        if(setrank[x] == setrank[y])
            setrank[x]++;
    }
}
int main(){
    int n, m, z, x, y;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        uset[i] = i;
    while(m--){
        cin>>z>>x>>y;
        if(z == 1)
            setunion(x, y);
        else if(find(x) == find(y))
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
    // system("pause");
    return 0;
}