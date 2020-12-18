#include<bits/stdc++.h>
using namespace std;
const  int  maxn = 1e5+1;
int  arr[maxn];
vector<int> num;

int t, n;
int firstnum, secondnum, res;

int main () {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        res = 0;
        for (int i=1; i<=n; ++i) scanf("%d",&arr[i]);
        sort(arr+1, arr+1+n);
        int nozero=1;
        while(arr[nozero]==0) ++nozero;

        secondnum = arr[nozero] ;
        arr[2] = arr[nozero+1];
        for (int i=3; i<=nozero+1; ++i) arr[i] = 0;

        num.clear();
        for(int i = n; i >= 2; --i) num.push_back(arr[i]);
        int len = num.size();
        for(int i = 0; i < len; ++i)
            num[i] *= secondnum;
        for(int i = 0; i < len; ++i)
            if(i == len-1 && num[i] >= 10){
                num.push_back(num[i]/10);
                num[i] %= 10;
            }
            else{
                num[i+1] += num[i]/10;
                num[i] %= 10;
            }
        len = num.size();
        for(int i = len-1; i >= 0; --i)
            printf("%d", num[i]);
        printf("\n");
        
        memset(arr,0,sizeof arr);

    }
    return 0;

}