#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 10005;
vector<int> v;
int main(){
    int n, m, t;
    int a[maxn], b[maxn];
    cin>>t;
    while(t--){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int cnt = 0, sum = 0;
        cin>>n>>m;
        if(n < m) swap(n, m);
        while(m){
            a[++cnt] = m;
            b[cnt] = n/m;
            sum += m*b[cnt];
            n %= m;
            swap(n, m);
        }
        cout<<sum<<endl;
        for(int i = 1; i <= cnt; i++)
            for(int j = 1; j <= b[i]; j++)
                for(int k = 1; k <= a[i]; k++)
                    cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}