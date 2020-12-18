#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<utility>
#include<set>
using namespace std;
typedef pair<string, int> PAIR1;
typedef pair<string, string> PAIR2;
const int maxn = 7;
queue<PAIR1> q;
set<string> sset;
PAIR2 s[maxn];
int main(){
    string str, str1, str2, dest;
    int cnt = 0, num = 0, flag = 0;
    cin>>str>>dest; q.push(PAIR1(str, num));
    while(cin>>str1>>str2){
        s[++cnt] = PAIR2(str1, str2);
    }
    sset.clear();
    while(!q.empty()){
        str = q.front().first;
        num = q.front().second;
        string ss;
        q.pop();
        if(num > 10){
            break;
        }
        if(str.compare(dest) == 0){
            flag = 1;
            break;
        }
        for(int i = 1; i <= cnt; i++){
            int pos = str.find(s[i].first, 0);
            //cout<<str<<" "<<s[i].first<<" "<<pos<<endl;
            while(pos != str.npos){
                ss = str;
                ss.replace(pos, s[i].first.length(), s[i].second);
                if(sset.find(ss) == sset.end()){
                    q.push(PAIR1(ss, num+1));
                    sset.insert(ss);
                }
                pos = str.find(s[i].first, pos+1);
                // cout<<"hello\n";
            }
        }
    }
    if(flag) cout<<num<<endl;
    else cout<<"NO ANSWER!\n";
    //system("pause");
    return 0;
}