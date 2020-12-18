#include <bits/stdc++.h>
using namespace std;
int main(){
    // string s[8] = {"½ù²©º­","ºØÁæÖ¥","ÌÆÕ°Ñã","Ô¬ĞÀÓï","ÁÖÎÄê»"};
    // int a[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    // int cnt = 4;
    // srand(time(NULL));
    // cout<<s[rand()%5]<<endl;
    // // while(cnt){
    // //     int x = rand()%8;
    // //     if(!a[x]){
    // //         cout<<s[x]<<endl;
    // //         a[x] = 1;
    // //         --cnt;
    // //     }
    // // }
    int a[34];
    memset(a, 0, sizeof(a));
    a[2] = a[5] = a[6] = a[14] = a[17] = a[19] = a[25] = a[8] = a[27] = 1;
    int cnt = 5;
    srand(time(NULL));
    while(cnt){
        int x = rand()%34;
        if(!a[x]){
            cout<<"1901102"<<(x+1)/10<<(x+1)%10<<endl;
            --cnt;
            a[x] = 1;
        }
    }
    system("pause");
    return 0;
}