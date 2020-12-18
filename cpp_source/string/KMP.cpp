/*
 * 2020.11.22 H40x
 * jcy
 * KMP 算法
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> prefix_function(string s){
    int n = (int)s.length();
    vector<int> pi(n+1);
    pi[0] = pi[1] = 0;
    for(int i = 2; i <= n; ++i){
        int j = pi[i - 1];
        while(j > 0 && s[j] != s[i-1]) j = pi[j];
        if(s[j] == s[i-1]) ++j;
        pi[i] = j;
    }
    return pi;
}
int KMP(string T, string P){
    int n = T.length();
    int m = P.length();
    int j = 0;
    vector<int> pi = prefix_function(P);
    // for(int i = 0; i < pi.size(); ++i)
    // cout<<pi[i]<<endl;
    for(int i = 0; i < n; ++i){
        while(j > 0 && T[i] != P[j]) j = pi[j];
        if(T[i] == P[j]) ++j;
        if(j == m) return i - m + 1;
    }
    return -1;
}
int main(){
    string t, p;
    cin>>t>>p;
    cout<<KMP(t, p)<<endl;
    system("pause");
    return 0;
}