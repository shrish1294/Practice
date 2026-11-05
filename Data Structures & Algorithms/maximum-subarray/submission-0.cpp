class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int ans  = INT_MIN;
        for(auto a: nums){
            ans = max(ans, a);
            sum+=a;
            ans = max(ans, sum);
            if(sum<=0)
                sum = (a > 0)?a: 0;
        }
        
        return ans;

    }
};
