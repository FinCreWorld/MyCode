#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
    int t, n, a, b;
    cin>>t;
    for(int i = 0; i < t; ++i){
        int flag = 0;
        scanf("%d", &n);
        scanf("%d", &a);
        for(int j = 1; j < n; ++j){
            scanf("%d", &b);
            if(!(a^b)) flag = 1;
            a = b;
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
    // system("pause");
    return 0;
}