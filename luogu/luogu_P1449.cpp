#include<iostream>
using namespace std;
const int maxn = 1005;
int s[maxn];
int main(){
    char ch;
    int top = 1;
    while(ch = getchar()){
        if(ch == '@'){
            cout<<s[1]<<endl;
            break;
        }
        else if(isdigit(ch)){
            int x = 0;
            do{
                x = (x<<1) + (x<<3) + (ch^48);
                ch = getchar();
            }while(isdigit(ch));
            s[top++] = x;
        }
        else{
            switch(ch){
                case '-': s[top-2] -= s[top-1];--top;break;
                case '+': s[top-2] += s[top-1];--top;break;
                case '*': s[top-2] *= s[top-1];--top;break;
                case '/': s[top-2] /= s[top-1];--top;
            }
        }
    }
    return 0;
}