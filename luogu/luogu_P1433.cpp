#include<iostream>
#include<cmath>
#include<cstdio>
#include<cfloat>
using namespace std;
const int maxn = 16;
const double EPS = 0.000001;
struct Point{
    double x, y;
}points[maxn];
double dis[maxn][maxn];
double getdis(Point a, Point b){
    return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}
bool vis[maxn];
double ans = DBL_MAX;
void dfs(int cnt, double sum, int n, int last){
    if(sum > ans+EPS) return;
    if(cnt == 0)
        ans = sum;
    else{
        for(int i = 1; i <= n; i++){
             if(!vis[i]){
                 vis[i] = 1;
                 dfs(cnt-1, sum+dis[last][i], n, i);
                 vis[i] = 0;
             }
        }
    }
}
int main(){
    int n, x, y;
    cin>>n;;
    for(int i = 1; i <= n; i++)
        cin>>points[i].x>>points[i].y;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dis[i][j] = getdis(points[i], points[j]);
        }
    }
    dfs(n, 0, n, 0);
    printf("%.2f\n", ans);
    //system("pause");
    return 0;
}