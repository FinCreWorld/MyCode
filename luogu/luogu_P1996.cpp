#include<iostream>
using namespace std;
const int maxn = 105;
bool vis[maxn];
int main(){
    int n, m, cnt = 0, cur = 0, k = 1;
    cin>>n>>m;
    while(cnt < n){
        if(!vis[cur] && k < m){
            ++k;
        }
        else if(!vis[cur] && k == m){
            cout<<cur+1<<" ";
            k = 1;
            vis[cur] = 1;
            ++cnt;
        }
        cur = (cur+1)%n;
    }
    cout<<endl;
    return 0;
}