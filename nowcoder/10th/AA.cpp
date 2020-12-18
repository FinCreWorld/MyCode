#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int t, p;
    cin>>t;
    while(t--){
        scanf("%d", &p);
        switch (p)
        {
        case 2:
            printf("1\n");
            break;
        
        case 3:
            printf("1 2\n");
            break;
        case 4:
            printf("1 3 2\n");
            break;
        case 5:
            printf("1 2 4 3\n");
            break;
        default:
            printf("-1\n");
            break;
        }
    }
    return 0;
}