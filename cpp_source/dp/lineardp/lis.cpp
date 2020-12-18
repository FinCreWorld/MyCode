/*
 * 2020.9.25 T2 106
 * jcy
 * 线性递归，最长上升子序列
 */
#include<iostream>
using namespace std;
const int maxn = 100;
const int INF = 0xfffffff;
int a[maxn], f1[maxn], f2[maxn], n;
// O(n^2) 算法
// 下一状态最优质值 = 状态比较函数（已存在最优状态，可以由先前状态得到的最优质值）
// 动态规划具有判断性继承思想
int dp1(){
    for(int i = 1; i <= n; ++i){
        f1[i] = 1;
        for(int j = 1; j < i; ++j){
            // 考察以第 i 个元素结尾的序列中的最长上升子序列
            // 如果 a[j] < a[i]，则第 i 个元素可以继承第 j 个元素的状态
            if(a[j] < a[i] && f1[i] < f1[j]+1){
                f1[i] = f1[j] + 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = max(ans, f1[i]);
    }
    return ans;
}
int dp2(){
    for(int i = 1; i <= n; ++i) f2[i] = INF;
    f2[1] = a[1];
    int len = 1;
    for(int i = 2; i <= n; ++i){
        int l = 0, r = len, mid;
        if(a[i] > f2[len]){
            f2[++len] = a[i];
        }else{
            while(l < r){
                mid = (l + r)/2;
                if(f2[mid] > a[i]) r = mid;
                else l = mid+1;
            }
            // 用于排除重复数字的影响
            if(a[i] == f2[l-1]) continue;
            f2[l] = a[i];
        }
    }
    return len;
}
int main(){
    // for(int i = 1; i <= n; ++i)
    //     cin>>a[i];
    // dp1();
    // dp2();
    for(int i = 1; i <= 10; ++i){
        srand(100);
        int rd = rand() % 100;
        for(int j = 1; j <= rd; ++j){
            a[j] = rand() % 30;
        }
        n = rd;
        if(dp1() == dp2()) cout<<"success\n"<<endl;
        else{
            cout<<dp1()<<" "<<dp2()<<endl;
            for(int j = 1; j <= rd; ++j)
                cout<<a[j]<<" ";
            cout<<endl;
            break;
        }
    }
    system("pause");
    return 0;
}