/*
 * 2020.10.7 T2 106
 * jcy
 * 前缀和
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+3;
const double EPS = 1e-5;
int a[maxn], minScore[maxn], sumScore[maxn];
double score[maxn];
double maxScore = 0;
int n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    minScore[n] = a[n];
    sumScore[n] = a[n];
    for(int i = n - 1; i >= 2; --i){
        sumScore[i] = a[i] + sumScore[i+1];
        minScore[i] = min(a[i], minScore[i+1]);
        score[i] = ((double)sumScore[i] - minScore[i])/(n - i);
        maxScore = max(maxScore, score[i]);
    }
    for(int i = 2; i <= n - 1; ++i){
        if(abs(score[i] - maxScore) < EPS){
            printf("%d\n", i - 1);
        }
    }
    system("pause");
    return 0;
}