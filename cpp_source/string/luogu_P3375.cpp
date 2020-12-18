/*
 * 2020.11.22 H40x
 * KMP字符串匹配 jcy
 * KMP 模板
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
int KMP(vector<int> pi, string T, string P){
    int n = T.length();
    int m = P.length();
    int q = 0;
    for(int i = 0; i < n; ++i){
        while(q > 0 && T[i] != P[q]) q = pi[q];
        if(T[i] == P[q]) ++q;
        if(q == m){
            cout<<i - m + 2<<endl;
            q = pi[q];
        }
    }
    return -1;
}
int main(){
    string a, b;
    cin>>a>>b;
    vector<int> pi = prefix_function(b);
    KMP(pi, a, b);
    int n = pi.size();
    for(int i = 1; i < n; ++i)
        cout<<pi[i]<<" ";
    system("pause");
    return 0;
}