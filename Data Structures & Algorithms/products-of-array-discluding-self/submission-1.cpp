class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int len = nums.size();
        vector<int>right_prod(len + 1, 1); 
        for(int i = len - 1; i >= 0; i--){
            right_prod[i] = nums[i]*right_prod[i + 1];
        }

        vector<int>ans;
        int left_prod = 1;
        for(int i = 0; i < len; i++){
            int pr = left_prod * right_prod[i+1];
            ans.push_back(pr);
            left_prod*=nums[i];
        }

        return ans;


    }
};
