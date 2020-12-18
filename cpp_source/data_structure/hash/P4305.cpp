#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn = 50021;
typedef long long LL;
struct hash_map{
    struct node{
        LL key;
        int nxt;
    }data[maxn];
    int head[maxn], cnt = 0;
    int hash(LL key){key %= maxn; return key>=0 ? key : key + maxn;}
    bool get(LL key){
        int hs = hash(key);
        for(int p = head[hs]; p; p = data[p].nxt)
            if(data[p].key == key) return false;
        data[++cnt] = (node){key, head[hs]};
        head[hs] = cnt;
        return true;
    }
    hash_map(){
        cnt = 0;
        memset(head, 0, sizeof(head));
    }
};
int main(){
    freopen("output.txt", "w", stdout);
    int t, n, x;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        hash_map hm;
        while(n--){
            scanf("%d", &x);
            if(hm.get(x)) printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}