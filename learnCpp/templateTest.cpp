#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

template <typename T>
inline T read(T &x){
    T f=1;char ch=getchar();x=0;
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}

typedef long long ll;

int main(){
    int a1, a2;
    read(a1);read(a2);
    cout<<a1<<" "<<a2<<endl;
    
    ll b1, b2;
    read(b1);read(b2);
    cout<<b1<<" "<<b2<<endl;
    
    system("pause");
    return 0;
}