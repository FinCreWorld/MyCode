#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
const int maxn = 305;
char maze[maxn][maxn];
bool vis[maxn][maxn];   // 用于标记已访问过的点
struct point{
    point():x(0),y(0){}
    point(int x, int y){
        this->x = x;
        this->y = y;
    }
    int x, y;
    bool operator==(point b){
        return x == b.x && y == b.y;
    }
};
typedef pair<point, int> PAIR;
int n, m;
point dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
point slide1[26], slide2[26];
queue<PAIR> q;
point transform(char ch, point p){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(maze[i][j] == ch && (p.x != i || p.y != j))
                return point(i, j);
        }
    }
    return point(0, 0);
}
int main(){
    point start, end;
    cin>>n>>m;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin>>maze[i][j];
            if(maze[i][j] == '@') start = (point){i, j};
            if(maze[i][j] == '=') end = (point){i, j};
            // if(isalpha(maze[i][j]))
            //     if(slide1[maze[i][j]-'A'].x)
            //         slide2[maze[i][j]-'A'] = (point){i, j};
            //     else
            //         slide1[maze[i][j]-'A'] = (point){i, j};
        }
    for(int i = 0; i <= n+1; i++)
        maze[i][0] = maze[i][m+1] = '#';
    for(int j = 0; j <= m+1; j++)
        maze[0][j] = maze[n+1][j] = '#';
    q.push(PAIR(start, 0));
    vis[start.x][start.y] = true;
    while(!q.empty()){
        point p = q.front().first;
        
        int num = q.front().second;
        q.pop();
        if(p == end){
            cout<<num<<endl;
            break;
        }
        char ch = maze[p.x][p.y];
        if(ch >= 'A' && ch <= 'Z'){
            p = transform(ch, p);
            if(p.x == 0) continue;
        }
        for(int i = 0; i < 4; i++){
            point np = (point){p.x+dir[i].x, p.y+dir[i].y};
            if(!vis[np.x][np.y] && maze[np.x][np.y]!='#'){
                vis[np.x][np.y] = true;
                q.push(PAIR(np, num+1));
            }
        }
    }
    return 0;
}