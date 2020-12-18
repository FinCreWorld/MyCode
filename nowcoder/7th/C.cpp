#include<iostream>
#include<cstdio>
using namespace std;
long long read(){
    long long x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f = -1;
        else ch = getchar();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + ch^48;
        ch = getchar();
    }
    return f*x;
}
int main(){
    long long a;
    int t;
    cin>>t;
    while(t--){
        a = read();
        if(a == 1)
            printf("Fake news!\n");
        else
            printf("Nobody knows it better than me!\n");
    }
    system("pause");
    return 0;
}