class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

           vector<int>v(amount + 1, INT_MAX);
           v[0] = 0;
           sort(coins.begin(), coins.end());
           
           for(int i = 1; i <=amount ; i ++){
                int mini = INT_MAX;
                for(auto a: coins){
                    if(a > i)
                        break;
                    int x = v[i - a];
                    if(x == INT_MAX)
                        continue;
                    mini = min(mini, 1 + x);
                }
                v[i] = mini;
           }
           if(v[amount] == INT_MAX)
            return -1;
           return v[amount];
    }
};
