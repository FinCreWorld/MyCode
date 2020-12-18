#include<iostream>
#include<vector>
using namespace std;
const int maxn = 300005;    // 最大船只数
const int maxm = 100005;    // 最多存在国籍数
vector<int> nation[maxm];
int statis[maxm], sum;
int q[maxn], front, tail;
int main(){
    int n, k, x, t;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>t>>k;
        q[tail] = t;
        while(k--){
            cin>>x;
            nation[tail].push_back(x);
            if(!statis[x]) ++sum;
            statis[x]++;
        }
        while(t-q[front] >= 86400){
            int len = nation[front].size();
            for(int j = 0; j < len; j++){
                statis[nation[front][j]]--;
                if(!statis[nation[front][j]]) --sum;
            }
            nation[front].clear();
            front = (front + 1) % n;
        }
        tail = (tail + 1) % n;
        cout<<sum<<endl;
    }
    return 0;
}