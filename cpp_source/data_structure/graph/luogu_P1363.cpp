#include<bits/stdc++.h>
using namespace std;
const int maxn = 1502;
const int maxm = 1502;
int n, m, startX, startY;
int g[maxn][maxm][3];
typedef struct d{
    int x, y;
}D;
D d[4] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
bool dfs(int x, int y, int lx, int ly){
    bool flag = false;
    if(g[x][y][0]==1 && (g[x][y][1]!=lx || g[x][y][2]!=ly)){
        flag = true;
    }else if(g[x][y][0]==0){
        g[x][y][0] = 1;
        g[x][y][1] = lx;
        g[x][y][2] = ly;
        for(int i = 0; i < 4; ++i){
            int xx = (x + d[i].x + n)%n;
            int yy = (y + d[i].y + m)%m;
            flag = dfs(xx, yy, lx+d[i].x, ly+d[i].y);
            if(flag) break;
        }
    }
    return flag;
}
int main(){
    int startX, startY;
    char ch;
    while(cin>>n>>m){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin>>ch;
                if(ch=='.' || ch=='S') g[i][j][0] = 0;
                else g[i][j][0] = -1;
                if(ch == 'S'){
                    startX = i;
                    startY = j;
                }
            }
        }
        if(dfs(startX, startY, startX, startY)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}