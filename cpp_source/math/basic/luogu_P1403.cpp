/*
 * 不知道在什么时候写的
 * 2020.9.26 T2 106
 * jcy 第二版，第一版10分，用了一个垃圾算法
 * 转换思路，使用统计思想，直接 O(n) 复杂度
 */
#include<iostream>
#include<cstdlib>
using namespace std;
const int maxn = 1e6+5;
int main(){
    int n, ans = 0;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        ans += n/i;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}