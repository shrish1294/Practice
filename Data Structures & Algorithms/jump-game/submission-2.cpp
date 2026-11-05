class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int cnt = 0;
        int stp = nums[0];
        int prev = 0; 
        int next = nums[0];
        while(prev < next && next < n){

            int k = next;
            while(k > prev){
                stp = max(stp, k + nums[k]);
                 k--;
            }
            if(stp >= n-1)
                return true;
            prev = next;
            next = stp; 
        }
        return (stp >=n-1);


        
    }
};
