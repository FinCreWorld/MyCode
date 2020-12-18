#include<bits/stdc++.h>
using namespace std;
int main(){
    bitset<10> bs("10010");
    cout<<bs<<endl;
    cout<<bs.count()<<endl;
    for(int i = 0; i < bs.size(); ++i)
        cout<<bs[i]<<" ";
    cout<<endl;
    system("pause");
    return 0;
}