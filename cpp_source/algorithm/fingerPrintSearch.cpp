#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int compute(string s){
    return atoi(s.c_str());
}
int search(string t, string p){
    int fp = compute(p);
    int pLen = p.length();
    int tLen = t.length();
    int f = compute(t.substr(0, pLen));
    for(int i = 0; i < tLen - pLen; ++i){
        if(fp == f) return i;
        f = (f - (t[i] - '0')*(int)(pow(10, pLen - 1)))*10 + (t[i + pLen] - '0');
    }
    return -1;
}
int main(){
    string t, p;
    cin>>t>>p;
    cout<<search(t, p)<<endl;
    system("pause");
    return 0;
}