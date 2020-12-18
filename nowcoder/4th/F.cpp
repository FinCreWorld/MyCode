#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, a, b, c, d;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if(a+b < c+d){
            if((a+b)*(a+b) + c*c - d*d > 2*a*(a+b))
                cout<<"AB//CD"<<endl;
            else cout<<"AB//DC"<<endl;
        }
        else{
            if((c+d)*(c+d) + a*a - b*b > 2*c*(c+d))
                cout<<"AB//DC"<<endl;
            else cout<<"AB//CD"<<endl;
        }
    }
    return 0;
}