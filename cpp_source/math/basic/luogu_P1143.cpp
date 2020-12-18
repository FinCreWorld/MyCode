/*
  知识点:   进制转换
  做题时间: 2020.8.20
  题源:     洛谷 P1143
  遇到问题：getchar() 读取换行有错误，最好 string 一下子全部读入
*/

#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<iostream>
const int maxn = 100;
using namespace std;
int main(){
    int n, m, tmp = 0, k = 0;
    string s;
    char ans[maxn];
    cin>>n>>s>>m;
    for(int i = 0; i < s.length(); ++i){
        if(isalpha(s[i])){
            tmp = tmp*n + s[i] - 'A' + 10;
        }else{
            tmp = tmp*n + s[i] - '0';
        }
    }
    while(tmp){
        ans[++k] = tmp % m;
        tmp /= m;
    }
    for(int i = k; i >= 1; --i){
        if(ans[i] < 10) printf("%d", ans[i]);
        else printf("%c", ans[i]-10+'A');
    }
    printf("\n");
    system("pause");
    return 0;
}