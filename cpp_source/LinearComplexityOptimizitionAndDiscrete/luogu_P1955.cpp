/*
 * 2020.10.7 T2 106
 * jcy
 * 离散化、并差集
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int a[maxn], b[maxn], c[maxn], d[maxn];
int origin[maxn<<1];
int f[maxn<<1];
int find(int x){
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
void unionSet(int x, int y){
    if(find(x) == find(y)) return;
    f[f[x]] = f[y];
}
int read(){
    char ch=getchar();int x=0;
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x;
}
int main(){
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, cnt = 0, m, num;
    int r, s, t, cntab = 0, cntcd = 0;
    num = read();
    while(num--){
        cnt = cntab = cntcd = 0;
        n = read();
        for(int i = 1; i <= n; ++i){
            r = read();
            s = read();
            t = read();
            if(t){
                a[++cntab] = r;
                b[cntab] = s;
            }else{
                c[++cntcd] = r;
                d[cntcd] = s;
            }
            origin[++cnt] = r, origin[++cnt] = s;
        }
        sort(origin+1, origin+cnt+1);
        m = unique(origin+1, origin+cnt+1) - origin - 1;
        for(int i = 1; i <= cntab; ++i){
            a[i] = lower_bound(origin+1, origin+m+1, a[i]) - origin;
            b[i] = lower_bound(origin+1, origin+m+1, b[i]) - origin;
        }
        for(int i = 1; i <= cntcd; ++i){
            c[i] = lower_bound(origin+1, origin+m+1, c[i]) - origin;
            d[i] = lower_bound(origin+1, origin+m+1, d[i]) - origin;
        }
        for(int i = 1; i <= m; ++i) f[i] = i;
        for(int i = 1; i <= cntab; ++i){
            unionSet(a[i], b[i]);
        }
        int flag = 0;
        for(int i = 1; i <= cntcd; ++i){
            if(find(c[i]) == find(d[i])){
                flag = 1;
                break;
            }
        }
        // for(int i = 1; i <= m; ++i){
        //     cout<<i<<" "<<find(i)<<endl;
        // }
        // for(int i = 1; i <= cntab; ++i){
        //     cout<<a[i]<<" == "<<b[i]<<endl;
        // }
        // for(int i = 1; i <= cntcd; ++i){
        //     cout<<c[i]<<" != "<<d[i]<<endl;
        // }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
    
    system("pause");
    return 0;
}