#include<iostream>
#include<cmath>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> PAIR;
const int maxn = 105;
int l[maxn], r[maxn], width[maxn], n, rt[maxn], flag[maxn];
queue<PAIR> q;
int getdeep(int p){
    if(!p) return 0;
    else return max(getdeep(l[p]), getdeep(r[p]))+1;
}
int getwidth(int p){
    q.push(PAIR(p, 1));
    while(!q.empty()){
        int point = q.front().first;
        int height = q.front().second;
        q.pop();
        width[height]++;
        if(l[point]) q.push(PAIR(l[point], height+1));
        if(r[point]) q.push(PAIR(r[point], height+1));
    }
    int b = 0;
    for(int i = 1; i <= n; i++)
        b = max(b, width[i]);
    return b;
}
void getroot(int p){
    if(l[p]){
        rt[l[p]] = p;
        getroot(l[p]);
    }
    if(r[p]){
        rt[r[p]] = p;
        getroot(r[p]);
    }
}
int getdis(int a, int b){
    getroot(1);
    int cnt = 1;
    int p = a;
    while(p){
        flag[p] = cnt;
        cnt++;
        p = rt[p];
    }
    p = b;
    int h = 0;
    while(!flag[p]){
        ++h;
        p = rt[p];
    }
    return (flag[p]-1)*2+h;
}
int main(){
    cin>>n;
    int a, b;
    for(int i = 1; i < n; i++){
        cin>>a>>b;
        if(l[a]) r[a] = b;
        else l[a] = b;
    }
    cin>>a>>b;
    cout<<getdeep(1)<<endl;
    cout<<getwidth(1)<<endl;
    cout<<getdis(a, b)<<endl;
    // system("pause");
    return 0;
}