#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string s = "123,456";
    string s1;
    stringstream ss(s);
    // ss>>s1>>s1;
    // // cin>>s1>>",">>s1;
    // cout<<s1<<endl;
    // system("pause");
    while(getline(ss, s1, ',')){
        cout<<s1<<endl;
    }
    system("pause");
    return 0;
}