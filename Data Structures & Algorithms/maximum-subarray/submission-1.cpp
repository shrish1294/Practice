class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n =nums.size();
        
        int ans = INT_MIN;
        int s = 0;
        for(auto a: nums){
            s += a;
            ans = max(ans, s);
            ans = max(ans, a);
            if(s < 0)
                s = 0;
        }
        return ans; 


    }
};
