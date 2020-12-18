#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<utility>
using namespace std;
const int maxn = 1505;
const int M1 = 999983;
const int M2 = 1000003;
const int N = 701;
typedef pair<int, int> PAIR;
set<PAIR> s;
PAIR my_hash(char s[]){
    int len = strlen(s);
    PAIR p;
    p.first = p.second = 0;
    for(int i = 0; i < len; ++i){
        p.first = (p.first*N + s[i]) % M1;
        p.second = (p.second*N + s[i]) % M2;
    }
    return p;
}
int main(){
    int n, cnt = 0;
    PAIR p;
    char str[maxn];
    scanf("%d", &n);
    while(n--){
        scanf("%s", str);
        p = my_hash(str);
        if(s.find(p) == s.end()){
            s.insert(p);
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    system("pause");
    return 0;
}