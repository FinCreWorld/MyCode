#include<bits/stdc++.h>
using namespace std;
const int maxn = 27;
int g[maxn][maxn];  // 用于删去重复边
int head[maxn];
typedef struct Edge{
    int to, nxt;
}Edge;
Edge edges[maxn*maxn];
int indegree[maxn];
int n, m, ans[maxn];
int topo(){
    queue<int> q;
    int flag = 0, degree[maxn], cnt = 0;
    for(int i = 0; i < n; ++i){
        degree[i] = indegree[i];
    }
    for(int i = 0; i < n; ++i){
        if(!degree[i]){
            q.push(i);
        }
    }
    int p;
    while(!q.empty()){
        if(q.size() > 1) flag = 1;
        p = q.front(); q.pop();
        ans[cnt++] = p;
        for(int k = head[p]; k; k = edges[k].nxt){
            int pp = edges[k].to;
            --degree[pp];
            if(!degree[pp]) q.push(pp);
        }
    }
    int status = 0;     // 默认既没有环，也没有稳定序列
    for(int i = 0; i < n; ++i){
        if(degree[i]){
            status = 1; // 此时有环存在
            break;
        }
    }
    if(!flag && !status && cnt == n) status = 2;   // 此时存在稳定序列
    return status;
}
int main(){
    char ch;
    int a, b, cnt = 0, flag = 0;
    cin>>n>>m;
    for(int i = 0; i < m; ++i){
        do{ch = getchar();}while(!isalpha(ch));
        a = ch - 'A';
        getchar(); ch = getchar();
        b = ch - 'A';
        ++indegree[b];
        edges[++cnt] = (Edge){b, head[a]};
        head[a] = cnt;
        int k = topo();
        if(k == 1){
            flag = 1;
            printf("Inconsistency found after %d relations.\n", i+1);
            break;
        }else if(k == 2){
            flag = 1;
            printf("Sorted sequence determined after %d relations: ", i+1);
            for(int j = 0; j < n; ++j){
                putchar(ans[j]+'A');
            }
            printf(".\n");
            break;
        }
    }
    if(!flag) printf("Sorted sequence cannot be determined.\n");
    system("pause");
    return 0;
}