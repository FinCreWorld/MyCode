/* 2020.9.19 T2 106
 * jcy 编码
 * 组合数的灵活应用
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int maxn = 7;
const int letter = 26;
typedef long long LL;
LL c(LL n, LL m){
    if(!m) return 1;
    LL num = 1;
    for(LL i = n; i > n-m; --i){
        num *= i;
    }
    for(LL i = m; i > 0; --i){
        num /= i;
    }
    return num;
}
int main(){
    char str[maxn];
    LL ans = 0;
    int len;
    int flag = 0;
    scanf("%s", str);
    len = strlen(str);
    for(int i = 1; i < len; ++i){
        ans += c(letter, i);
        if(str[i] <= str[i-1]) flag = 1;
    }
    if(!flag){
        int last = 0;
        for(int i = 0; i < len; ++i){
            for(int j = last+1; j <= str[i]-'a'; ++j){
                ans += c(letter-j, len-i-1);
            }
            last = str[i]-'a'+1;
        }
        cout<<ans+1<<endl;
    }else{
        cout<<0<<endl;
    }
    system("pause");
    return 0;
}