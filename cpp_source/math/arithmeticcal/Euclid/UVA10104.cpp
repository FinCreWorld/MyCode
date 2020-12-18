/*
 * 2020.10.19 T2 106
 * jcy
 * 扩展欧几里得算法
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
void exteuclide(int a, int b, int& d, int&x, int& y){
    if(!b){d = a; x = 1; y = 0;}
    else{exteuclide(b, a%b, d, y, x); y -= a/b*x;}
}
void euclid(int a, int b){
    int x, y, d;
    exteuclide(a, b, d, x, y);
    printf("%d %d %d\n", x, y, d);
}
int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) == 2)
        euclid(a, b);
    system("pause");
    return 0;
}
/*
 * 使用该方法求解的 x 满足 |x| + |y| 最小
 * 且 x < y
 */