class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        

        int l = 1, r = 1e9;
        int ans = INT_MAX;
        while(l <=r){

            int m = (l+r)/2;
            long long cnt = 0;
            for(auto a: piles){
                cnt  = cnt + (a+m-1)/ m;
            }
            if(cnt > h)
                l = m + 1;
            else{
                ans = min(ans, m);
                r = m - 1;
            }
        }
        return ans; 

    }
};
