#include<iostream>
using namespace std;
const int maxn = 300005;
struct A{
    int n, t;
}a[maxn];
int front, tail;
int nation[maxn];
int main(){
    int n, ans = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        int t, k, x;
        cin>>t>>k;
        while(k--){
            cin>>x;
            if(!nation[x]) ++ans;
            nation[x]++;
            a[tail] = (A){x, t};
            tail = (tail+1) % maxn;
        }
        while(a[front].t + 86400 <= t){
            nation[a[front].n]--;
            if(!nation[a[front].n]) --ans;
            front = (front+1) % maxn;
        }
        cout<<ans<<endl;
    }
    return 0;
}