/*
 * 2020.9.12 实验室
 * 洛谷 进制转换
 * 负数求余
 */
#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;
char trans(int x){
    char ch;
    if(x < 10) return x + '0';
    return x - 10 + 'A';
}
int main(){
    int a, b, c;
    stack<char> s;
    cin>>a>>b;
    cout<<a<<"=";
    while(a){
        if(a<0 && a%b) c = a%b - b;
        else c = a%b;
        // cout<<a<<"%"<<b<<"="<<c<<endl;
        a = (a-c)/b;
        s.push(trans(c));
    }
    while(!s.empty()) {cout<<s.top();s.pop();}
    cout<<"(base"<<b<<")\n";
    system("pause");
    return 0;
}