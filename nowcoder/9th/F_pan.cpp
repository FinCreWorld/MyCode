#include<bits/stdc++.h>
using  namespace  std;

const int maxn = 1e6+1;
const int maxsum = 1e6+1e6+1;
int  n, m;

struct data{
    int val;
    int belong;
}arr[maxsum];

int  groupHave[maxsum];

int  arrLen=1;

int  res = INT_MAX;

inline bool cmp(data& u, data&v){

    return u.val < v.val;
}

int  main () {
    scanf("%d%d", &n,&m);

    int everyGroupLen=0;

    for (int i=1; i<=n; ++i) {
        scanf("%d", &everyGroupLen);

        for (int j=1; j<=everyGroupLen; ++j ){
            scanf("%d",&(arr[arrLen].val));
            arr[arrLen].belong = i;
            arrLen ++;
        }
    }

    sort(arr+1,arr+arrLen, cmp);

    int  left=1,right = 0, nowGroupNum=0;
    //groupHave[arr[right].belong] ++ ;
    while(right < arrLen) {
            if(nowGroupNum < m){
                ++ right;
                if(++groupHave[arr[right].belong] == 1) ++nowGroupNum ;
            }
            else if(nowGroupNum == m){
                if(arr[right].val - arr[left].val < res ) res = arr[right].val - arr[left].val;
                if(--groupHave[arr[left].belong] ==0) nowGroupNum --;
                ++left;
            }
        }

    printf("%d\n", res);
    return 0;
}