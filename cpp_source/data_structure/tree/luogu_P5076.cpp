#include<iostream>
using namespace std;
const int maxn = 10005;
const int INF = 0x7fffffff;
struct A{
    A():l(0),r(0),size(0),num(INF){}
    int l, r, size, num;
}a[maxn];
int cnt = 0;    // 用于标记节点
void checkRank(int x);  // 在树中查询 x 的排名
void checkNum(int x);   // 查询排名为 x 的数
void getLast(int x);    // 找到 x 的前驱，前驱定义为小于 x 的最大的数
void getNext(int x);    // 找到 x 的后继，后继定义为大于 x 的最小的数
void insert(int x);     // 向集合中插入数 x
void checkRank(int x){
    int p = 1, rank = a[p].size-a[a[p].r].size;
    while(a[p].num != INF){
        if(x < a[p].num){
            p = a[p].l;
            rank -= a[p].size - a[a[p].l].size;
        }
        else if(x > a[p].num && a[p].r){
            p = a[p].r;
            rank += a[p].size - a[a[p].r].size;
        }
        else if(x > a[p].num){  // 如果当前节点右子树为空，且 p 需要向右移动，则 rank 需要加一
            p = a[p].r;
            rank++;
        }
        else break;
    }
    cout<<rank<<endl;   // 其实输出是集合中小于 x 的个数再加1
}
void checkNum(int x){
    int p = 1, rank = a[p].size-a[a[p].r].size;
    while(a[p].num != INF){
        if(x < rank){
            p = a[p].l;
            rank -= a[p].size - a[a[p].l].size;
        }
        else if(x > rank){
            p = a[p].r;
            rank += a[p].size - a[a[p].r].size;
        }
        else break;
    }
    cout<<a[p].num<<endl;   // 如果不存在该排名，则输出 0
}
void getLast(int x){
    int lastNum = -INF, p = 1;
    while(a[p].num != INF){
        if(a[p].num < x){
            lastNum = a[p].num;
            p = a[p].r;
        }
        else
            p = a[p].l;
    }
    cout<<lastNum<<endl;
}
void getNext(int x){
    int nextNum = INF, p = 1;
    while(a[p].num != INF){
        if(a[p].num <= x)
            p = a[p].r;
        else{
            nextNum = a[p].num;
            p = a[p].l;
        }
    }
    cout<<nextNum<<endl;
}
void insert(int x){
    int p = 1;
    if(!cnt) cnt = 1;
    while(a[p].num != INF){
        a[p].size++;
        if(x >= a[p].num){
            if(!a[p].r) a[p].r = ++cnt;
            p = a[p].r;
        }
        else{
            if(!a[p].l) a[p].l = ++cnt;
            p = a[p].l;
        }
    }
    a[p].num = x; a[p].size++;
}
int main(){
    int q, op, x;
    cin>>q;
    while(q--){
        cin>>op>>x;
        switch (op){
            case 1: checkRank(x); break;
            case 2: checkNum(x); break;
            case 3: getLast(x); break;
            case 4: getNext(x); break;
            default: insert(x);
        }
    }
    system("pause");
    return 0;
}