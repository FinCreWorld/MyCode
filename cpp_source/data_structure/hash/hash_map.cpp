#include<cstring>
const int SZ = 999997;
struct hash_map{
    struct data{
        long long key;
        int value, nex;
    };
    data e[SZ<<1];
    int h[SZ], cnt;
    int hash(long long u){return u % SZ;}
    int& operator[](long long u){
        int hu = hash(u);
        for(int p = hu; p; p = e[p].nex)
            if(e[p].key == u) return e[p].value;
        return e[++cnt] = (data){u, -1, h[hu]}, h[hu] = cnt, e[cnt].value;
    }
    hash_map(){
        cnt = 0;
        memset(h, 0, sizeof(h));
    }
};