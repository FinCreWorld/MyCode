#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    cout<<1<<" ";
    for(int i = 2; i <= n; i++){
        while(n != 1){
            if(n%i == 0){
                cout<<i<<" ";
                n = n/i;
            }
            else break;
        }
    }
    cout<<endl;
    system("pause");
    return 0;
}