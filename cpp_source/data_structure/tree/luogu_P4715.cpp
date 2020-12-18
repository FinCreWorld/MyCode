#include<iostream>
#include<cmath>
using namespace std;
const int maxn = (1<<8)+5;
int a[maxn], b[maxn];
int main(){
    int n;
    cin>>n;
    n = (int)pow(2, n);
    for(int i = 2*n-1; i > n-1; --i){
        cin>>b[2*n-i];
        a[i] = 2*n - i;
    }
    for(int i = n-1; i >= 1; --i){
        if(b[a[2*i]] > b[a[2*i+1]])
            a[i] = a[2*i];
        else
            a[i] = a[2*i+1];
    }
    if(b[a[2]] < b[a[3]])
        cout<<a[2]<<endl;
    else cout<<a[3]<<endl;
    system("pause");
    return 0;
}