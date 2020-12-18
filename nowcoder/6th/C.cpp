#include<iostream>
using namespace std;
const int maxn = 205;
const double EPS = 0.000000001;
int a[maxn][maxn];
double b[maxn];    // 用于存储每列的最大值
int main(){
    int t, n, m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin>>a[i][j];
        for(int j = 1; j <= m; j++){
            double sum = 0, rowmax = 0;
            for(int i = 1; i <= n; i++){
                sum += a[i][j];
                if(sum /a[i][j] > rowmax+EPS){
                    rowmax = sum/a[i][j];
                }
            }
            b[j] = rowmax;
        }
        // for(int i = 1; i <= m; i++)
        //     cout<<b[i]<<" ";
        // cout<<endl;
        double ans = 0;
        for(int i = 1; i <= m; i++)
            if(b[i] > ans+EPS) ans = b[i];
        printf("%.8lf\n", ans);
    }
    // system("pause");
    return 0;
}