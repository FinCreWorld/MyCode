#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cctype>
using namespace std;
const int maxn = 55;
int a[maxn][maxn];
int kk[4][4];
int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int main(){
    int t, n, sum = 0;
    t = read();
    for(int i = 0; i < t; ++i){
        n = read();
        sum = 0;
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                a[j][k] = read();
            }
        }
        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 3; ++k){
                kk[j][k] = read();
                sum += kk[j][k];
            }
        }
        if(kk[0][0] == sum){
            for(int j = 0; j < n; ++j){
                printf("%d", a[j][0]);
                for(int k = 1; k < n; ++k){
                    printf(" %d", a[j][k]);
                }
                printf("\n");
            }
        }else{
            for(int j = 0; j < n; ++j){
                printf("0");
                for(int k = 1; k < n; ++k){
                    printf(" 0");
                }
                printf("\n");
            }
        }
    }
    // system("pause");
    return 0;
}