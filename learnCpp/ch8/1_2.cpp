#include<iostream>
using namespace std;
istream& fun(istream& in){
    int x;
    while(in>>x){
        cout<<x;
    }
    cout<<in.rdstate()<<endl;
    cout<<in.eofbit<<endl;
    cout<<in.badbit<<endl;
    cout<<in.failbit<<endl;
    cout<<in.goodbit<<endl;
    if(in.rdstate()==in.eofbit){
        cout<<"到达文件末尾\n";
    }
    in.clear();
    return in;
}
int main(){
    fun(cin);
    int a;
    cin>>a;
    cout<<a<<endl;
    system("pause");
    return 0;
}