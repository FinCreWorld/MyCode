// 拉链法进行哈希存储
const int SIZE = 1000000;
const int M = 999997;
struct HashTable{
    struct Node{
        int next, key, value;
    }data[SIZE];
    int head[M], size;
    int f(int key) {return key % M;}
    int get(int key){
        for(int p = head[f(key)]; p; p = data[p].next)
            if(data[p].key == key) return data[p].value;
        return -1;
    }
    int modify(int key, int value){
        for(int p = head[f(key)]; p; p = data[p].next)
            if(data[p].key == key) return data[p].value = value;
    }
    int add(int key, int value){
        if(get(key) != -1) return -1;
        data[++size] = (Node){head[f(key)], key, value};
        head[f(key)] = size;
        return value;
    }
};