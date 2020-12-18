#include<bits/stdc++.h>
using namespace std;
const int M = 100003;
int head[M], cnt = 0;
struct Node{
    int key, value, next;
}dt[M];
int hh(int key){
    return key % M;
}
void find(int key){
    int hs = hh(key);
    for(int p = head[hs]; p; p = dt[p].next)
        if(dt[p].key == key){
            printf("%d\n", dt[p].value);
            return;
        }
    printf("0\n");
}
int main(){
    int n, hs, key;
    memset(head, 0, sizeof(head));
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &key);
        hs = hh(key);
        dt[i] = (Node){key, i, head[hs]};
        head[hs] = i;
    }
    int q, x;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &x);
        find(x);
    }  
    system("pause");
    return 0;
}