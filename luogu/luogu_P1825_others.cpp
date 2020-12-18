#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
int xx,yy,q,p,n,m;
int fx[4]={0,0,-1,1},
    fy[4]={1,-1,0,0};
char a[5005][5005];
bool flag[5005][5005];
struct node
{
    int x,y,k;
};
queue<node> que;
node do_it(int xxx,int yyy,int kk)
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==a[xxx][yyy]&&(i!=xxx||j!=yyy))
            	return (node){i,j,kk};
    return (node){0,0,0};
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
        	cin>>a[i][j];
            if(a[i][j]=='@')
                xx=i,yy=j;
        }
    
    node o;
    o.x=xx,o.y=yy,o.k=0;
    flag[xx][yy]=true;
    int xxx,yyy;
    que.push(o);
    while(!que.empty())
    {
        o=que.front();
        cout<<o.x<<" "<<o.y<<endl;
        que.pop();
        if(a[o.x][o.y]=='=')
        {
            printf("%d\n",o.k);
            system("pause");
            return 0;
        }
        if(a[o.x][o.y]>='A'&&a[o.x][o.y]<='Z')
        	o=do_it(o.x,o.y,o.k);
        for(int i=0;i<4;++i)
        {
            xxx=fx[i]+o.x;
            yyy=fy[i]+o.y;
            if(!xxx||!yyy||xxx>n||yyy>m||flag[xxx][yyy]||a[xxx][yyy]=='#')
                continue;
            flag[xxx][yyy]=true,que.push((node){xxx,yyy,o.k+1});
        }
    }
    printf("-1");
    return 0;
}