#include<iostream>
using namespace std;
int main(){
    cout<<"hi!"<<endl;
    cout<<"hi!"<<ends;
    cout<<"hi!"<<flush;
    cin.tie(&cout); // 将 cin 关联到 cout，实际上本来就是关联到 cout 的
    ostream *old_tie = cin.tie(nullptr);    // 得到 cin 关联的输出流，并取消 cin 与输出流的关联
    cin.tie(&cerr);
    cin.tie(old_tie);
    cerr<<"hello"<<endl;
    string str;
    while(getline(cin, str)){
        if(str.size() > 10)
            cout<<str<<endl;
    }
    system("pause");
    return 0;
}