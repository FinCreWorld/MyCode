#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 105;
int d[maxn];
int maxd = 0;
int n;
int main(){
    int s;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>d[i];
        maxd = max(maxd, d[i]);
    }
    for(int i = 1; i <= n; i++){
        s = (int)ceil(50*((double)d[i]/maxd));
        putchar('+');
        for(int i = 0; i < s; i++) putchar('-');
        putchar('+'); putchar('\n');
        putchar('|');
        for(int i = 1; i <= s; i++){
            if(i != 50) putchar(' ');
            else putchar('*');
        }
        putchar('|');
        printf("%d\n", d[i]);
        putchar('+');
        for(int i = 0; i < s; i++) putchar('-');
        putchar('+'); if(i != n) putchar('\n');
    }
    system("pause");
    return 0;
}