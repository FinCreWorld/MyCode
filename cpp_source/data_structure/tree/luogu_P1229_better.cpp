#include<iostream>
using namespace std;
int main(){
    string s1, s2;
    int ans = 1;
    cin>>s1>>s2;
    for(int i = 0; i < s1.length()-1; i++)
        for(int j = 1; j < s2.length(); j++)
            if(s1[i] == s2[j] && s1[i+1] == s2[j-1])
                ans <<= 1;
    cout<<ans<<endl;
    return 0;
}