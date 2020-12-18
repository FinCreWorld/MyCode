/*
 * 2020.10.4 T2 106
 * jcy
 */
#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int maxn = 2e5;
typedef long long ll;
template <typename T>void read(T &x){
    x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
}
typedef struct Factor{
    int factor;
    int index;
}Factor;
Factor mFactor[maxn], sFactor[maxn];
int getFactor(Factor* factor, int x){
    int cnt = 0;
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0){
            factor[cnt++].factor = i;
            factor[cnt-1].index = 0;
        }
        while(x % i == 0){
            ++factor[cnt-1].index;
            x /= i;
        }
    }
    if(x > 1) {
        factor[cnt++].factor = x;
        factor[cnt-1].index = 1;
    }
    return cnt;
}
// int gcd(int x, int y){
//     return y ? gcd(y, x%y) : x;
// }
// int lcm(int x, int y){
//     return x/gcd(x, y)*y;
// }
int main(){
    int n, m1, m2, s, mNum, sNum;
    int minNum = INF, ans = -1;
    read(n);
    read(m1), read(m2);
    mNum = getFactor(mFactor, m1);
    for(int i = 0; i < mNum; ++i)
        mFactor[i].index *= m2;
    // for(int i = 0; i < mNum; ++i){
    //     cout<<mFactor[i].factor<<" "<<mFactor[i].index<<endl;
    // }
    for(int i = 1; i <= n; ++i){
        read(s);
        sNum = getFactor(sFactor, s);
        // for(int j = 0; j < sNum; ++j){
        //     cout<<sFactor[j].factor<<" "<<sFactor[j].index<<endl;
        // }
        int tmp = 0, p1 = 0, p2 = 0, cnt = 0;
        if(sNum < mNum) continue;
        while(p1 < mNum && p2 < sNum){
            if(p1 > p2){
                break;
            }
            if(mFactor[p1].factor < sFactor[p2].factor)
                ++p1;
            else if(mFactor[p1].factor > sFactor[p2].factor)
                ++p2;
            else{
                cout<<mFactor[p1].factor<<" "<<mFactor[p1].index<<" ";
                cout<<sFactor[p2].factor<<" "<<sFactor[p2].index<<endl;
                tmp = max(tmp, (mFactor[p1].index+sFactor[p2].index-1)/sFactor[p2].index);
                ++p1, ++p2;
                ++cnt;
            }
        }
        if(cnt < mNum) continue;
        if(tmp < minNum){
            minNum = tmp;
            ans = i;
        }
    }
    if(minNum == INF) cout<<"-1"<<endl;
    else cout<<minNum<<endl;
    system("pause");
    return 0;
}