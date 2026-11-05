class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        if(n > 1 && nums[0] == 0)
            return false;
        int i = 0;
        while(true){
            if( i >= n-1)
                return true; 
            if(nums[i] == 0)
                return false;
            int j = 0;
            int k = i;
            for(int j = i ; j  <= i + nums[i]; j++){
                if(j + nums[j] >=n-1)
                    return true;

                i = max(i, j + nums[j]);    
            }
         
        }
        return false;
    }
};
