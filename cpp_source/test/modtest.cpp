#include<iostream>
using namespace std;
int main(){
    int a, b;
    // 当 a < 0, b < 0 时，其结果为负
    // 当 a > 0, b < 0 时，其结果为正
    // 当 a < 0, b > 0 时，其结果为负
    while(cin>>a>>b){
        cout<<a%b<<endl;
    }
    return 0;
}