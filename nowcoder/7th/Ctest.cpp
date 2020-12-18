#include<iostream>
#include<cmath>
using namespace std;
const double EPS = 0.00001;
int main(){
    for(int i = 1; i <= 10000; i++){
        long long a = i*(i+1)*(2*i+1)/6;
        //cout<<a<<" ";
        if(abs(sqrt(a) - (int)sqrt(a))<EPS) cout<<a<<" "<<i<<" YES\n";
        //cout<<endl;
    }
    system("pause");
}