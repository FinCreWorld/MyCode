#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn = 1E9+2;
const int maxm = 50847540;
int *pri, sum;  // 记录找到的素数
int cnt = 0;
bool *vis;
int read(){
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
void init(long long n, int k){
    int last = 0;
    sum = 0;
    for(int i = 2; i <= n; ++i){
        if(!vis[i]){
            pri[cnt++] = i;
            sum = last + i;
            sum %= k;
            last = sum;
        }else{
            sum = last;
        }
        for(int j = 0; j < cnt; ++j){
            if(1ll * pri[j] * i > n) break;
            vis[pri[j] * i] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}
int main(){
    pri = (int*)calloc(1, sizeof(int)*maxm);
    vis = (bool*)calloc(1, sizeof(bool)*maxn);
    long long t, n, k, ans = 0;
    t=read();
    for(int i = 0; i < t; ++i){
        n=read();k=read();
        memset(vis, 0, sizeof(vis));
        init(n+1, k);
        ans = (((n+4)*(n-1)/2)%k) + sum - 2;
        ans %= k;
        printf("%d\n", ans);
    }
    return 0;
}
