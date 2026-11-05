class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int>left(n, 1);
        vector<int>ryt(n, 1);
        int pr = 1;
        for(int i = 1 ; i < n; i++){
            left[i] = left[i-1]*nums[i-1];
        }
        for(int i = n-2; i>=0; i--){
            ryt[i] = ryt[i+1]*nums[i+1];
        }

        vector<int>ans(n, 0);
        for(int i = 0; i < n; i++){
            if(i==0)
                ans[i] = ryt[i];
            else if(i==n-1)
                ans[i] = left[i];
            else
                ans[i] = left[i]*ryt[i];
        }
        return ans; 

    }
};
