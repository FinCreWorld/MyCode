#include<iostream>
#include<vector>
using namespace std;
vector<int> a;
int main(){
    int n, m, x;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>x;
        a.push_back(x);
    }
    while(m--){
        cin>>x;
        cout<<a[x-1]<<endl;
    }
    return 0;
}