#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}
int main(){
    int a, b;
    while(cin>>a>>b){
        cout<<gcd(a, b)<<endl;
    }
    system("pause");
    return 0;
}