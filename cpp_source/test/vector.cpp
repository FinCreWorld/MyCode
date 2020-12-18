#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> s;
    s[0] = 99;
    s[1] = 98;
    cout<<s.size()<<endl;
    for(int i = 0; i < s.size(); ++i)
        cout<<s[i]<<endl;
    return 0;
}