#include <queue>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;
int len;
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>, int> mp;
        vector<int> tmp;
        for(int i = 0; i < price.size(); ++i) tmp.push_back(0);
        mp[tmp] = 0;
        return shopping(price, special, needs, mp);
    }
    int shopping(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, map<vector<int>, int>& mp){
        int minPrice = 0x7fffffff;
        if(mp.count(needs)) return mp[price];
        for(int i = 0; i < special.size(); ++i){
            vector<int> tmpVct;
            bool flag = true;
            for(int j = 0; j < needs.size(); ++j){
                if(needs[j] - special[i][j] < 0){
                    flag = false;
                    break;
                }else{
                    tmpVct.push_back(needs[j] - special[i][j]);
                }
            }
            if(flag)
                minPrice = min(minPrice, shopping(price, special, tmpVct, mp) + *special[i].end());
        }
        return mp[needs] = minPrice;
    }
};
int main(){
    vector<int> price;
    price.push_back(2);
    price.push_back(3);
    price.push_back(4);

    vector<vector <int> > special;
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(4);
    special.push_back(tmp);

    tmp.clear();
    tmp.push_back(2);
    tmp.push_back(2);
    tmp.push_back(1);
    tmp.push_back(9);
    special.push_back(tmp);

    vector<int> needs;
    needs.push_back(1);
    needs.push_back(2);
    needs.push_back(1);

    Solution s;
    cout<<s.shoppingOffers(price, special, needs);
    system("pause");
    return 0;
}