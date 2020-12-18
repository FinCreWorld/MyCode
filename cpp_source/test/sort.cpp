#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    int a[] = {3, 4, 35, 7, 23, 56,7,2,0};
    sort(a, a+sizeof(a)/sizeof(int), cmp);
    for(int i = 0; i < sizeof(a)/sizeof(int); ++i){
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("%c", 48);
    system("pause");
    return 0;
}