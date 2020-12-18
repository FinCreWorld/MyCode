#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 10005;
const int maxlen = 1505;
const int b =  337;
typedef unsigned long long ull;
ull hash(char s[]){
    ull a = 0;
    int len = strlen(s);
    for(int i = 0; i < len; ++i)
        a += a*337 + s[i];
    return a;
}
int main(){
    int n;
    ull a[maxn];
    char s[maxlen];
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%s", s);
        a[i] = hash(s);
    }
    sort(a+1, a+n+1);
    int cnt = 1;
    for(int i = 1; i < n; ++i)
        if(a[i] != a[i+1]) ++cnt;
    printf("%d\n", cnt);
    system("pause");
    return 0;
}