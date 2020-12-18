#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 30;
long long ans = 1;
char s1[maxn], s2[maxn];    // 分别表示前序遍历和后序遍历字符串
void count(int l1, int r1, int l2, int r2){
    if(l1 > r1) return;
    if(s1[l1] == s2[r2]){
        ans <<= 1;
        count(l1+1, r1, l2, r2-1);
    }
    else{
        char ch = s1[l1];
        int i, len;
        for(i = l2; i <= r2; i++)
            if(ch == s2[i]) break;
        len = i - l2;
        count(l1+1, l1+len, l2, i-1);
        count(l1+len+2, r1, i+1, r2-1);
    }
}
int main(){
    cin>>s1>>s2;
    count(1, strlen(s1)-1, 0, strlen(s2)-2);
    cout<<ans<<endl;
    // system("pause");
    return 0;
}