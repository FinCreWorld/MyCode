#include<iostream>
#include<cmath>
#include<set>
using namespace std;
set<int> s;
int main(){
    int n, x, xx;
    long long ans = 0;
    set<int>::iterator p, q;
    s.clear();
    cin>>n;
    cin>>xx;
    s.insert(xx);
    for(int i = 1; i < n; i++){
        cin>>x;
        p = s.lower_bound(x);
        if(p == s.begin())
            ans += *p - x;
        else if(p == s.end())
            ans += x - *(--p);
        else{
            q = p;
            --p;
            ans += min(*q - x, x - *p);
        }
        s.insert(x);
    }
    cout<<ans + xx<<endl;
    system("pause");
    return 0;
}