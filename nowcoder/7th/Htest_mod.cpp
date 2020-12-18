// 本测试程序用于打表，找到 n/i 取整的规律
#include<iostream>
using namespace std;
int main(){
    long long n;
    //freopen("output.txt", "w", stdout);
    cin>>n;
    for(long long i = 1; i <= n; i = n/(n/i) + 1){
        //cout<<i<<" "<<n/(n/i)<<endl;
    }
    system("pause");
    return 0;
}