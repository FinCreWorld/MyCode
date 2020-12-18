#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;
const int maxgroup = 26;
const int maxm = 500000;
stack<string> path;
vector<string> words[maxgroup];
struct Edge{
    string word;
    int v, nxt, vis;
}edges[maxm];
int head[maxgroup], cnt = 0;
int n;
int degree[maxgroup][2];    // 用于表示点的出度和入读
bool cmp(string &a, string &b){
    return a > b;
}
void input(){
    cin>>n;
    string word;
    for(int i = 0; i < n; ++i){
        cin>>word;
        words[word[0]-'a'].push_back(word);
    }
    for(int i = 0; i < maxgroup; ++i){
        sort(words[i].begin(), words[i].end(), cmp);
    }
    int u, v;
    for(int i = 0; i < maxgroup; ++i){
        u = i;
        for(int j = 0; j < words[i].size(); ++j){
            v = *(words[i][j].end()-1) - 'a';
            ++degree[u][0]; ++degree[v][1];
            edges[++cnt] = (Edge){words[i][j], v, head[u], 0};
            head[u] = cnt;
        }
    }
}
void test(){
    for(int i = 0; i < maxgroup; ++i){
        for(int p = head[i]; p; p = edges[p].nxt){
            cout<<edges[p].word<<" ";
        }
        cout<<endl;
    }
}
void dfs(int u){
    for(int p = head[u]; p; p = edges[p].nxt){
        if(!edges[p].vis){
            edges[p].vis = 1;
            dfs(edges[p].v);
            path.push(edges[p].word);
        }
    }
}
int main(){
    input();
    int flag = -1;
    // 找到起点 flag
    for(int i = 0; i < maxgroup; ++i){
        // degree[i][0] 表示出读，degree[i][1] 表示入度
        if(degree[i][0] == degree[i][1]+1){
            flag = i;
            break;
        }
    }
    if(flag == -1){ // 如果找不到起点，说明此时存在欧拉回路，只需找到字典序最小的单词即可
        for(int i = 0; i < maxgroup; ++i){
            if(words[i].size()){
                dfs(i);
                break;
            }
        }
    }
    else dfs(flag); // 从起点开始 dfs
    if(path.size() == n){
        cout<<path.top();
        path.pop();
        while(!path.empty()){
            cout<<"."<<path.top();
            path.pop();
        }
    }
    else{
        cout<<"***";
    }
    cout<<endl;
    system("pause");
    return 0;
}