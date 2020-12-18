/*
 * 2020.12.2 H308
 * jcy
 * 单选错题 期望的可加性
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000005;
int a[maxn];
int b[maxn];
int main(){
    int n, A, B, C;
    scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);
    for (int i = 2; i <= n; i++)
        a[i] = ((long long) a[i - 1] * A + B) % 100000001;
    for (int i = 1; i <= n; i++)
        a[i] = a[i] % C + 1;
    for(int i = 2; i <= n; ++i)
        b[i] = max(a[i], a[i - 1]);
    b[1] = max(a[1], a[n]);
    double ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += 1.0/b[i];
    printf("%.3lf\n", ans);
    system("pause");
    return 0;
}