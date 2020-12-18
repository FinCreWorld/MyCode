/*
 * 2020.10.18 H F4
 * jcy
 * 二分+求最大区间和
 * 一个下午之血的教训，%llf 用来读取 long double
 * %lf 用来读取 double
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 1e5 + 5;
double sum[maxn];
int q[maxn];
double a[maxn];
int s, t, n, len;
double g, h, EPS = 1e-5;
bool check(double x){
    int l, r;
    l = r = 1;
    for(int i = 1; i <= n; ++i){
        sum[i] = sum[i-1] + a[i] - x;
    }
    q[l] = 1;
    if(sum[s] > -EPS) return true;
    for(int i = 1; i <= n - s; ++i){
        while(l <= r && i - q[l] >= len) ++l;
        while(l <= r && sum[i] <= sum[q[r]]) --r;
        q[++r] = i;
        if(sum[s + i] - sum[q[l]] > -EPS) return true;
    }
    return false;
}
int main(){
    scanf("%d", &n);
    scanf("%d %d", &s, &t);
    len = t - s + 1;
    sum[0] = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%lf", &a[i]);
    }
    g = -10000; h = 10000;
    while(h - g > EPS){
        double mid = (g + h)/2;
        if(check(mid))
            g = mid;
        else h = mid;
    }
    printf("%.3lf\n", h);
    // cout<<sizeof(long double)<<endl;
    // cout<<sizeof(double)<<endl;
    system("pause");
    return 0;
}