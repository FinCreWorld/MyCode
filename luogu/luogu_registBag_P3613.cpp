#include<iostream>
#include<vector>
#include<utility>
using namespace std;
const int maxn = 100005;
typedef pair<int, int> PAIR;
vector<PAIR> a[maxn];
int main(){
    int n, q, b, c, d, e;
    cin>>n>>q;
    while(q--){
        cin>>b;
        if(b == 1){
            cin>>b>>c>>d;
            a[b].push_back(PAIR(c, d));
        }
        else{
            cin>>c>>d;
            int len = a[c].size();
            for(int i = 0; i < len; i++){
                if(a[c][i].first == d && a[c][i].second)
                    cout<<a[c][i].second<<endl;
            }
        }
    }
    return 0;
}