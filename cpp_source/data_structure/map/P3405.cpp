#include<string>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<map>
using namespace std;
const int maxn = 200005;
typedef pair<string, string> pr;
map<pr, int> mp;
pr cities;
int main(){
    std::ios::sync_with_stdio(false);
    string s1, s2;
    map<pr, int>::iterator it;
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>s1>>s2;
        cities = (pr){s1.substr(0, 2), s2};
        if(cities.first == cities.second) continue;
        it = mp.find(cities);
        if(it == mp.end()) mp[cities] = 1;
        else ++(it->second);
    }
    int ans = 0;
    pr p;
    for(it = mp.begin(); it != mp.end(); ++it){
        p = pr(it->first.second, it->first.first);
        if(mp.find(p) != mp.end()){
            ans += mp[p]*(it->second);
        }
    }
    cout<<ans/2<<endl;
    system("pause");
    return 0;
}