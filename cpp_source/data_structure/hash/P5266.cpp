#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<utility>
using namespace std;
const int maxn = 22;
const int M1 = 100003;
const int M2 = 100019;
const int B = 331;
typedef pair<int, int> PAIR;
map<PAIR, int> mp;
int cnt = 0;
PAIR hh(char s[]){
    PAIR p; p.first = p.second = 0;
    for(int i = 0; i < strlen(s); ++i){
        p.first = (p.first * B + s[i]) % M1;
        p.second = (p.second * B + s[i]) % M2;
    }
    return p;
}
map<PAIR, int>::iterator get(char s[]){
    return mp.find(hh(s));
}
void find(char s[]){
    map<PAIR, int>::iterator it = get(s);
    if(it == mp.end())
        printf("Not found\n");
    else
        printf("%d\n", it->second);
}
void add(char s[], int score){
    map<PAIR, int>::iterator it = get(s);
    if(it == mp.end()) ++cnt;
    mp[hh(s)] = score;
    printf("OK\n");
}
void del(char s[]){
    map<PAIR, int>::iterator it = get(s);
    if(it == mp.end())
        printf("Not found\n");
    else{
        --cnt;
        mp.erase(it);
        printf("Deleted successfully\n");
    }
}
int main(){
    int n, op, score;
    char name[maxn];
    scanf("%d", &n);
    while(n--){
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            scanf("%s %d", name, &score);
            add(name, score);
            break;
        case 2:
            scanf("%s", name);
            find(name);
            break;
        case 3:
            scanf("%s", name);
            del(name);
            break;
        default:
            printf("%d\n", cnt);
            break;
        }
    }
    system("pause");
    return 0;
}