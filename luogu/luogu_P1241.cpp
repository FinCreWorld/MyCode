#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
stack<char> s1, s2;
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    string str;
    int len;
    cin>>str;
    len = str.length();
    for(int i = len-1; i >= 0; --i){
        switch (str[i])
        {
        case '(':
            if(!s1.empty() && s1.top() == ')')
                s1.pop();
            else
                s2.push(')');
            break;
        
        case '[':
            if(!s1.empty() && s1.top() == ']')
                s1.pop();
            else
                s2.push(']');
            break;
        default:
            s1.push(str[i]);
            break;
        }
        s2.push(str[i]);
    }
    while(!s1.empty()){
        if(s1.top() == ')')
            s2.push('(');
        else
            s2.push('[');
        s1.pop();
    }
    while(!s2.empty()){
        cout<<s2.top();
        s2.pop();
    }
    cout<<endl;
    return 0;
}