#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int read(){
    int x=0, f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int main(){
    unsigned long x;
    int y = 0;
    // x = read();
    // y = read();
    scanf("%lu %d", &x, &y);
    cout<<x<<" "<<y<<endl;
    // cout<<sizeof(int)<<endl;
    // cout<<sizeof(long)<<endl;
    system("pause");
    return 0;
}