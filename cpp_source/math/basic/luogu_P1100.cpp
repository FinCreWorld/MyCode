/*
 * 2020.9.12
 * 洛谷 高低位运算
 * 移位运算
 */
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
    unsigned int x;
    scanf("%ud", &x);
    printf("%u\n", ((x&0x0000ffff)<<16)|((x&0xffff0000)>>16));
    system("pause");
    return 0;
}