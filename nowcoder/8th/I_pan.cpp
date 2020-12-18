#include<bits/stdc++.h>
#include<algorithm>
using  namespace std;
const  int  maxn  =  100001;
map <int,int>  m;
map <pair<int,int>,int> arr; 
int main () {
    int  t, a, b, n, q, tmp;
    scanf("%d",&t);
    for (int i=1; i<=t; ++i){
        m.clear();
        arr.clear();
        printf("Case #%d: ",i);
        scanf("%d",&n);
        q = n;
        for (int j =1; j<=n; ++j){
            scanf("%d%d", &a, &b);
            if(a<b){
                a ^= b;
                b ^= a;
                a ^= b;
            }
            if(arr.count(std::make_pair(a,b)))--q;
            else {
                arr[std::make_pair(a,b)] = 1;
                m[a] =1;
                m[b] =1;
            }
        }
        // cout<<m.size()<<" "<<q<<endl;
        printf("%d\n",min((int)m.size(),q));
    }
    return 0;
}