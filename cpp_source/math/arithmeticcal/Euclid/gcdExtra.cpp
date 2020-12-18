/*
 * 扩展欧几里得算法
 * 用于求解形如 ax+by=gcd(a,b) 的方程
 * 扩展欧几里得算法得到的 x 和 y 满足
 * 是所有符合条件的 x，y 中 |x| + |y| 最小的
 * 且若有多个 |x| + |y| 相同，输出满足 x <= y
 */
using namespace std;
void gcd(int a, int b, int& d, int& x, int& y){
    if(!b) {x = 1; y = 0; d = a;}
    else {gcd(b, a%b, d, y, x); y -= x*a/b;}
}