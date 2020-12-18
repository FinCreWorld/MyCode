#include<iostream>
#include<set>
using namespace std;
set<int> s;
int main(){
    int n;
    // cin>>n;
    // s.insert(99);
    // s.insert(101);
    // s.insert(102);
    // set<int>::iterator it = s.lower_bound(100);
    // if(it == s.end()){
    //     cout<<"lower_bound 无法定位元素 100"<<endl;
    // }else{
    //     cout<<*it<<endl;
    // }
    srand(1);
    for(int i = 1; i <= 10; ++i)
        s.insert(rand()%100);
    set<int>::iterator it1, it2;
    for(it1 = s.begin(); it1 != s.end(); ++it1)
        cout<<*it1<<" ";
    // cout<<endl;
    // cout<<*s.lower_bound(55)<<endl;
    // cout<<*s.upper_bound(55)<<endl;
    it1 = s.begin();
    --it1;
    cout<<(it1 == s.end())<<endl;
    system("pause");
    return 0;
}