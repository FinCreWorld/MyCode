#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
set<int> s;
int main(){
    int n, op, l;
    set<int>::iterator it1,it2;
    cin>>n;
    while(n--){ // 真是糟糕的代码
        scanf("%d %d", &op, &l);
        if(op == 1){
            if(s.find(l) == s.end())
                s.insert(l);
            else printf("Already Exist\n");
        }else{
            if(s.empty()) printf("Empty\n");
            else{
                it1 = s.lower_bound(l); // 返回第一个大于等于 val 的元素
                it2 = it1--;
                if(it2 == s.end()) printf("%d\n", *it1), s.erase(it1);
                else if(it1 == s.end()) printf("%d\n", *it2), s.erase(it2);
                else if(abs(*it1 - l) > abs(*it2 - l)) printf("%d\n", *it2), s.erase(it2);
                else printf("%d\n", *it1), s.erase(it1);
            }
        }
    }
    system("pause");
    return 0;
}