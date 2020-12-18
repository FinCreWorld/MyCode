/*
 * 2020.10.5 T2 106
 * jcy
 * 滑动窗口、单调队列
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int n, k, a[maxn];
int q[maxn], rt, lt;
int main(){
    n = read(), k = read();
    for(int i = 1; i <= n; ++i)
        a[i] = read();
    
    // 输出滑动窗口后的最小值
    rt = lt = 1;
    q[lt] = 1;
    for(int i = 2; i < k; ++i){
        while(lt <= rt && a[q[rt]] >= a[i]) --rt;
        q[++rt] = i;
    }
    for(int i = k; i <= n; ++i){
        if(i - q[lt] >= k) ++lt;
        while(lt <= rt && a[q[rt]] >= a[i]) --rt;
        q[++rt] = i;
        printf("%d ", a[q[lt]]);
    }
    printf("\n");

    // 输出华东窗口后的最大值
    rt = lt = 1;
    q[lt] = 1;
    for(int i = 2; i < k; ++i){
        while(lt <= rt && a[q[rt]] <= a[i]) --rt;
        q[++rt] = i;
    }
    for(int i = k; i <= n; ++i){
        if(i - q[lt] >= k) ++lt;
        while(lt <= rt && a[q[rt]] <= a[i]) --rt;
        q[++rt] = i;
        printf("%d ", a[q[lt]]);
    }
    printf("\n");
    system("pause");
    return 0;
}