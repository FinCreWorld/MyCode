// 埃拉托斯特尼筛法，时间复杂度为 nloglogn
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 1000005;
bool is_prime[maxn];
int prime[maxn];
int Eratosthenes(int n){
    int p = 0;
    for(int i = 0; i <= n; ++i) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; ++i)
        if(is_prime[i]){
            prime[p++] = i;
            for(long long j = (long long)i*i; j <= n; j+=i)
                is_prime[j] = false;
        }
    return p;
}
int main(){
    // freopen("prime_table.txt", "w", stdout);
    int n;
    cin>>n;
    int num = Eratosthenes(n);
    cout<<"hello"<<endl;
    printf("%d 以内的质数有 %d 个：\n", n, num);
    for(int i = 0; i < num; i++)
        printf("%d ", prime[i]);
    system("pause");
    return 0;
}