/*
 * 2020.12.2 T2 30X
 * jcy
 * OSU! 一道以及难以理解的题，我tmd看了题解看了3h+
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
double a[maxn], b[maxn], c[maxn], p[maxn], ans = 0;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%lf", &p[i]);
    p[n+1] = 0;
    a[0] = b[0] = c[0] = 0;
    for(int i = 1; i <= n; ++i){
        a[i] = (a[i-1] + 1) * p[i];
        b[i] = (b[i-1] + 2*a[i-1] + 1) * p[i];
        c[i] = (c[i-1] + 3*b[i-1] + 3*a[i-1] + 1) * p[i];
        ans += c[i] * (1 - p[i+1]);
    }
    printf("%.1llf\n", ans);
    system("pause");
    return 0;
}