#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, y;
    while(cin>>x>>y){
        if((x == 1 && y == 0) || (x == 0 && y == 0)){
            cout<<0<<endl;
        }else if((y < x && y > -x + 1) || (x == y && x > 0)){
            cout<<(4*x - 3)<<endl;
        }else if((y > x && y > -x) || (x == -y && y > 0)){
            cout<<(4*y - 2)<<endl;
        }else if((y < -x && y > x) || (x == y && x < 0)){
            cout<<(-4*x - 1)<<endl;
        }else if((y < x && y < -x+1) || (x == -y+1 && x > 0)){
            cout<<-4*y<<endl;
        }else {
            cout<<0<<endl;
        }
    }
    system("pause");
    return 0;
}