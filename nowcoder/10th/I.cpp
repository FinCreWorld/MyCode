#include<iostream>
using namespace std;
int  t, n;

int  main () {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for (int i=1; i<n; ++i){
            for(int j=i+1; j<=n; ++j) printf("%d %d\n",i, j);
        }
    }
    return 0;
}